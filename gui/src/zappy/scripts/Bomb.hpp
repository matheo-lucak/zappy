/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Bomb
*/

#pragma once

#include <vector>
#include <optional>

#include "ECS/Script.hpp"
#include "ECS/Components/Model.hpp"
#include "Utils/Vector3.hpp"

#include "Map.hpp"
#include "Clock.hpp"

class Bomb : public ecs::Script {
    public:
        Bomb(ecs::GameObject &gameObject) noexcept;
        ~Bomb() = default;

        std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

        void Awake() noexcept override;
        void Start() noexcept override;
        void Update() noexcept override;

        float detonationTime;
        int   range;

    private:
        void Explode();
        bool ExplodeCreateChild(const ecs::GameObject &obj, utils::Vector3u coord);

    private:
        Map * m_map;
        Clock m_clock;
        ecs::Model *m_model;
        utils::Vector3f m_scaleDown;
        utils::Vector3f m_scaleUp;
        bool m_scalingUp;

    public:
        ecs::GameObject *player;
};

DECLARE_AS_SCRIPT(Bomb)
