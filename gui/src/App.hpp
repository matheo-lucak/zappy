/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** App
*/

#pragma once

#include <string_view>

#include "Core.hpp"

class App : public zappy::Application
{
    public:
        App(zappy::ApplicationCmdLineArgs args);
        ~App() noexcept override;

        static constexpr std::string_view BUILD_SCENES_PATH = "../src/zappy/BuildScenes.json";
};
