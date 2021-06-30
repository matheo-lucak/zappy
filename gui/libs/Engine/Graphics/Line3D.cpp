/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Line3D
*/

#include <raylib.h>
#include "Line3D.hpp"

namespace Graphics
{
    Line3D::Line3D(utils::Vector3f starting_position, utils::Vector3f ending_position, utils::Color color) noexcept :
        starting_position{starting_position},
        ending_position{ending_position},
        color{color}
    {

    }

    Line3D::Line3D(int start_pos_x, int start_pos_y, int start_pos_z, int end_pos_x, int end_pos_y, int end_pos_z, utils::Color color) noexcept :
        starting_position{start_pos_x, start_pos_y, start_pos_z},
        ending_position{end_pos_x, end_pos_y, end_pos_z},
        color{color}
    {

    }

    void Line3D::draw() const noexcept
    {
        ::Vector3 converted_starting_position = (::Vector3){starting_position.x, starting_position.y, starting_position.z};
        ::Vector3 converted_ending_position = (::Vector3){ending_position.x, ending_position.y, ending_position.z};
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};

        ::DrawLine3D(converted_starting_position, converted_ending_position, converted_color);
    }
}
