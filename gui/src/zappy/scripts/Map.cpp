/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Map
*/

#include <iostream>
#include <optional>
#include <time.h>

#include "Graphics/Camera.hpp"
#include "BoxCollider.hpp"
#include "Map.hpp"
#include "Tile.hpp"
#include "Text.hpp"

SCRIPT_INIT(Map)

Map::Map(ecs::GameObject &gameObject) noexcept : ecs::Script{gameObject},
                                                 m_grid(
                                                     gameObject.getComponent<ecs::BoxCollider>().getSize(),
                                                     gameObject.getComponent<ecs::Transform>().getPosition())
{
    m_grid.setCellSize({2});
}

void Map::create(utils::Vector3u size)
{
    //std::list<ecs::GameObject *> tiles = ecs::GameObject::FindGameObjectsByTag("Tile");
//
    //for (auto tile : tiles) {
    //    if (tile) {
    //        ecs::GameObject::Destroy(*tile);
    //    }
    //}

    const auto &tile_bp = ecs::GameObject::FindPrefabByName("Tile");

    // Tiles
    for (unsigned int z = 0; z < size.z; z++)
    {
        for (unsigned int x = 0; x < size.x; x++)
        {
            auto &cell = m_grid.at(x, 0, z);

            ecs::GameObject &tile_obj = gameObject.InstantiateChild(tile_bp);
            cell.setObject(tile_obj);

            utils::Vector3f pos = cell.getPosition();
            pos.y -= 1;
            cell.setPosition(pos);
        }
    }
    m_size = size;
    resetCameraTarget(size);
}

void Map::resetCameraTarget(utils::Vector3u size)
{
    Graphics::Camera::camera.lock(true);
    Graphics::Camera::camera.setPosition({static_cast<float>(size.x), 60.0f, static_cast<float>(size.z) + 40.0f});
    Graphics::Camera::camera.setTarget({static_cast<float>(size.x), 2.0f, static_cast<float>(size.z) + 5.0f});
}

std::unique_ptr<ecs::Script> Map::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<Map>(copyOn);
}

void Map::Awake() noexcept
{
    create(gameObject.getComponent<ecs::BoxCollider>().getSize());
    ecs::GameObject *obj = ecs::GameObject::FindGameObjectByName("NetworkManager");

    if (!obj) {
        std::cerr << "There is no Network Manager" << std::endl;
        return;
    }
    m_net_manager = &obj->getScript<NetworkManager>();
    m_net_manager->addRequest(std::move(Request::RQ_CONNECT));
    m_net_manager->addRequest(std::move(Request::RQ_MAP_SIZE));
    m_net_manager->addRequest(std::move(Request::RQ_MAP_CONTENT));
    m_net_manager->addRequest(std::move(Request::RQ_TEAM_NAMES));
    m_net_manager->addRequest(std::move(Request::RQ_TIME_UNIT_REQUEST));
}

void Map::Start() noexcept
{
    auto &text_tile_position_obj = gameObject.FindChildByName("TilePosition")->getComponent<ecs::Text>();

    text_tile_position_obj.text = "Tile on focus: (0, 0)";
}

void Map::handleCameraMovements(void)
{
    if (Graphics::Input::isKeyDown(Graphics::Keycode::LEFT))
    {
        utils::Vector3f camera_pos = Graphics::Camera::camera.getPosition();

        if (camera_pos.x > -30.0f)
            Graphics::Camera::camera.setPosition({camera_pos.x - 1.0f, camera_pos.y, camera_pos.z});
    }
    if (Graphics::Input::isKeyDown(Graphics::Keycode::RIGHT))
    {
        utils::Vector3f camera_pos = Graphics::Camera::camera.getPosition();

        if (camera_pos.x < 30.0f)
            Graphics::Camera::camera.setPosition({camera_pos.x + 1.0f, camera_pos.y, camera_pos.z});
    }
    if (Graphics::Input::isKeyDown(Graphics::Keycode::UP))
    {
        utils::Vector3f camera_pos = Graphics::Camera::camera.getPosition();

        if (camera_pos.z > 35.0f)
            Graphics::Camera::camera.setPosition({camera_pos.x, camera_pos.y, camera_pos.z - 1.0f});
    }
    if (Graphics::Input::isKeyDown(Graphics::Keycode::DOWN))
    {
        utils::Vector3f camera_pos = Graphics::Camera::camera.getPosition();

        Graphics::Camera::camera.setPosition({camera_pos.x, camera_pos.y, camera_pos.z + 1.0f});
    }
}

