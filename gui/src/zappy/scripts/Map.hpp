/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Map
*/

#pragma once

#include "ECS/Script.hpp"
#include "Grid3.hpp"

#include "net/NetworkManager.hpp"
#include "Drone.hpp"
#include "Egg.hpp"
#include "Incantation.hpp"
#include "resources/Inventory.hpp"

class Map : public ecs::Script
{
public:
    Map(ecs::GameObject &gameObject) noexcept;
    ~Map() noexcept;

    std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

    void Awake() noexcept override;
    void Start() noexcept override;
    void Update() noexcept override;

    void create(utils::Vector3u size);
    void resetCameraTarget(utils::Vector3u size);
    utils::Grid3 &getGrid(void);

    void askForMapUpdate() noexcept;
    void handleMapUpdate() noexcept;

    void newDrone(size_t id, int x, int y, Drone::Direction d);
    void newDroneFromEgg(size_t id);
    void killDrone(size_t id);
    void newEgg(size_t id, int x, int y);

    void droneUpdate(ecs::GameObject *drone);

    void collectResource(Resource rs_id, ecs::GameObject *drone);
    void dropResource(Resource rs_id, ecs::GameObject *drone);

    ecs::GameObject *getDrone(size_t id);
    ecs::GameObject *getEgg(size_t id);

    utils::Vector3f getTilePos(int x, int y);

private:
    void handleCameraMovements(void);
    void update_render_tile_info(void);
    void handle_find_render_tile(void);
    void Explode() noexcept;

public:
    NetworkManager *       m_net_manager       = nullptr;
    bool                   m_game_ready        = false;
    int                    m_freq              = 10;
    utils::Grid3           m_grid;
    utils::Vector3u        m_size;
    utils::Vector2f        m_render_tile;
    char *                 winning_team        = nullptr;
    std::list<std::string> m_all_team;
    ecs::GameObject *      m_end_game_button;
    bool                   ended               = false;
};

void response_handler(Map &map, Response &response);

DECLARE_AS_SCRIPT(Map)
