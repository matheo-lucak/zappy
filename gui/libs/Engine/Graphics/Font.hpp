/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Font
*/

#pragma once

#include <string_view>
#include <raylib.h>

namespace Graphics
{
    class Font
    {
    protected:
        ::Font m_font;

    public:
        Font(std::string_view filepath) noexcept;
        ~Font() noexcept;

        Font &operator=(const Font &) noexcept = default;
        Font &operator=(Font &&other) noexcept;
    };
}
