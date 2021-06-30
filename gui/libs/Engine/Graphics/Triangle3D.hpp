/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Triangle3D
*/

#pragma once

#include "IDrawable.hpp"
#include "Vector3.hpp"
#include "Color.hpp"

namespace Graphics
{
    class Triangle3D : public IDrawable2D
    {
    public:
        utils::Vector3f p1;
        utils::Vector3f p2;
        utils::Vector3f p3;
        utils::Color color;

    public:
        Triangle3D(const utils::Vector3f &p1, const utils::Vector3f &p2, const utils::Vector3f &p3, utils::Color color = utils::Color{}) noexcept;
        ~Triangle3D() noexcept = default;

    protected:
        void draw() const noexcept override;
    };
}
