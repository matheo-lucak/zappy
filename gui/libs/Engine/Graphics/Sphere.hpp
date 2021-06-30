/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Sphere
*/

#pragma once

#include "IDrawable.hpp"
#include "Vector3.hpp"
#include "Color.hpp"

namespace Graphics
{
    class Sphere : public IDrawable3D
    {
    public:
        utils::Vector3f center_pos;
        float radius;
        utils::Color color;

    public:
        Sphere(const utils::Vector3f center_pos = utils::Vector3f::zero(), float radius = 1.0f, utils::Color color = utils::Color{}) noexcept;
        Sphere(float center_pos_x, float center_pos_y, float center_pos_z, float radius = 1.0f, utils::Color color = utils::Color{}) noexcept;
        Sphere(const Sphere &other) noexcept = default;
        ~Sphere() noexcept = default;

    protected:
        void draw() const noexcept override;
    };
}