void Map::Update() noexcept
{
    handle_find_render_tile();
    update_render_tile_info();
    askForMapUpdate();
    handleCameraMovements();
    handleMapUpdate();
}

utils::Grid3 &Map::getGrid()
{
    return m_grid;
}

void Map::update_render_tile_info()
{
    auto cell = m_grid.at(utils::Vector3f{m_render_tile.x, 0.0f, m_render_tile.y}).getObject();

    if (cell.has_value() == false)
        return;

    ecs::GameObject &obj = cell->get();
    auto &tile_script = obj.getScript<Tile>();
    auto &text_food_obj = gameObject.FindChildByName("TileFoodAmount")->getComponent<ecs::Text>();
    auto &text_linemate_obj = gameObject.FindChildByName("TileLinemateAmount")->getComponent<ecs::Text>();
    auto &text_deraumere_obj = gameObject.FindChildByName("TileDeraumereAmount")->getComponent<ecs::Text>();
    auto &text_mendiane_obj = gameObject.FindChildByName("TileMendianeAmount")->getComponent<ecs::Text>();
    auto &text_sibur_obj = gameObject.FindChildByName("TileSiburAmount")->getComponent<ecs::Text>();
    auto &text_phiras_obj = gameObject.FindChildByName("TilePhirasAmount")->getComponent<ecs::Text>();
    auto &text_thystame_obj = gameObject.FindChildByName("TileThystameAmount")->getComponent<ecs::Text>();

    text_food_obj.text = std::string("F: ") + std::to_string(tile_script.m_inventory.get_item_quantity(Resource::FOOD));
    text_linemate_obj.text = std::string("L: ") + std::to_string(tile_script.m_inventory.get_item_quantity(Resource::LINEMATE));
    text_deraumere_obj.text = std::string("D: ") + std::to_string(tile_script.m_inventory.get_item_quantity(Resource::DERAUMERE));
    text_mendiane_obj.text = std::string("M: ") + std::to_string(tile_script.m_inventory.get_item_quantity(Resource::MENDIANE));
    text_sibur_obj.text = std::string("S: ") + std::to_string(tile_script.m_inventory.get_item_quantity(Resource::SIBUR));
    text_phiras_obj.text = std::string("P: ") + std::to_string(tile_script.m_inventory.get_item_quantity(Resource::PHIRAS));
    text_thystame_obj.text = std::string("T: ") + std::to_string(tile_script.m_inventory.get_item_quantity(Resource::THYSTAME));
}

void Map::handle_find_render_tile()
{
    if (Graphics::Mouse::isButtonPressed(Graphics::MouseButton::BUTTON_LEFT)) {
        for (unsigned int z = 0; z < m_size.z; z++) {
            for (unsigned int x = 0; x < m_size.x; x++) {
                auto cell = m_grid.at(utils::Vector3f{x, 0.0f, z}).getObject();

                if (cell.has_value() == false)
                    continue;
                
                ecs::GameObject &obj = cell->get();
                auto &tile_script = obj.getScript<Tile>();

                utils::Vector2f mouse_position = Graphics::Mouse::getPosition();
                utils::Vector2f coords = tile_script.getInventoryToWorldScreen();

                if (coords.x - 15 <= mouse_position.x && coords.x + 15 >= mouse_position.x
                    && coords.y - 15 <= mouse_position.y && coords.y + 15 >= mouse_position.y) {
                    m_render_tile = utils::Vector2f{x, z};

                    auto &text_tile_position_obj = gameObject.FindChildByName("TilePosition")->getComponent<ecs::Text>();

                    text_tile_position_obj.text = std::string("Tile on focus: (") +
                                                  std::to_string(static_cast<int>(m_render_tile.x)) +
                                                  std::string(", ") +
                                                  std::to_string(static_cast<int>(m_render_tile.y)) +
                                                  std::string(")");
                    break;
                }
            }
        }
    }
}

void Map::handleMapUpdate() noexcept
{
    if (!m_net_manager)
        return;
    if (m_net_manager->isResponseAvaible()) {
        Response r = m_net_manager->getResponse();
        response_handler(*this, r);
    }
}

