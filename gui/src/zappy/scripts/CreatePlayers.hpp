/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** CreatePlayers
*/

#pragma once

#include "ECS/Script.hpp"


class CreatePlayers : public ecs::Script {
    public:
        CreatePlayers(ecs::GameObject &gameObject) noexcept;
        ~CreatePlayers() = default;

        std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

        void Start() noexcept override;
        void Update() noexcept override;

    private:
    private:
};

DECLARE_AS_SCRIPT(CreatePlayers)
