/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "SceneManagerInternal.hpp"

void zappy::SceneManager::LoadBuildScenes(std::string_view path)
{
    zappy::SceneManagerInternal::LoadBuildScenes(path);
}

void zappy::SceneManager::LoadScene(unsigned int buildIdx)
{
    zappy::SceneManagerInternal::AskLoadScene(buildIdx);
}

int zappy::SceneManager::getActiveSceneBuildIdx() noexcept
{
    return zappy::SceneManagerInternal::getActiveSceneBuildIdx();
}

void zappy::SceneManager::QuitApplication() noexcept
{
    zappy::SceneManagerInternal::QuitApplication();
}

void zappy::SceneManager::ToggleMusicMute(bool value) noexcept
{
    zappy::SceneManagerInternal::ToggleMusicMute(value);
}