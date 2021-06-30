/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** handlers
*/

#include <iostream>
#include <map>

#include "net/Response.hpp"
#include "Map.hpp"
#include "resources/Inventory.hpp"

void r_msz_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 2) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 2)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t pos_x = std::stoi(*it);
    size_t pos_y = std::stoi(*(++it));
}

void r_bct_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 9) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 9)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t pos_x = std::stoi(*it);
    size_t pos_y = std::stoi(*(++it));
    size_t linemate1_qt = std::stoi(*(++it));
    size_t deraumere2_qt = std::stoi(*(++it));
    size_t sibur3_qt = std::stoi(*(++it));
    size_t mendiane4_qt = std::stoi(*(++it));
    size_t phiras5_qt = std::stoi(*(++it));
    size_t trystame6_qt = std::stoi(*(++it));
}

void r_tna_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    std::string team_name = *(response.m_args.begin());
}

void r_ppo_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 4) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 4)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    size_t pos_x = std::stoi(*(++it));
    size_t pos_y = std::stoi(*(++it));
    Drone::Direction drct = static_cast<Drone::Direction>(std::stoi(*(++it)));
}

void r_pst_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 8) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 8)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    size_t incantation_lvl = std::stoi(*(++it));
    size_t linemate1_qt = std::stoi(*(++it));
    size_t deraumere2_qt = std::stoi(*(++it));
    size_t sibur3_qt = std::stoi(*(++it));
    size_t mendiane4_qt = std::stoi(*(++it));
    size_t phiras5_qt = std::stoi(*(++it));
    size_t trystame6_qt = std::stoi(*(++it));
}

void r_pnw_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 6) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 6)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    size_t pos_x = std::stoi(*(++it));
    size_t pos_y = std::stoi(*(++it));
    Drone::Direction drct = static_cast<Drone::Direction>(std::stoi(*(++it)));
    size_t incantation_lvl = std::stoi(*(++it));
    std::string team_name = *(++it);
}

void r_pex_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    size_t player_id = std::stoi(*(response.m_args.begin()));
}

void r_pbc_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 2) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 2)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    std::string msg = *(++it);
}

void r_pic_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 10) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 10)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t pos_x = std::stoi(*it);
    size_t pos_y = std::stoi(*(++it));
    size_t incantation_lvl = std::stoi(*(++it));
    size_t player_id = std::stoi(*(++it));
    size_t linemate1_qt = std::stoi(*(++it));
    size_t deraumere2_qt = std::stoi(*(++it));
    size_t sibur3_qt = std::stoi(*(++it));
    size_t mendiane4_qt = std::stoi(*(++it));
    size_t phiras5_qt = std::stoi(*(++it));
    size_t trystame6_qt = std::stoi(*(++it));
}

void r_pie_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 3) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 3)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t pos_x = std::stoi(*it);
    size_t pos_y = std::stoi(*(++it));
    size_t incantation_res = std::stoi(*(++it));
}

void r_enw_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 4) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 4)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t egg_id = std::stoi(*it);
    size_t player_id = std::stoi(*(++it));
    int pos_x = std::stoi(*(++it));
    int pos_y = std::stoi(*(++it));
    map.newEgg(egg_id, pos_x, pos_y);
}

void r_eht_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    size_t egg_id = std::stoi(*(response.m_args.begin()));
    map.newDroneFromEgg(egg_id);
}

void r_ebo_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 6) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 6)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    int pos_x = std::stoi(*(++it));
    int pos_y = std::stoi(*(++it));
    Drone::Direction drct = static_cast<Drone::Direction>(std::stoi(*(++it)));
    int incantation_lvl = std::stoi(*(++it));
    std::string team_name = *(++it);
}

void r_edi_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    size_t egg_id = std::stoi(*(response.m_args.begin()));
}

void r_pdr_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 2) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 2)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    Resource resource_id = static_cast<Resource>(std::stoi(*(++it)));
    ecs::GameObject *drone = map.getDrone(player_id);
}

void r_pgt_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 2) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 2)" << std::endl;
        return;
    }
    std::list<std::string>::iterator it = response.m_args.begin();
    size_t player_id = std::stoi(*it);
    Resource resource_id = static_cast<Resource>(std::stoi(*(++it)));
    ecs::GameObject *drone = map.getDrone(player_id);
}

void r_pdi_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    size_t player_id = std::stoi(*(response.m_args.begin()));
    map.killDrone(player_id);
}

void r_sgt_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    size_t time_unit = std::stoi(*(response.m_args.begin()));
}

void r_seg_handler(Map &map, Response &response)
{
    if (response.m_args.size() != 1) {
        std::cerr << "Response Handler: invalide request (wrong number of argument(s): expected 1)" << std::endl;
        return;
    }
    std::string winning_team = *(response.m_args.begin());
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
