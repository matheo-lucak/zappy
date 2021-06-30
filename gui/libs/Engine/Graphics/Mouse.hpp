/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Mouse
*/

#pragma once

#include "Vector2.hpp"

namespace Graphics
{
    enum class MouseButton
    {
        BUTTON_LEFT,
        BUTTON_RIGHT,
        BUTTON_MIDDLE,
        BUTTON_SIDE,
        BUTTON_EXTRA,
        BUTTON_FORWARD,
        BUTTON_BACK,
    };

    class Mouse
    {
    public:
        static utils::Vector2f getPosition() noexcept;
        static void setPosition(const utils::Vector2f &position) noexcept;

        static void toggleCursorVisibility(bool value) noexcept;

        static bool isButtonPressed(MouseButton button) noexcept;
        static bool isButtonDown(MouseButton button) noexcept;
        static bool isButtonReleased(MouseButton button) noexcept;
        static bool isButtonUp(MouseButton button) noexcept;
    };
};
