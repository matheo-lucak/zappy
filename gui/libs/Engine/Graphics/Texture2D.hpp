/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Texture2D
*/

#pragma once

#include <string_view>
#include <raylib.h>
#include "IDrawable.hpp"
#include "Image.hpp"
#include "Vector2.hpp"

namespace Graphics
{
    class Texture2D : public IDrawable2D
    {
        friend class Cube;
        friend class Model;

    protected:
        ::Texture2D m_texture;

    public:
        utils::Vector2f position;
        float rotation;
        float scale;
        utils::Color color;

    public:
        Texture2D(std::string_view filepath, const utils::Vector2f &position = utils::Vector2f::zero(), float rotation = 0.0f, float scale = 1.0f, utils::Color color = utils::Color::White) noexcept;
        Texture2D(std::string_view filepath, float x, float y, float rotation = 0.0f, float scale = 1.0f, utils::Color color = utils::Color::White) noexcept;
        Texture2D(const Image &image, const utils::Vector2f &position = utils::Vector2f::zero(), float rotation = 0.0f, float scale = 1.0f, utils::Color color = utils::Color::White) noexcept;
        Texture2D(const Image &image, float x, float y, float rotation = 0.0f, float scale = 1.0f, utils::Color color = utils::Color::White) noexcept;
        Texture2D(const Texture2D &) noexcept = default;
        Texture2D(Texture2D &&other) noexcept;
        ~Texture2D() noexcept;

        Texture2D &operator=(const Texture2D &) noexcept = default;
        Texture2D &operator=(Texture2D &&) noexcept = default;

        virtual utils::Vector2f getSize() const noexcept;

    protected:
        void draw() const noexcept override;
    };
};
