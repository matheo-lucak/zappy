/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Image
*/

#pragma once

#include <string_view>
#include "Color.hpp"
#include "Pixel.hpp"
#include "Line2D.hpp"
#include "Noise.hpp"
#include "Gradient.hpp"

namespace Graphics
{
    class Image
    {
        friend class Texture2D;

    public:
        enum class Rotation
        {
            Clockwise,
            CounterClockwise
        };

        enum class Flip
        {
            Vertical,
            Horizontal
        };

    protected:
        ::Image m_image;

    public:
        Image(std::string_view filepath) noexcept;
        Image(int width, int height, utils::Color color = utils::Color{}) noexcept;
        Image(int width, int height, const VerticalGradient &gradient) noexcept;
        Image(int width, int height, const HorizontalGradient &gradient) noexcept;
        Image(int width, int height, const RadialGradient &gradient) noexcept;
        Image(int width, int height, const WhiteNoise &noise) noexcept;
        Image(int width, int height, const PerlinNoise &noise) noexcept;
        Image(const Image &other) noexcept;
        Image(Image &&other) noexcept;
        ~Image() noexcept;

        Image &operator=(const Image &) noexcept = default;
        Image &operator=(Image &&other) noexcept;

        int getWidth(void) const noexcept;
        int getHeight(void) const noexcept;

        void rotate(Rotation rotation) noexcept;
        void flip(Flip flip) noexcept;
        void invertColor(void) noexcept;
        void replaceColor(utils::Color to_replace, utils::Color with) noexcept;
        void setGrayscale(void) noexcept;
        void setContrast(float level) noexcept;
        void setColorBrightness(int brightness) noexcept;

        void clear(Color color) noexcept;
        void drawOnto_Pixel(const Pixel &pixel) noexcept;
        void drawOnto_Line2D(const Line2D &line) noexcept;
        
        bool exportToFile(std::string_view filepath) const noexcept;
    };
}
