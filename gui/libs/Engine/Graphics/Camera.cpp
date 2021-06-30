/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Camera
*/

#include "Camera.hpp"

Graphics::Camera Graphics::Camera::camera{};

Graphics::Camera::Camera() noexcept : m_locked{false}
{
    m_camera = {};
    m_camera.position = (::Vector3){ 5.0f, 10.0f, 10.0f };
    m_camera.target = (::Vector3){ 0.0f, 0.0f, 0.0f };
    m_camera.up = (::Vector3){ 0.0f, 1.0f, 0.0f };
    m_camera.fovy = 45.0f;
    m_camera.projection = CAMERA_PERSPECTIVE;
}

void Graphics::Camera::setPosition(const utils::Vector3f &pos) noexcept
{
    m_camera.position = (::Vector3){pos.x, pos.y, pos.z};
}

utils::Vector3f Graphics::Camera::getPosition() const noexcept
{
    return utils::Vector3f{m_camera.position.x, m_camera.position.y, m_camera.position.z};
}

void Graphics::Camera::setTarget(const utils::Vector3f &target) noexcept
{
    m_camera.target = (::Vector3){target.x, target.y, target.z};
}

utils::Vector3f Graphics::Camera::getTarget() const noexcept
{
    return utils::Vector3f{m_camera.target.x, m_camera.target.y, m_camera.target.z};
}

void Graphics::Camera::lock(bool value) noexcept
{
    m_locked = value;
}

bool Graphics::Camera::isLocked() const noexcept
{
    return m_locked;
}