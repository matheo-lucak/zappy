/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** WiredCube
*/

#include <raylib.h>
#include "WiredCube.hpp"

namespace Graphics
{
    WiredCube::WiredCube(const utils::Vector3f &position, float side_length, utils::Color color) noexcept :
        position{position},
        side_length{side_length},
        color{color}
    {

    }

    WiredCube::WiredCube(float x, float y, float z, float side_length, utils::Color color) noexcept :
        position{x, y, z},
        side_length{side_length},
        color{color}
    {

    }

    void WiredCube::draw() const noexcept
    {
        ::Vector3 converted_position = (::Vector3){position.x, position.y, position.z};
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};
        ::Vector3 properties = (::Vector3){side_length, side_length, side_length};
    
        ::DrawCubeWiresV(converted_position, properties, converted_color);
    }
};
