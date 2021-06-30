/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** App
*/

#include <iostream>
#include <iomanip>
#include <memory>

#include "App.hpp"
#include "Entrypoint.hpp"
#include "Engine.hpp"

#include "CreatePlayers.hpp"
#include "Player.hpp"
#include "Bomb.hpp"
#include "Explosion.hpp"
#include "Map.hpp"
#include "Initializer.hpp"
#include "SoundHandler.hpp"
#include "CameraCtrl.hpp"
#include "ResultScreen.hpp"

App::App(indie::ApplicationCmdLineArgs args):
    Application{args, "Zappy", App::BUILD_SCENES_PATH, 1920, 1080}
{
    std::cout << "My App prepared" << std::endl;
    ReferenceScript(CreatePlayers);
    ReferenceScript(Player);
    ReferenceScript(Bomb);
    ReferenceScript(Map);
    ReferenceScript(Explosion);
    ReferenceScript(Initializer);
    ReferenceScript(SoundHandler);
    ReferenceScript(CameraCtrl);
    ReferenceScript(ResultScreen);
}

App::~App() noexcept
{
    std::cout << "My App Ended" << std::endl;
}

std::unique_ptr<indie::Application> CreateApplication(indie::ApplicationCmdLineArgs args)
{
    return std::make_unique<App>(args);
}
