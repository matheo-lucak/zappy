/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Mouse
*/

#include <unordered_map>
#include <raylib.h>
#include "Mouse.hpp"

namespace
{
    const std::unordered_map<Graphics::MouseButton, ::MouseButton> KEY_MAPPER = {
        {Graphics::MouseButton::BUTTON_LEFT, MOUSE_BUTTON_LEFT},
        {Graphics::MouseButton::BUTTON_RIGHT, MOUSE_BUTTON_RIGHT},
        {Graphics::MouseButton::BUTTON_MIDDLE, MOUSE_BUTTON_MIDDLE},
        {Graphics::MouseButton::BUTTON_SIDE, MOUSE_BUTTON_SIDE},
        {Graphics::MouseButton::BUTTON_EXTRA, MOUSE_BUTTON_EXTRA},
        {Graphics::MouseButton::BUTTON_FORWARD, MOUSE_BUTTON_FORWARD},
        {Graphics::MouseButton::BUTTON_BACK, MOUSE_BUTTON_BACK},
    };
}

namespace Graphics
{
    utils::Vector2f Mouse::getPosition() noexcept
    {
        ::Vector2 position = ::GetMousePosition();

        return utils::Vector2f{position.x, position.y};
    }

    void Mouse::setPosition(const utils::Vector2f &position) noexcept
    {
        ::SetMousePosition(position.x, position.y);
    }

    void Mouse::toggleCursorVisibility(bool value) noexcept
    {
        if (value == true) {
            ::ShowCursor();
        } else {
            ::HideCursor();
        }
    }

    bool Mouse::isButtonPressed(MouseButton button) noexcept
    {
        auto it = KEY_MAPPER.find(button);

        if (it == KEY_MAPPER.end())
            return false;
        return ::IsMouseButtonPressed(it->second);
    }

    bool Mouse::isButtonDown(MouseButton button) noexcept
    {
        auto it = KEY_MAPPER.find(button);

        if (it == KEY_MAPPER.end())
            return false;
        return ::IsMouseButtonDown(it->second);
    }

    bool Mouse::isButtonReleased(MouseButton button) noexcept
    {
        auto it = KEY_MAPPER.find(button);

        if (it == KEY_MAPPER.end())
            return false;
        return ::IsMouseButtonReleased(it->second);
    }

    bool Mouse::isButtonUp(MouseButton button) noexcept
    {
        auto it = KEY_MAPPER.find(button);

        if (it == KEY_MAPPER.end())
            return false;
        return ::IsMouseButtonUp(it->second);
    }
};
