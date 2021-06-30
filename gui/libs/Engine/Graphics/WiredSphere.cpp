/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** WiredSphere
*/

#include <raylib.h>
#include "WiredSphere.hpp"

namespace Graphics
{
    WiredSphere::WiredSphere(const utils::Vector3f center_pos, float radius, int nb_rings, int nb_slices, utils::Color color) noexcept :
        center_pos{center_pos},
        radius{radius},
        nb_rings{nb_rings},
        nb_slices{nb_slices},
        color{color}
    {

    }

    WiredSphere::WiredSphere(float center_pos_x, float center_pos_y, float center_pos_z, float radius, int nb_rings, int nb_slices, utils::Color color) noexcept :
        center_pos{center_pos_x, center_pos_y, center_pos_z},
        radius{radius},
        nb_rings{nb_rings},
        nb_slices{nb_slices},
        color{color}
    {

    }

    void WiredSphere::draw() const noexcept
    {
        ::Vector3 converted_center_pos = (::Vector3){center_pos.x, center_pos.y, center_pos.z};
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};

        ::DrawSphereWires(converted_center_pos, radius, nb_rings, nb_slices, converted_color);
    }
}
