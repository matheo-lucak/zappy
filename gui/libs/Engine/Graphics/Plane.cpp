/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Plane
*/

#include "Plane.hpp"

namespace Graphics
{
    Plane::Plane(const utils::Vector3f &center_pos, const utils::Vector2f &size, utils::Color color) noexcept :
        center_pos{center_pos},
        size{size},
        color{color}
    {

    }

    Plane::Plane(float center_pos_x, float center_pos_y, float center_pos_z, float size_x, float size_y, utils::Color color) noexcept :
        center_pos{center_pos_x, center_pos_y, center_pos_z},
        size{size_x, size_y},
        color{color}
    {

    }

    void Plane::draw() const noexcept
    {
        ::Vector3 converted_center_pos = (::Vector3){center_pos.x, center_pos.y, center_pos.z};
        ::Vector2 converted_size = (::Vector2){size.x, size.y};
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};

        ::DrawPlane(converted_center_pos, converted_size, converted_color);
    }
}
