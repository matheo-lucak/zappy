/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Touch
*/

#pragma once

#include "Vector2.hpp"

namespace Graphics
{
    class Touch
    {
    public:
        static utils::Vector2f getPosition() noexcept;
    };
};
