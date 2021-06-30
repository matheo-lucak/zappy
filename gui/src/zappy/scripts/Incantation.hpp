/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Incantation
*/

#pragma once

#include "ECS/Script.hpp"

class Incantation : public ecs::Script
{
public:
    Incantation(ecs::GameObject &gameObject) noexcept;
    ~Incantation() = default;

    std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

    void Start() noexcept override;
    void Update() noexcept override;

    size_t id;
    size_t lvl;
    int x = 0;
    int y = 0;
};

DECLARE_AS_SCRIPT(Incantation)
