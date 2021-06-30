/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Color
*/

#pragma once

#include <string_view>
#include <array>
#include <ostream>

namespace utils
{
    class Color
    {
    public:
        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
        std::uint8_t a;

        Color() noexcept;
        Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255) noexcept;
        Color(const Color& other) noexcept = default;
        Color(Color&& other) noexcept = default;
        explicit Color(std::uint32_t color) noexcept;
        ~Color() = default;

        std::uint32_t toInt() const noexcept;

        Color &operator=(const Color &other);
        Color &operator+=(const Color &other);
        Color &operator-=(const Color &other);
        Color &operator*=(const Color &other);

        static const Color Black;
        static const Color White;
        static const Color Purple;
        static const Color Red;
        static const Color Orange;
        static const Color Yellow;
        static const Color LightGreen;
        static const Color DarkGreen;
        static const Color Cyan;
        static const Color Aqua;
        static const Color DarkBlue;
        static const Color LightBlue;
        
        static Color NameToColor(std::string_view name);

    private:
        union SplitColor
        {
            std::uint32_t rgba;
            std::array<std::uint8_t, 4> colors;
        };
    };

    Color operator+(const Color &left, const Color &right);
    Color operator-(const Color &left, const Color &right);
    Color operator*(const Color &left, const Color &right);

    inline std::ostream& operator<<(std::ostream& stream, const Color& color)
    {
        stream  << '(' << (static_cast<int>(color.r))
                << ", " << (static_cast<int>(color.g))
                << ", " << (static_cast<int>(color.b))
                << ", " << (static_cast<int>(color.a)) << ')';
        return stream;
    }
};
