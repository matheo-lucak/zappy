/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Text
*/

#include <raylib.h>
#include "Text.hpp"

namespace Graphics
{
    Text::Text(const std::string &text, const utils::Vector2f &position, const utils::Color &color, float size) noexcept :
        text{text},
        position{position},
        color{color},
        size{size}
    {
    }

    void Text::draw() const noexcept
    {
        ::DrawText(text.c_str(),
                    position.x,
                    position.y,
                    static_cast<int>(size),
                    CLITERAL(::Color){color.r, color.g, color.b, color.a});
    }
};
