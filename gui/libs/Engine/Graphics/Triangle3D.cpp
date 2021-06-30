/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Triangle3D
*/

#include <raylib.h>
#include "Triangle3D.hpp"

namespace Graphics
{
    Triangle3D::Triangle3D(const utils::Vector3f &p1, const utils::Vector3f &p2, const utils::Vector3f &p3, utils::Color color) noexcept :
        p1{p1},
        p2{p2},
        p3{p3},
        color{color}
    {

    }

    void Triangle3D::draw() const noexcept
    {
        ::Vector3 converted_p1 = (::Vector3){p1.x, p1.y, p1.z};
        ::Vector3 converted_p2 = (::Vector3){p2.x, p2.y, p2.z};
        ::Vector3 converted_p3 = (::Vector3){p3.x, p3.y, p3.z};
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};

        ::DrawTriangle3D(converted_p1, converted_p2, converted_p3, converted_color);
    }
}
