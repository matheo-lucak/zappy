/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** handlers
*/

#include <iostream>
#include <map>
#include <string.h>

#include "net/Response.hpp"
#include "Map.hpp"
#include "resources/Inventory.hpp"
#include "Tile.hpp"

// map size
void r_msz_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 2) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 2)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t pos_x = std::stoi(*it);
    size_t pos_y = std::stoi(*(++it));
}

// content of a tile
void r_bct_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 9) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 9)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t pos_x = std::stoi(*it);
    size_t pos_y = std::stoi(*(++it));
    int linemate1_qt = std::stoi(*(++it));
    int deraumere2_qt = std::stoi(*(++it));
    int mendiane3_qt = std::stoi(*(++it));
    int sibur4_qt = std::stoi(*(++it));
    int phiras5_qt = std::stoi(*(++it));
    int thystame6_qt = std::stoi(*(++it));

    auto cell = map.m_grid.at(utils::Vector3f{pos_x, 0.0f, pos_y}).getObject();
    if (cell.has_value() == false)
        return;
    
    ecs::GameObject &obj = cell->get();
    auto &tile_script = obj.getScript<Tile>();

    tile_script.m_inventory.set_item(Resource::LINEMATE, linemate1_qt);
    tile_script.m_inventory.set_item(Resource::DERAUMERE, deraumere2_qt);
    tile_script.m_inventory.set_item(Resource::MENDIANE, mendiane3_qt);
    tile_script.m_inventory.set_item(Resource::SIBUR, sibur4_qt);
    tile_script.m_inventory.set_item(Resource::PHIRAS, phiras5_qt);
    tile_script.m_inventory.set_item(Resource::THYSTAME, thystame6_qt);
}
// name of all the teams
void r_tna_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    std::string team_name = *(response.m_args.begin());

    map.m_all_team.push_back(team_name);
}

// player’s position
void r_ppo_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 4) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 4)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    size_t pos_x = std::stoi(*(++it));
    size_t pos_y = std::stoi(*(++it));
    Drone::Direction drct = static_cast<Drone::Direction>(std::stoi(*(++it)));

    ecs::GameObject *drone = map.getDrone(player_id);
    auto &drone_script = drone->getScript<Drone>();

    drone_script.x = pos_x;
    drone_script.y = pos_y;
    drone_script.dir = drct;
}

// player’s stats
void r_pst_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 8) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 8)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    size_t incantation_lvl = std::stoi(*(++it));
    int linemate1_qt = std::stoi(*(++it));
    int deraumere2_qt = std::stoi(*(++it));
    int mendiane3_qt = std::stoi(*(++it));
    int sibur4_qt = std::stoi(*(++it));
    int phiras5_qt = std::stoi(*(++it));
    int thystame6_qt = std::stoi(*(++it));

    ecs::GameObject *drone = map.getDrone(player_id);
    auto &drone_script = drone->getScript<Drone>();

    drone_script.lvl = incantation_lvl;

    drone_script.m_inventory.set_item(Resource::LINEMATE, linemate1_qt);
    drone_script.m_inventory.set_item(Resource::DERAUMERE, deraumere2_qt);
    drone_script.m_inventory.set_item(Resource::MENDIANE, mendiane3_qt);
    drone_script.m_inventory.set_item(Resource::SIBUR, sibur4_qt);
    drone_script.m_inventory.set_item(Resource::PHIRAS, phiras5_qt);
    drone_script.m_inventory.set_item(Resource::THYSTAME, thystame6_qt);
}

// connection of a new player
void r_pnw_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 6) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 6)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    int pos_x = std::stoi(*(++it));
    int pos_y = std::stoi(*(++it));
    Drone::Direction drct = static_cast<Drone::Direction>(std::stoi(*(++it)));
    size_t incantation_lvl = std::stoi(*(++it));
    std::string team_name = *(++it);

    map.newDrone(player_id, pos_x, pos_y);

    ecs::GameObject *drone = map.getDrone(player_id);
    auto &drone_script = drone->getScript<Drone>();

    drone_script.lvl = incantation_lvl;
    drone_script.dir = drct;
    drone_script.m_team_name = team_name;
    drone_script.active - true;
    drone_script.x = pos_x;
    drone_script.y = pos_y;
}

// expulsion
void r_pex_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    size_t player_id = std::stoi(*(response.m_args.begin()));
}

// broadcast
void r_pbc_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 2) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 2)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    std::string msg = *(++it);
}

