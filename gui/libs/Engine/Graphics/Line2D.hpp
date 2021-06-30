/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Line
*/

#pragma once

#include "IDrawable.hpp"
#include "Color.hpp"
#include "Vector2.hpp"

namespace Graphics
{
    class Line2D : public IDrawable2D
    {
    public:
        utils::Vector2f starting_position;
        utils::Vector2f ending_position;
        utils::Color color;

    public:
        Line2D() noexcept = default;
        Line2D(utils::Vector2f starting_position, utils::Vector2f ending_position, utils::Color color = utils::Color{}) noexcept;
        Line2D(int start_pos_x, int start_pos_y, int end_pos_x, int end_pos_y, utils::Color color = utils::Color{}) noexcept;
        Line2D(const Line2D &) noexcept = default;
        Line2D(Line2D &&) noexcept = default;
        ~Line2D() noexcept = default;

        Line2D &operator=(const Line2D &) noexcept = default;
        Line2D &operator=(Line2D &&) noexcept = default;

    protected:
        void draw() const noexcept override;
    };
};
