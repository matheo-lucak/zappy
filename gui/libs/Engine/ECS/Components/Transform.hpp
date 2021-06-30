/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Transform
*/

#pragma once

#include "IComponent.hpp"
#include "Utils/Vector3.hpp"

namespace ecs
{
    class Transform : public IComponent
    {
    public:
        Transform() noexcept;
        Transform(const Transform &other) noexcept = default;
        Transform(Transform &&other) noexcept = default;
        ~Transform() noexcept override = default;

        Transform& operator=(const Transform& rhs) noexcept = default;
        Transform& operator=(Transform&& rhs) noexcept = default;

        const utils::Vector3f &getPosition() const noexcept;
        void setPosition(const utils::Vector3f &position) noexcept;

        const utils::Vector3f &getRotation() const noexcept;
        void setRotation(const utils::Vector3f &rotation) noexcept;

        const utils::Vector3f &getScale() const noexcept;
        void setScale(const utils::Vector3f &scale) noexcept;

        std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept override;
        void display(std::ostream& stream) const override;

    private:
        utils::Vector3f m_position;
        utils::Vector3f m_rotation;
        utils::Vector3f m_scale;
    };
};
