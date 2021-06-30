/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Egg
*/

#include "Egg.hpp"

SCRIPT_INIT(Egg)

Egg::Egg(ecs::GameObject &gameObject) noexcept : ecs::Script{gameObject}
{
}

std::unique_ptr<ecs::Script> Egg::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<Egg>(copyOn);
}

void Egg::Start() noexcept
{
}

void Egg::Update() noexcept
{
}
