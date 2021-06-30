/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** ResultScreen
*/

#pragma once

#include <list>

#include "ECS/Script.hpp"
#include "ECS/Components/Model.hpp"
#include "Utils/Vector3.hpp"

class ResultScreen : public ecs::Script {
    public:
        ResultScreen(ecs::GameObject &gameObject) noexcept;
        ~ResultScreen() = default;

        std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

        void Awake() noexcept override;
        void Update() noexcept override;

    protected:
    private:
        static std::list<ecs::GameObject *> m_players;
        static int m_idx;

        void SetPositions() noexcept;
        void SetData() noexcept;
};

DECLARE_AS_SCRIPT(ResultScreen)
