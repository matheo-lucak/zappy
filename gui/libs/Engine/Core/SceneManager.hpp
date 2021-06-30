/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** SceneManager
*/

#pragma once

#include <string_view>

namespace indie::SceneManager
{
    void LoadBuildScenes(std::string_view path);

    void LoadScene(unsigned int buildIdx);
    int getActiveSceneBuildIdx() noexcept;

    void QuitApplication() noexcept;

    void ToggleMusicMute(bool value) noexcept;
} // namespace indie::SceneManager