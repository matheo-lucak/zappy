/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** WiredRectangularPrism
*/

#include <raylib.h>
#include "WiredRectangularPrism.hpp"

namespace Graphics
{
    WiredRectangularPrism::WiredRectangularPrism(const utils::Vector3f &position, float width, float height, float length, utils::Color color) noexcept :
        position{position},
        width{width},
        height{height},
        length{length},
        color{color}
    {

    }

    WiredRectangularPrism::WiredRectangularPrism(float x, float y, float z, float width, float height, float length, utils::Color color) noexcept :
        position{x, y, z},
        width{width},
        height{height},
        length{length},
        color{color}
    {

    }

    void WiredRectangularPrism::draw() const noexcept
    {
        ::Vector3 converted_position = (::Vector3){position.x, position.y, position.z};
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};
        ::Vector3 properties = (::Vector3){width, height, length};

        ::DrawCubeWiresV(converted_position, properties, converted_color);
    }
}
