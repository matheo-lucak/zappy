/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Color
*/

#include "Color.hpp"
#include <unordered_map>

namespace utils
{
    Color const Color::Black      = Color{  0,   0,   0, 255};
    Color const Color::White      = Color{255, 255, 255, 255};
    Color const Color::Purple     = Color{255,   0, 255, 255};
    Color const Color::Red        = Color{255,   0,   0, 255};
    Color const Color::Orange     = Color{255, 165,   0, 255};
    Color const Color::Yellow     = Color{255, 255,   0, 255};
    Color const Color::LightGreen = Color{  0, 255,   0, 255};
    Color const Color::DarkGreen  = Color{ 50, 205,  50, 255};
    Color const Color::Cyan       = Color{  0, 255, 255, 255};
    Color const Color::DarkBlue   = Color{ 65, 105, 225, 255};
    Color const Color::LightBlue  = Color{135, 206, 250, 255};

    static const std::unordered_map<std::string_view, Color> m_nameToString{
        { "Black",      Color::Black        },
        { "White",      Color::White        },
        { "Purple",     Color::Purple       },
        { "Red",        Color::Red          },
        { "Orange",     Color::Orange       },
        { "Yellow",     Color::Yellow       },
        { "LightGreen", Color::LightGreen   },
        { "DarkGreen",  Color::DarkGreen    },
        { "Cyan",       Color::Cyan         },
        { "DarkBlue",   Color::DarkBlue     },
        { "LightBlue",  Color::LightBlue    },
    };

    Color::Color() noexcept
    {
        r = 0;
        g = 0;
        b = 0;
        a = 255;
    }

    Color::Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) noexcept
    {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }

    Color::Color(std::uint32_t color) noexcept
    {
        SplitColor splitColor;

        splitColor.rgba = color;
        r = splitColor.colors[0];
        g = splitColor.colors[1];
        b = splitColor.colors[2];
        a = splitColor.colors[3];
    }

    std::uint32_t Color::toInt() const noexcept
    {
        SplitColor splitColor;

        splitColor.colors = {r, g, b, a};
        return splitColor.rgba;
    }

    Color &Color::operator=(const Color &other)
    {
        r = other.r;
        g = other.g;
        b = other.b;
        a = other.a;
        return *this;
    }

    Color &Color::operator+=(const Color &other)
    {
        r += other.r;
        g += other.g;
        b += other.b;
        a += other.a;
        return *this;
    }

    Color &Color::operator-=(const Color &other)
    {
        r -= other.r;
        g -= other.g;
        b -= other.b;
        a -= other.a;
        return *this;
    }

    Color &Color::operator*=(const Color &other)
    {
        r *= other.r;
        g *= other.g;
        b *= other.b;
        a *= other.a;
        return *this;
    }

    Color operator+(const Color &left, const Color &right)
    {
        Color color(left.r + right.r,
                    left.g + right.g,
                    left.b + right.b,
                    left.a + right.a);

        return color;
    }

    Color operator-(const Color &left, const Color &right)
    {
        Color color(left.r - right.r,
                    left.g - right.g,
                    left.b - right.b,
                    left.a - right.a);

        return color;
    }

    Color operator*(const Color &left, const Color &right)
    {
        Color color(left.r * right.r,
                    left.g * right.g,
                    left.b * right.b,
                    left.a * right.a);

        return color;
    }

    Color Color::NameToColor(std::string_view name)
    {
        return m_nameToString.at(name);
    }
};
