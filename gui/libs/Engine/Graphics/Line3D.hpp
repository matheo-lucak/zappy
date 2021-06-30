/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Line
*/

#pragma once

#include "IDrawable.hpp"
#include "Color.hpp"
#include "Vector3.hpp"

namespace Graphics
{
    class Line3D : public IDrawable3D
    {
    public:
        utils::Vector3f starting_position;
        utils::Vector3f ending_position;
        utils::Color color;

    public:
        Line3D() noexcept = default;
        Line3D(utils::Vector3f starting_position, utils::Vector3f ending_position, utils::Color color = utils::Color{}) noexcept;
        Line3D(int start_pos_x, int start_pos_y, int start_pos_z, int end_pos_x, int end_pos_y, int end_pos_z, utils::Color color = utils::Color{}) noexcept;
        Line3D(const Line3D &) noexcept = default;
        Line3D(Line3D &&) noexcept = default;
        ~Line3D() noexcept = default;

        Line3D &operator=(const Line3D &) noexcept = default;
        Line3D &operator=(Line3D &&) noexcept = default;

    protected:
        void draw() const noexcept override;
    };
};
