/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Sphere
*/

#include <raylib.h>
#include "Sphere.hpp"

namespace Graphics
{
    Sphere::Sphere(const utils::Vector3f center_pos, float radius, utils::Color color) noexcept :
        center_pos{center_pos},
        radius{radius},
        color{color}
    {

    }

    Sphere::Sphere(float center_pos_x, float center_pos_y, float center_pos_z, float radius, utils::Color color) noexcept :
        center_pos{center_pos_x, center_pos_y, center_pos_z},
        radius{radius},
        color{color}
    {

    }

    void Sphere::draw() const noexcept
    {
        ::Vector3 converted_center_pos = (::Vector3){center_pos.x, center_pos.y, center_pos.z};
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};

        ::DrawSphere(converted_center_pos, radius, converted_color);
    }
}
