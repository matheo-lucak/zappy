/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Image
*/

#include <raylib.h>
#include "Image.hpp"
#include "ResourceInitialization.hpp"

namespace Graphics
{
    Image::Image(std::string_view filepath) noexcept
    {
        m_image = ::LoadImage(filepath.data());
    }

    Image::Image(int width, int height, utils::Color color) noexcept
    {
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};

        m_image = ::GenImageColor(width, height, converted_color);
    }

    Image::Image(int width, int height, const VerticalGradient &gradient) noexcept
    {
        ::Color converted_color_top = (::Color){gradient.top.r, gradient.top.g, gradient.top.b, gradient.top.a};
        ::Color converted_color_bottom = (::Color){gradient.bottom.r, gradient.bottom.g, gradient.bottom.b, gradient.bottom.a};

        m_image = ::GenImageGradientV(width, height, converted_color_top, converted_color_bottom);
    }

    Image::Image(int width, int height, const HorizontalGradient &gradient) noexcept
    {
        ::Color converted_color_left = (::Color){gradient.left.r, gradient.left.g, gradient.left.b, gradient.left.a};
        ::Color converted_color_right = (::Color){gradient.right.r, gradient.right.g, gradient.right.b, gradient.right.a};

        m_image = ::GenImageGradientH(width, height, converted_color_left, converted_color_right);
    }

    Image::Image(int width, int height, const RadialGradient &gradient) noexcept
    {
        ::Color converted_color_inner = (::Color){gradient.inner.r, gradient.inner.g, gradient.inner.b, gradient.inner.a};
        ::Color converted_color_outer = (::Color){gradient.outer.r, gradient.outer.g, gradient.outer.b, gradient.outer.a};

        m_image = ::GenImageGradientRadial(width, height, gradient.density, converted_color_inner, converted_color_outer);
    }

    Image::Image(int width, int height, const WhiteNoise &noise) noexcept
    {
        m_image = ::GenImageWhiteNoise(width, height, noise.factor);
    }

    Image::Image(int width, int height, const PerlinNoise &noise) noexcept
    {
        m_image = ::GenImagePerlinNoise(width, height, noise.offset_x, noise.offset_y, noise.scale);
    }

    Image::Image(const Image &other) noexcept
    {
        m_image = ::ImageCopy(other.m_image);
    }

    Image::Image(Image &&other) noexcept
    {
        other.m_image = {};
    }

    Image::~Image() noexcept
    {
        ::UnloadImage(m_image);
    }

    Image &Image::operator=(Image &&other) noexcept
    {
        m_image = other.m_image;
        other.m_image = {};
        return *this;
    }

    int Image::getWidth(void) const noexcept
    {
        return m_image.width;
    }

    int Image::getHeight(void) const noexcept
    {
        return m_image.height;
    }

    void Image::clear(Color color) noexcept
    {
        ::Color converted_color = (::Color){color.r, color.g, color.b, color.a};

        ::ImageClearBackground(&m_image, converted_color);
    }

    void Image::rotate(Rotation rotation) noexcept
    {
        switch (rotation) {
            case Rotation::Clockwise:
                ::ImageRotateCW(&m_image);
                break;
            case Rotation::CounterClockwise:
                ::ImageRotateCCW(&m_image);
                break;
            default:
                break;
        }
    }

    void Image::flip(Flip flip) noexcept
    {
        switch (flip) {
            case Flip::Vertical:
                ::ImageFlipVertical(&m_image);
                break;
            case Flip::Horizontal:
                ::ImageFlipHorizontal(&m_image);
                break;
            default:
                break;
        }
    }

    void Image::invertColor(void) noexcept
    {
        ::ImageColorInvert(&m_image);
    }

    void Image::replaceColor(utils::Color to_replace, utils::Color with) noexcept
    {
        ::Color converted_color_to_replace = (::Color){to_replace.r, to_replace.g, to_replace.b, to_replace.a};
        ::Color converted_color_with = (::Color){with.r, with.g, with.b, with.a};

        ::ImageColorReplace(&m_image, converted_color_to_replace, converted_color_with);
    }

    void Image::setGrayscale(void) noexcept
    {
        ::ImageColorGrayscale(&m_image);
    }

    void Image::setContrast(float level) noexcept
    {
        ::ImageColorContrast(&m_image, level);
    }

    void Image::setColorBrightness(int brightness) noexcept
    {
        ::ImageColorBrightness(&m_image, brightness);
    }

    void Image::drawOnto_Pixel(const Pixel &pixel) noexcept
    {
        ::Vector2 converted_position = (::Vector2){pixel.position.x, pixel.position.y};
        ::Color converted_color = (::Color){pixel.color.r, pixel.color.g, pixel.color.b, pixel.color.a};

        ::ImageDrawPixelV(&m_image, converted_position, converted_color);
    }

    void Image::drawOnto_Line2D(const Line2D &line) noexcept
    {
        ::Vector2 converted_starting_position = (::Vector2){line.starting_position.x, line.starting_position.y};
        ::Vector2 converted_ending_position = (::Vector2){line.ending_position.x, line.ending_position.y};
        ::Color converted_color = (::Color){line.color.r, line.color.g, line.color.b, line.color.a};

        ::ImageDrawLineV(&m_image, converted_starting_position, converted_ending_position, converted_color);
    }

    bool Image::exportToFile(std::string_view filepath) const noexcept
    {
        return ::ExportImage(m_image, filepath.data());
    }
}
