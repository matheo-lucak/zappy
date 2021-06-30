/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Incantation
*/

#include "Incantation.hpp"

SCRIPT_INIT(Incantation)

Incantation::Incantation(ecs::GameObject &gameObject) noexcept : ecs::Script{gameObject}
{
}

std::unique_ptr<ecs::Script> Incantation::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<Incantation>(copyOn);
}

void Incantation::Start() noexcept
{
}

void Incantation::Update() noexcept
{
}
