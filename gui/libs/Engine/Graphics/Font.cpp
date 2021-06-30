/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Font
*/

#include "Font.hpp"

namespace Graphics
{
    Font::Font(std::string_view filepath) noexcept
    {
        m_font = ::LoadFont(filepath.data());
    }

    Font::~Font() noexcept
    {
        ::UnloadFont(m_font);
    }

    Font &Font::operator=(Font &&other) noexcept
    {
        m_font = other.m_font;
        other.m_font = {};
        return *this;
    }
}
