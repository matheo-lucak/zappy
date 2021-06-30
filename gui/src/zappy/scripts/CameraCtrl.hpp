/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** CameraCtrl
*/

#pragma once

#include "ECS/Script.hpp"
#include "Utils/Vector3.hpp"

class CameraCtrl : public ecs::Script {
    public:
        CameraCtrl(ecs::GameObject &gameObject) noexcept;
        ~CameraCtrl() noexcept override = default;

        std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

        void Start() noexcept override;
        void Update() noexcept override;

    protected:
    private:
        float m_speed;
        utils::Vector3f m_targetPos;
        utils::Vector3f m_targetTarget;
        int m_context;
};

DECLARE_AS_SCRIPT(CameraCtrl)