// start of an incantation
void r_pic_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 10) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 10)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t pos_x = std::stoi(*it);
    size_t pos_y = std::stoi(*(++it));
    size_t incantation_lvl = std::stoi(*(++it));
    size_t player_id = std::stoi(*(++it));
    size_t linemate1_qt = std::stoi(*(++it));
    size_t deraumere2_qt = std::stoi(*(++it));
    size_t mendiane3_qt = std::stoi(*(++it));
    size_t sibur4_qt = std::stoi(*(++it));
    size_t phiras5_qt = std::stoi(*(++it));
    size_t thystame6_qt = std::stoi(*(++it));
}

// end of an incantation
void r_pie_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 3) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 3)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t pos_x = std::stoi(*it);
    size_t pos_y = std::stoi(*(++it));
    size_t incantation_res = std::stoi(*(++it));
}

// an egg was laid by a player
void r_enw_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 4) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 4)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t egg_id = std::stoi(*it);
    size_t player_id = std::stoi(*(++it));
    int pos_x = std::stoi(*(++it));
    int pos_y = std::stoi(*(++it));
    map.newEgg(egg_id, pos_x, pos_y);
}

// egg hatching
void r_eht_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    size_t egg_id = std::stoi(*(response.m_args.begin()));

    map.newDroneFromEgg(egg_id);
}

// player connection from an egg
void r_ebo_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 6) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 6)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t egg_id = std::stoi(*it);
    int pos_x = std::stoi(*(++it));
    int pos_y = std::stoi(*(++it));
    Drone::Direction drct = static_cast<Drone::Direction>(std::stoi(*(++it)));
    int incantation_lvl = std::stoi(*(++it));
    std::string team_name = *(++it);

    map.newDroneFromEgg(egg_id);
    ecs::GameObject *drone = map.getDrone(egg_id);
    auto &drone_script = drone->getScript<Drone>();

    drone_script.dir = drct;
    drone_script.lvl = incantation_lvl;
    drone_script.m_team_name = team_name;
    drone_script.x = pos_x;
    drone_script.y = pos_y;
    drone_script.active = true;
}

// death of an hatched egg
void r_edi_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    size_t player_id = std::stoi(*(response.m_args.begin()));

    map.killDrone(player_id);
}

// resource dropping
void r_pdr_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 2) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 2)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    Resource resource_id = static_cast<Resource>(std::stoi(*(++it)));

    ecs::GameObject *drone = map.getDrone(player_id);

    map.dropResource(resource_id, drone);
}

// resource collecting
void r_pgt_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 2) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 2)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    Resource resource_id = static_cast<Resource>(std::stoi(*(++it)));

    ecs::GameObject *drone = map.getDrone(player_id);

    map.collectResource(resource_id, drone);
}

// death of a player
void r_pdi_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    size_t player_id = std::stoi(*(response.m_args.begin()));

    map.killDrone(player_id);
}

// time unit request
void r_sgt_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    int time_unit = std::stoi(*(response.m_args.begin()));

    map.m_freq = time_unit;
}

// end of game
void r_seg_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalid request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    map.winning_team = strdup((*response.m_args.begin()).c_str());
}

void response_handler(Map &map, Response &response)
{
    switch (response.m_type) {
        case (Response::RESPONSE_MSZ) : r_msz_handler(map, response); return;
        case (Response::RESPONSE_BCT) : r_bct_handler(map, response); return;
        case (Response::RESPONSE_TNA) : r_tna_handler(map, response); return;
        case (Response::RESPONSE_PPO) : r_ppo_handler(map, response); return;
        case (Response::RESPONSE_PST) : r_pst_handler(map, response); return;
        case (Response::RESPONSE_PNW) : r_pnw_handler(map, response); return;
        case (Response::RESPONSE_PEX) : r_pex_handler(map, response); return;
        case (Response::RESPONSE_PBC) : r_pbc_handler(map, response); return;
        case (Response::RESPONSE_PIC) : r_pic_handler(map, response); return;
        case (Response::RESPONSE_PIE) : r_pie_handler(map, response); return;
        case (Response::RESPONSE_ENW) : r_enw_handler(map, response); return;
        case (Response::RESPONSE_EHT) : r_eht_handler(map, response); return;
        case (Response::RESPONSE_EBO) : r_ebo_handler(map, response); return;
        case (Response::RESPONSE_EDI) : r_edi_handler(map, response); return;
        case (Response::RESPONSE_PDR) : r_pdr_handler(map, response); return;
        case (Response::RESPONSE_PGT) : r_pgt_handler(map, response); return;
        case (Response::RESPONSE_PDI) : r_pdi_handler(map, response); return;
        case (Response::RESPONSE_SGT) : r_sgt_handler(map, response); return;
        case (Response::RESPONSE_SEG) : r_seg_handler(map, response); return;
        default:
            break;
    }
    std::cerr << "Response Handler: Unkown request type" << std::endl;
}
