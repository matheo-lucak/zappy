/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Initializer
*/

#pragma once

#include "Clock.hpp"
#include "ECS/Script.hpp"

class Initializer : public ecs::Script {
    public:
        Initializer(ecs::GameObject &gameObject) noexcept;
        ~Initializer() noexcept override = default;

        std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

        void Start() noexcept override;
        void Update() noexcept override;

        void CreateMenu() noexcept;

    protected:
    private:
};

DECLARE_AS_SCRIPT(Initializer)
