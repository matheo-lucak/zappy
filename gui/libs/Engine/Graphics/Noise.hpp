/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Noise
*/

#pragma once

namespace Graphics
{
    struct WhiteNoise
    {
    public:
        float factor;
    };

    struct PerlinNoise
    {
    public:
        int offset_x;
        int offset_y;
        float scale;
    };
}
