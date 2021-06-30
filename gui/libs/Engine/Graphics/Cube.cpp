/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Cube
*/

#include <raylib.h>
#include "Cube.hpp"

namespace Graphics
{
    Cube::Cube(const utils::Vector3f &position, float side_length, utils::Color color) noexcept :
        m_texture{nullptr},
        position{position},
        side_length{side_length},
        color{color}
    {

    }

    Cube::Cube(float x, float y, float z, float side_length, utils::Color color) noexcept :
        m_texture{nullptr},
        position{x, y, z},
        side_length{side_length},
        color{color}
    {

    }

    void Cube::setTexture(Texture2D *texture) noexcept
    {
        m_texture = texture;
    }

    void Cube::removeTexture(void) noexcept
    {
        m_texture = nullptr;
    }

    void Cube::draw() const noexcept
    {
        ::Vector3 converted_position = (::Vector3){position.x, position.y, position.z};
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};
        ::Vector3 properties = (::Vector3){side_length, side_length, side_length};
    
        if (m_texture) {
            ::DrawCubeTexture(m_texture->m_texture, converted_position, properties.x, properties.y, properties.z, converted_color);
        } else {
            ::DrawCubeV(converted_position, properties, converted_color);
        }
    }
};
