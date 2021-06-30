/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "SceneManagerInternal.hpp"

void indie::SceneManager::LoadBuildScenes(std::string_view path)
{
    indie::SceneManagerInternal::LoadBuildScenes(path);
}

void indie::SceneManager::LoadScene(unsigned int buildIdx)
{
    indie::SceneManagerInternal::AskLoadScene(buildIdx);
}

int indie::SceneManager::getActiveSceneBuildIdx() noexcept
{
    return indie::SceneManagerInternal::getActiveSceneBuildIdx();
}

void indie::SceneManager::QuitApplication() noexcept
{
    indie::SceneManagerInternal::QuitApplication();
}

void indie::SceneManager::ToggleMusicMute(bool value) noexcept
{
    indie::SceneManagerInternal::ToggleMusicMute(value);
}