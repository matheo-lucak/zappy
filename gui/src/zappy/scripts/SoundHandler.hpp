/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** SoundHandler
*/

#pragma once

#include <array>

#include "ECS/Script.hpp"
#include "ECS/GameObject.hpp"

class SoundHandler : public ecs::Script {
    public:
        SoundHandler(ecs::GameObject &gameObject) noexcept;
        ~SoundHandler() noexcept override = default;

        std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

        void Start() noexcept override;

    protected:
    private:
        std::array<ecs::GameObject *, 4> m_icons;

        void SwitchIcon(int clickedID) noexcept;
};

DECLARE_AS_SCRIPT(SoundHandler)