void Map::askForMapUpdate() noexcept
{
    static bool first_tick = true;
    static struct timespec last_time;
    struct timespec current_time;
    long delta_time_us;
    long time_for_tick_us;

    if (first_tick) {
        timespec_get(&last_time, TIME_UTC);
        first_tick = false;
        return;
    }
    timespec_get(&current_time, TIME_UTC);
    delta_time_us = (current_time.tv_nsec - last_time.tv_nsec) / 1000;
    time_for_tick_us = (long)(1000000 / m_freq) - delta_time_us;
    time_for_tick_us = time_for_tick_us >= 0 ? time_for_tick_us : 0;
    if (time_for_tick_us <= 0) {
        last_time = current_time;
        std::cout << "Map Update" << std::endl;
        std::list<ecs::GameObject *> drones = ecs::GameObject::FindGameObjectsByTag("Drone");

        for (auto drone : drones) {
            if (!drone)
                continue;
            auto &drone_script = drone->getScript<Drone>();
            m_net_manager->addRequest(std::move(Request(Request::RQ_PLAYER_POSITION, drone_script.id)));
        }
    }
}

void Map::newDrone(size_t id, int x, int y)
{
    ecs::GameObject drone_bp = ecs::GameObject::FindPrefabByName("Drone");
    ecs::GameObject &new_drone = gameObject.InstantiateChild(drone_bp);
    auto &drone_script = new_drone.getScript<Drone>();

    drone_script.id = id;
    drone_script.x = x;
    drone_script.y = y;
}

void Map::newDroneFromEgg(size_t id)
{
    ecs::GameObject *egg = getEgg(id);

    if (!egg)
        return;
    auto &egg_script = egg->getScript<Egg>();
    ecs::GameObject drone_bp = ecs::GameObject::FindPrefabByName("Drone");
    ecs::GameObject &new_drone = gameObject.InstantiateChild(drone_bp);
    auto &drone_script = new_drone.getScript<Drone>();

    drone_script.id = egg_script.id;
    drone_script.x = egg_script.x;
    drone_script.y = egg_script.y;
    ecs::GameObject::Destroy(*egg);
}

void Map::killDrone(size_t id)
{
    ecs::GameObject *drone = getDrone(id);

    if (drone) {
        ecs::GameObject::Destroy(*drone);
    }
}

void Map::newEgg(size_t id, int x, int y)
{
    ecs::GameObject egg_bp = ecs::GameObject::FindPrefabByName("Egg");
    ecs::GameObject &new_egg = gameObject.InstantiateChild(egg_bp);
    auto &egg_script = new_egg.getScript<Egg>();

    egg_script.id = id;
    egg_script.x = x;
    egg_script.y = y;
}


void Map::collectResource(Resource rs_id, ecs::GameObject *drone)
{
    auto &drone_script = drone->getScript<Drone>();
    auto cell = m_grid.at(utils::Vector3f{drone_script.x, 0.0f, drone_script.y}).getObject();

    if (cell.has_value() == false)
        return;
    
    ecs::GameObject &obj = cell->get();
    auto &tile_script = obj.getScript<Tile>();
    
    tile_script.m_inventory.delete_item(rs_id, 1);
    drone_script.m_inventory.add_item(rs_id, 1);
}

void Map::dropResource(Resource rs_id, ecs::GameObject *drone)
{
    auto &drone_script = drone->getScript<Drone>();
    auto cell = m_grid.at(utils::Vector3f{drone_script.x, 0.0f, drone_script.y}).getObject();

    if (cell.has_value() == false)
        return;
    
    ecs::GameObject &obj = cell->get();
    auto &tile_script = obj.getScript<Tile>();
    
    tile_script.m_inventory.add_item(rs_id, 1);
    drone_script.m_inventory.delete_item(rs_id, 1);
}

ecs::GameObject *Map::getDrone(size_t id)
{
    std::list<ecs::GameObject *> drones = ecs::GameObject::FindGameObjectsByTag("Drone");

    for (auto drone : drones) {
        if (!drone)
            continue;
        auto &drone_script = drone->getScript<Drone>();
        if (drone_script.id == id) {
            return drone;
        }
    }
    return nullptr;
}

ecs::GameObject *Map::getEgg(size_t id)
{
    std::list<ecs::GameObject *> eggs = ecs::GameObject::FindGameObjectsByTag("Egg");

    for (auto egg : eggs) {
        if (!egg)
            continue;
        auto &egg_script = egg->getScript<Egg>();
        if (egg_script.id == id) {
            return egg;
        }
    }
    return nullptr;
}
