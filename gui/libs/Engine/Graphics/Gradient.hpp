/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Gradient
*/

#pragma once

#include "Color.hpp"

namespace Graphics
{
    struct VerticalGradient
    {
    public:
        utils::Color top;
        utils::Color bottom;
    };

    struct HorizontalGradient
    {
    public:
        utils::Color left;
        utils::Color right;
    };

    struct RadialGradient
    {
    public:
        float density;
        utils::Color inner;
        utils::Color outer;
    };
}
