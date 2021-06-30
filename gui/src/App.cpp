/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** App
*/

#include <iostream>
#include <iomanip>
#include <memory>

#include "App.hpp"
#include "Entrypoint.hpp"
#include "Engine.hpp"

#include "Map.hpp"
#include "Drone.hpp"
#include "Egg.hpp"
#include "net/NetworkManager.hpp"
#include "SoundHandler.hpp"
#include "Tile.hpp"

App::App(zappy::ApplicationCmdLineArgs args) : Application{args, "Zappy", App::BUILD_SCENES_PATH, 1920, 1080}
{
    std::cout << "My App prepared" << std::endl;
    ReferenceScript(Drone);
    ReferenceScript(Egg);
    ReferenceScript(Map);
    ReferenceScript(NetworkManager);
    ReferenceScript(SoundHandler);
    ReferenceScript(Tile);
}

App::~App() noexcept
{
    std::cout << "My App Ended" << std::endl;
}

std::unique_ptr<zappy::Application> CreateApplication(zappy::ApplicationCmdLineArgs args)
{
    return std::make_unique<App>(args);
}
