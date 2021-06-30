/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Pixel
*/

#include <raylib.h>
#include "Pixel.hpp"

namespace Graphics
{
    Pixel::Pixel(utils::Vector2f position, utils::Color color) noexcept :
        position{position},
        color{color}
    {

    }

    Pixel::Pixel(int x, int y, utils::Color color) noexcept :
        position{x, y},
        color{color}
    {

    }

    void Pixel::draw() const noexcept
    {
        ::Vector2 converted_position = (::Vector2){position.x, position.y};
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};

        ::DrawPixelV(converted_position, converted_color);
    }
}
