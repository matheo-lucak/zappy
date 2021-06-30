/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Tile
*/

#include "GameObject.hpp"

#include "Tile.hpp"

SCRIPT_INIT(Tile)

Tile::Tile(ecs::GameObject &gameObject) noexcept :
    ecs::Script{gameObject},
    m_inventory{}
{
}

std::unique_ptr<ecs::Script> Tile::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<Tile>(copyOn);
}

utils::Vector2f Tile::getInventoryToWorldScreen(void) const noexcept
{
    auto tileInventory_obj = gameObject.FindChildByName("TileInventory");
    utils::Vector3f position = tileInventory_obj->transform().getPosition();

    ::Vector2 pos = ::GetWorldToScreen({position.x, position.y, position.z}, Graphics::Camera::camera.m_camera);

    return utils::Vector2f{pos.x, pos.y};
}

void Tile::Awake() noexcept
{
    const auto &tileInventory_bp = ecs::GameObject::FindPrefabByName("TileInventory");
    auto &tileInventory_obj = gameObject.InstantiateChild(tileInventory_bp);

    m_tileInventory_obj = &tileInventory_obj;
    m_mineral = gameObject.FindChildByName("Mineral");
    m_food = gameObject.FindChildByName("Food");
;}

void Tile::Start() noexcept
{
    auto &tileIventory_transform = m_tileInventory_obj->transform();
    utils::Vector3f position = gameObject.transform().getPosition();

    tileIventory_transform.setPosition({position.x - 0.75f, position.y + 2.0f, position.z});
}

//check if exist
// check print mineral
// setenable

void Tile::Update() noexcept
{
    if (m_mineral || m_food)
        return;
}
