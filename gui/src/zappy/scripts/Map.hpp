/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Map
*/

#pragma once

#include "ECS/Script.hpp"
#include "Grid3.hpp"

class Map : public ecs::Script {
    public:
        Map(ecs::GameObject &gameObject) noexcept;
        ~Map() = default;

        std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

        void Start() noexcept override;
        void Update() noexcept override;

        utils::Grid3 &getGrid(void);
    private:
        void Explode() noexcept;

    private:
        utils::Grid3 m_grid;
};

DECLARE_AS_SCRIPT(Map)
