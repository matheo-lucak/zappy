/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Explosion
*/

#pragma once

#include <vector>
#include <optional>

#include "ECS/Script.hpp"

#include "Clock.hpp"

class Explosion : public ecs::Script {
    public:
        Explosion(ecs::GameObject &gameObject, float lifeTime = 0.3) noexcept;
        ~Explosion() = default;

        void Awake() noexcept override;
        void Update() noexcept override;
        void OnTrigger(ecs::GameObject &other) noexcept override;

        std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;
    private:
        Clock   m_clock;
        float   m_lifeTime;
};

DECLARE_AS_SCRIPT(Explosion)
