/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** WiredCube
*/

#pragma once

#include "IDrawable.hpp"
#include "Vector3.hpp"
#include "Color.hpp"

namespace Graphics
{
    class WiredCube : public IDrawable3D
    {
    public:
        utils::Vector3f position;
        float side_length;
        utils::Color color;

    public:
        WiredCube(const utils::Vector3f &position = utils::Vector3f::zero(), float side_length = 1.0f, utils::Color color = utils::Color{}) noexcept;
        WiredCube(float x, float y, float z, float side_length = 1.0f, utils::Color color = utils::Color{}) noexcept;
        WiredCube(const WiredCube &other) noexcept = default;
        ~WiredCube() noexcept = default;

    protected:
        void draw() const noexcept override;
    };
};
