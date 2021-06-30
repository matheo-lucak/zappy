/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** App
*/

#pragma once

#include "Core.hpp"
#include <string_view>

class App : public indie::Application
{
    public:
        App(indie::ApplicationCmdLineArgs args);
        ~App() noexcept override;

        static constexpr std::string_view BUILD_SCENES_PATH = "../src/zappy/BuildScenes.json";
};
