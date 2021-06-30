/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Bomb
*/

#include <iostream>

#include "GameObject.hpp"
#include "ECS.hpp"
#include "Core.hpp"

#include "Player.hpp"
#include "Bomb.hpp"

SCRIPT_INIT(Bomb)

Bomb::Bomb(ecs::GameObject &gameObject) noexcept :
    ecs::Script{gameObject},
    detonationTime(5),
    range(2),
    m_map(nullptr),
    m_model(nullptr),
    player(nullptr)
{
}

std::unique_ptr<ecs::Script> Bomb::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<Bomb>(copyOn);
}

void Bomb::Start() noexcept
{
    std::cout << "Bomb start" << std::endl;
}

void Bomb::Awake() noexcept
{
    ecs::GameObject *map = ecs::GameObject::FindGameObjectByName("Map");

    std::cout << "Bomb Awake" << std::endl;
    if (map) {
        m_map = &map->getScript<Map>();
    }
    m_clock.reset();

    m_model = &gameObject.getComponent<ecs::Model>();
    constexpr float step = 0.10f;
    m_scaleUp   = m_model->scaling() * (1 + step);
    m_scaleDown = m_model->scaling() * (1 - step);
    m_scalingUp = true;
}

void Bomb::Update() noexcept
{
    constexpr float minSpeed = 0.4f;
    constexpr float maxSpeed = 2.0f;
    const utils::Color minColor{utils::Color::White};
    const utils::Color maxColor{utils::Color::Red};

    float speed = utils::Vector3f::lerp(minSpeed, maxSpeed, m_clock.time() / detonationTime).x;
    utils::Vector3f &target = m_scalingUp ? m_scaleUp : m_scaleDown;
     m_model->scaling().moveTowards(target, speed * indie::Time::DeltaTimeSec());
    if (m_model->scaling().distance(target) < 0.001f) {
        m_scalingUp = !m_scalingUp;
    }
    auto colors = utils::Vector3f::lerp(utils::Vector3f{minColor.r, minColor.g, minColor.g},
                                        utils::Vector3f{maxColor.r, maxColor.g, maxColor.g},
                                        m_clock.time() / detonationTime);
    m_model->color() = utils::Color{static_cast<uint8_t>(colors.x),
                                    static_cast<uint8_t>(colors.y),
                                    static_cast<uint8_t>(colors.z)};

    if (m_clock.time() > detonationTime) {
        Explode();
    }
}

void Bomb::Explode()
{
    auto &bomb_explosion_sound = gameObject.getComponent<ecs::SoundPlayer>();
    bomb_explosion_sound.play();
    if (m_map) {
        ecs::GameObject &explosion_bp = ecs::GameObject::FindPrefabByName("Explosion");
        utils::Grid3 &grid = m_map->getGrid();
        utils::Vector3u coord = grid.posToCoord(gameObject.transform().getPosition());

        std::cout << "EXPLOSION" << std::endl;

        ExplodeCreateChild(explosion_bp, utils::Vector3u{coord.x, 1 , coord.z});
        for (int i = 0; i < range; i++) {
            if (ExplodeCreateChild(explosion_bp, utils::Vector3u{coord.x - i, 1, coord.z}) == false)
                break;
        }
        for (int i = 0; i < range; i++) {
            ExplodeCreateChild(explosion_bp, utils::Vector3u{coord.x + i, 1, coord.z});
            if (ExplodeCreateChild(explosion_bp, utils::Vector3u{coord.x + i, 1, coord.z}) == false)
                break;
        }
        for (int i = 0; i < range; i++) {
            if (ExplodeCreateChild(explosion_bp, utils::Vector3u{coord.x, 1, coord.z - i}) == false)
                break;
        }
        for (int i = 0; i < range; i++) {
            if (ExplodeCreateChild(explosion_bp, utils::Vector3u{coord.x, 1, coord.z + i}) == false)
                break;
        }
    }
    ecs::GameObject::Destroy(gameObject);
}

bool Bomb::ExplodeCreateChild(const ecs::GameObject &obj, utils::Vector3u coord)
{
    utils::Grid3 &grid = m_map->getGrid();

    if (grid.isValidCoords(coord) == false)
        return false;

    auto cell = grid.at(coord).getObject();

    if (cell.has_value()) {
        ecs::GameObject &obj = cell->get();

        if (obj.getName() != "Box")
            return false;
        grid.at(coord).setObject({});
        if (player) {
            auto &player_script = player->getScript<Player>();

            player_script.increaseNbBoxDestroyed();
        }
        ecs::GameObject::Destroy(obj);
        return false;
    }

    utils::Vector3f new_pos = grid.coordToPos(coord);
    ecs::GameObject::Instantiate(obj, new_pos);
    return true;
}
