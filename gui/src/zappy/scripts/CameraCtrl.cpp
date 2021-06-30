/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** CameraCtrl
*/

#include "CameraCtrl.hpp"
#include "GameObject.hpp"
#include "ECS.hpp"
#include "Core.hpp"
#include "Utils.hpp"
#include "Graphics.hpp"
#include "Initializer.hpp"

SCRIPT_INIT(CameraCtrl)

using Cmr = Graphics::Camera;

CameraCtrl::CameraCtrl(ecs::GameObject &gameObject) noexcept : ecs::Script{gameObject}
{
}

std::unique_ptr<ecs::Script> CameraCtrl::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<CameraCtrl>(copyOn);
}

void CameraCtrl::Start() noexcept
{
    Cmr::camera.lock(true);

    Cmr::camera.setPosition({ 2.0f, 2.0f, 2.0f });
    m_targetPos = { 15.0f, 15.0f, 15.0f };
    m_context = 1;
    m_speed = 4.0f;
}

void CameraCtrl::Update() noexcept
{
    if (m_context == 1) {
        Cmr::camera.setPosition(Cmr::camera.getPosition().moveTowards(m_targetPos, m_speed * indie::Time::DeltaTimeSec()));
        if (Cmr::camera.getPosition().distance(m_targetPos) < 0.001f) {
            // m_targetTarget = { 15.0f, 15.0f, -15.0f };
            m_targetTarget = { 0.0f, 15.0f, 0.0f };
            ++m_context;
            m_speed = 2.0f;
        }
    } else if (m_context == 2) {
        Cmr::camera.setTarget(Cmr::camera.getTarget().moveTowards(m_targetTarget, m_speed * indie::Time::DeltaTimeSec()));
        if (Cmr::camera.getTarget().distance(m_targetTarget) < 0.001f) {
            gameObject.getScript<Initializer>().CreateMenu();
            ++m_context;
        }
    }
}