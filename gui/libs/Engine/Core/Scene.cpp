/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Scene
*/

#include "Scene.hpp"

using namespace zappy;

Scene::Scene() noexcept
{
    isMusicMuted = false;
    objects.reserve(100);
    commissioning.reserve(5);
    colliders.reserve(100);
    buttons.reserve(10);
    musics.reserve(2);
    animators.reserve(2);
    drawable2d.reserve(10);
    drawable3d.reserve(100);
    deleting.reserve(10);
}
