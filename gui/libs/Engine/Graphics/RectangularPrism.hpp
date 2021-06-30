/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** RectangularPrism
*/

#pragma once

#include "IDrawable.hpp"
#include "Vector3.hpp"
#include "Color.hpp"

namespace Graphics
{
    class RectangularPrism : public IDrawable3D
    {
    public:
        utils::Vector3f position;
        float width;
        float height;
        float length;
        utils::Color color;

    public:
        RectangularPrism(const utils::Vector3f &position = utils::Vector3f::zero(), float width = 1.0f, float height = 1.0f, float length = 1.0f, utils::Color color = utils::Color{}) noexcept;
        RectangularPrism(float x, float y, float z, float width = 1.0f, float height = 1.0f, float length = 1.0f, utils::Color color = utils::Color{}) noexcept;
        RectangularPrism(const RectangularPrism &other) noexcept = default;
        ~RectangularPrism() noexcept = default;

    protected:
        void draw() const noexcept override;
    };
}
