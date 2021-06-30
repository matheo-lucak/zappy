/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Map
*/

#include "BoxCollider.hpp"
#include "Map.hpp"

SCRIPT_INIT(Map)

Map::Map(ecs::GameObject &gameObject) noexcept :
    ecs::Script{gameObject},
    m_grid(
        gameObject.getComponent<ecs::BoxCollider>().getSize(),
        gameObject.getComponent<ecs::Transform>().getPosition()
    )
{
    const auto &ground_bp = ecs::GameObject::FindPrefabByName("Ground");
    const auto &wall_bp = ecs::GameObject::FindPrefabByName("Wall");
    const auto &box_bp = ecs::GameObject::FindPrefabByName("Box");

    utils::Vector3u size = gameObject.getComponent<ecs::BoxCollider>().getSize();

    m_grid.setCellSize({2});

    // Ground
    for (unsigned int z = 0; z < size.z; z++) {
        for (unsigned int x = 0; x < size.x; x++) {
            auto &cell = m_grid.at(x, 0, z);
            ecs::GameObject &wall_obj = gameObject.InstantiateChild(ground_bp);
            cell.setObject(wall_obj);

            utils::Vector3f pos = cell.getPosition();
            pos.y -= 1;
            cell.setPosition(pos);
        }
    }

    // Walls
    for (unsigned int x = 0; x < size.x; x++) {
        ecs::GameObject &wall_1 = gameObject.InstantiateChild(wall_bp);
        ecs::GameObject &wall_2 = gameObject.InstantiateChild(wall_bp);

        m_grid.at(x, 1, 0).setObject(wall_1);
        m_grid.at(x, 1, size.z - 1).setObject(wall_2);
    }
    for (unsigned int z = 0; z < size.z; z++) {
        ecs::GameObject &wall_1 = gameObject.InstantiateChild(wall_bp);
        ecs::GameObject &wall_2 = gameObject.InstantiateChild(wall_bp);

        m_grid.at(0, 1, z).setObject(wall_1);
        m_grid.at(size.x - 1, 1, z).setObject(wall_2);
    }

    // Bricks
    for (unsigned int z = 2; z < size.z - 2; z += 2) {
        for (unsigned int x = 2; x < size.x - 2; x += 2) {
            ecs::GameObject &brick_obj = gameObject.InstantiateChild(wall_bp);

            m_grid.at(x, 1, z).setObject(brick_obj);
        }
    }

    // Boxes

    constexpr int box_spawn_prob = 60;

    for (unsigned int z = 1; z < size.z - 1; z += 1) {
        int bloc_in_a_row = 0;

        for (unsigned int x = 1; x < size.x - 1; x += 1) {
            // keep always 3 blocs free at angles
            if ((z == 1 && x == 1) ||
                (z == 1 && x == 2) ||
                (z == 2 && x == 1) ||
                (z == size.z - 2 && x == size.x - 2) ||
                (z == size.z - 3 && x == size.x - 2) ||
                (z == size.z - 2 && x == size.x - 3) ||
                (z == 1  && x == size.x - 2) ||
                (z == 1  && x == size.x - 3) ||
                (z == 2  && x == size.x - 2) ||
                (z == size.z - 2  && x == 1) ||
                (z == size.z - 3  && x == 1) ||
                (z == size.z - 2  && x == 2))
                continue;
            // dont overlap walls
            if (z % 2 == 0 && x % 2 == 0)
                continue;

            if (bloc_in_a_row < 4 && rand() % 100 < box_spawn_prob + bloc_in_a_row * 10) {
                ecs::GameObject &box_obj = gameObject.InstantiateChild(box_bp);

                m_grid.at(x, 1, z).setObject(box_obj);
                bloc_in_a_row++;
            } else if (bloc_in_a_row > 0) {
                bloc_in_a_row--;
            }

        }
    }
}

std::unique_ptr<ecs::Script> Map::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<Map>(copyOn);
}

void Map::Start() noexcept
{
}

void Map::Update() noexcept
{
}

utils::Grid3 &Map::getGrid()
{
    return m_grid;
}
