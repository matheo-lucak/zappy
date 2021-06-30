/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** WiredSphere
*/

#pragma once

#include "IDrawable.hpp"
#include "Vector3.hpp"
#include "Color.hpp"

namespace Graphics
{
    class WiredSphere : public IDrawable3D
    {
    public:
        utils::Vector3f center_pos;
        float radius;
        int nb_rings;
        int nb_slices;
        utils::Color color;

    public:
        WiredSphere(const utils::Vector3f center_pos = utils::Vector3f::zero(), float radius = 1.0f, int nb_rings = 4, int nb_slices = 4, utils::Color color = utils::Color{}) noexcept;
        WiredSphere(float center_pos_x, float center_pos_y, float center_pos_z, float radius = 1.0f, int nb_rings = 4, int nb_slices = 4, utils::Color color = utils::Color{}) noexcept;
        WiredSphere(const WiredSphere &other) noexcept = default;
        ~WiredSphere() noexcept = default;

    protected:
        void draw() const noexcept override;
    };
}
