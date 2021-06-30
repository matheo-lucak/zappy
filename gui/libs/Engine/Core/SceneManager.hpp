/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** SceneManager
*/

#pragma once

#include <string_view>

namespace zappy::SceneManager
{
    void LoadBuildScenes(std::string_view path);

    void LoadScene(unsigned int buildIdx);
    int getActiveSceneBuildIdx() noexcept;

    void QuitApplication() noexcept;

    void ToggleMusicMute(bool value) noexcept;
} // namespace zappy::SceneManager