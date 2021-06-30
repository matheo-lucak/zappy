/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Transform
*/

#include "Transform.hpp"

namespace ecs
{
    Transform::Transform() noexcept
    {
        m_position = utils::Vector3f::zero();
        m_rotation = utils::Vector3f::zero();
        m_scale = utils::Vector3f::one();
    }

    const utils::Vector3f &Transform::getPosition() const noexcept
    {
        return m_position;
    }

    void Transform::setPosition(const utils::Vector3f &position) noexcept
    {
        m_position = position;
    }

    const utils::Vector3f &Transform::getRotation() const noexcept
    {
        return m_rotation;
    }

    void Transform::setRotation(const utils::Vector3f &rotation) noexcept
    {
        m_rotation = rotation;
    }

    const utils::Vector3f &Transform::getScale() const noexcept
    {
        return m_scale;
    }

    void Transform::setScale(const utils::Vector3f &scale) noexcept
    {
        m_scale = scale;
    }

    std::unique_ptr<IComponent> Transform::copy(ecs::GameObject &copyOn) const noexcept
    {
        (void)copyOn;
        return std::make_unique<Transform>(*this);
    }

    void Transform::display(std::ostream& stream) const
    {
        stream << "Transform:\n"
               << "\tPosition = " << m_position << '\n'
               << "\tRotation = " << m_rotation << '\n'
               << "\tScale    = " << m_scale;
    }
};
