/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Pixel
*/

#pragma once

#include "IDrawable.hpp"
#include "Color.hpp"
#include "Vector2.hpp"

namespace Graphics
{
    class Pixel : public IDrawable2D
    {
    public:
        utils::Vector2f position;
        utils::Color color;

    public:
        Pixel(utils::Vector2f position = utils::Vector2f::zero(), utils::Color color = utils::Color{}) noexcept;
        Pixel(int x, int y, utils::Color color = utils::Color{}) noexcept;
        ~Pixel() noexcept = default;

    protected:
        void draw() const noexcept override;
    };
};
