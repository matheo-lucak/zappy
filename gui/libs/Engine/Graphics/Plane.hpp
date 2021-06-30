/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Plane
*/

#pragma once

#include <raylib.h>
#include "IDrawable.hpp"
#include "Vector3.hpp"
#include "Vector2.hpp"
#include "Color.hpp"

namespace Graphics
{
    class Plane : public IDrawable3D
    {
    public:
        utils::Vector3f center_pos;
        utils::Vector2f size;
        utils::Color color;

    public:
        Plane(const utils::Vector3f &center_pos = utils::Vector3f::zero(), const utils::Vector2f &size = utils::Vector2f::one(), utils::Color color = utils::Color{}) noexcept;
        Plane(float center_pos_x, float center_pos_y, float center_pos_z, float size_x, float size_y, utils::Color color = utils::Color{}) noexcept;
        ~Plane() noexcept = default;
    
    protected:
        void draw() const noexcept override;
    };
}
