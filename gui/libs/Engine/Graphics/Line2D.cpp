/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Line2D
*/

#include <raylib.h>
#include "Line2D.hpp"

namespace Graphics
{
    Line2D::Line2D(utils::Vector2f starting_position, utils::Vector2f ending_position, utils::Color color) noexcept :
        starting_position{starting_position},
        ending_position{ending_position},
        color{color}
    {

    }

    Line2D::Line2D(int start_pos_x, int start_pos_y, int end_pos_x, int end_pos_y, utils::Color color) noexcept :
        starting_position{start_pos_x, start_pos_y},
        ending_position{end_pos_x, end_pos_y},
        color{color}
    {

    }

    void Line2D::draw() const noexcept
    {
        ::Vector2 converted_starting_position = (::Vector2){starting_position.x, starting_position.y};
        ::Vector2 converted_ending_position = (::Vector2){ending_position.x, ending_position.y};
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};

        ::DrawLineV(converted_starting_position, converted_ending_position, converted_color);
    }
}
