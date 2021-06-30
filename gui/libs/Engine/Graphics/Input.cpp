/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Input
*/

#include <unordered_map>
#include <raylib.h>
#include "Input.hpp"

namespace
{
    const std::unordered_map<Graphics::Keycode, ::KeyboardKey> KEY_MAPPER = {
        {Graphics::Keycode::UNKNOWN, KEY_NULL},
        {Graphics::Keycode::APOSTROPHE, KEY_APOSTROPHE},
        {Graphics::Keycode::COMMA, KEY_COMMA},
        {Graphics::Keycode::MINUS, KEY_MINUS},
        {Graphics::Keycode::PERIOD, KEY_PERIOD},
        {Graphics::Keycode::SLASH, KEY_SLASH},
        {Graphics::Keycode::ZERO, KEY_ZERO},
        {Graphics::Keycode::ONE, KEY_ONE},
        {Graphics::Keycode::TWO, KEY_TWO},
        {Graphics::Keycode::THREE, KEY_THREE},
        {Graphics::Keycode::FOUR, KEY_FOUR},
        {Graphics::Keycode::FIVE, KEY_FIVE},
        {Graphics::Keycode::SIX, KEY_SIX},
        {Graphics::Keycode::SEVEN, KEY_SEVEN},
        {Graphics::Keycode::EIGHT, KEY_EIGHT},
        {Graphics::Keycode::NINE, KEY_NINE},
        {Graphics::Keycode::SEMICOLON, KEY_SEMICOLON},
        {Graphics::Keycode::EQUAL, KEY_EQUAL},
        {Graphics::Keycode::A, KEY_A},
        {Graphics::Keycode::B, KEY_B},
        {Graphics::Keycode::C, KEY_C},
        {Graphics::Keycode::D, KEY_D},
        {Graphics::Keycode::E, KEY_E},
        {Graphics::Keycode::F, KEY_F},
        {Graphics::Keycode::G, KEY_G},
        {Graphics::Keycode::H, KEY_H},
        {Graphics::Keycode::I, KEY_I},
        {Graphics::Keycode::J, KEY_J},
        {Graphics::Keycode::K, KEY_K},
        {Graphics::Keycode::L, KEY_L},
        {Graphics::Keycode::M, KEY_M},
        {Graphics::Keycode::N, KEY_N},
        {Graphics::Keycode::O, KEY_O},
        {Graphics::Keycode::P, KEY_P},
        {Graphics::Keycode::Q, KEY_Q},
        {Graphics::Keycode::R, KEY_R},
        {Graphics::Keycode::S, KEY_S},
        {Graphics::Keycode::T, KEY_T},
        {Graphics::Keycode::U, KEY_U},
        {Graphics::Keycode::V, KEY_V},
        {Graphics::Keycode::W, KEY_W},
        {Graphics::Keycode::X, KEY_X},
        {Graphics::Keycode::Y, KEY_Y},
        {Graphics::Keycode::Z, KEY_Z},
        {Graphics::Keycode::SPACE, KEY_SPACE},
        {Graphics::Keycode::ESCAPE, KEY_ESCAPE},
        {Graphics::Keycode::ENTER, KEY_ENTER},
        {Graphics::Keycode::TAB, KEY_TAB},
        {Graphics::Keycode::BACKSPACE, KEY_BACKSPACE},
        {Graphics::Keycode::INSERT, KEY_INSERT},
        {Graphics::Keycode::DELETE, KEY_DELETE},
        {Graphics::Keycode::RIGHT, KEY_RIGHT},
        {Graphics::Keycode::LEFT, KEY_LEFT},
        {Graphics::Keycode::DOWN, KEY_DOWN},
        {Graphics::Keycode::UP, KEY_UP},
        {Graphics::Keycode::PAGE_UP, KEY_PAGE_UP},
        {Graphics::Keycode::PAGE_DOWN, KEY_PAGE_DOWN},
        {Graphics::Keycode::HOME, KEY_HOME},
        {Graphics::Keycode::END, KEY_END},
        {Graphics::Keycode::CAPS_LOCK, KEY_CAPS_LOCK},
        {Graphics::Keycode::SCROLL_LOCK, KEY_SCROLL_LOCK},
        {Graphics::Keycode::NUM_LOCK, KEY_NUM_LOCK},
        {Graphics::Keycode::PRINT_SCREEN, KEY_PRINT_SCREEN},
        {Graphics::Keycode::PAUSE, KEY_PAUSE},
        {Graphics::Keycode::F1, KEY_F1},
        {Graphics::Keycode::F2, KEY_F2},
        {Graphics::Keycode::F3, KEY_F3},
        {Graphics::Keycode::F4, KEY_F4},
        {Graphics::Keycode::F5, KEY_F5},
        {Graphics::Keycode::F6, KEY_F6},
        {Graphics::Keycode::F7, KEY_F7},
        {Graphics::Keycode::F8, KEY_F8},
        {Graphics::Keycode::F9, KEY_F9},
        {Graphics::Keycode::F10, KEY_F10},
        {Graphics::Keycode::F11, KEY_F11},
        {Graphics::Keycode::F12, KEY_F12},
        {Graphics::Keycode::LEFT_SHIFT, KEY_LEFT_SHIFT},
        {Graphics::Keycode::LEFT_CONTROL, KEY_LEFT_CONTROL},
        {Graphics::Keycode::LEFT_ALT, KEY_LEFT_ALT},
        {Graphics::Keycode::LEFT_SUPER, KEY_LEFT_SUPER},
        {Graphics::Keycode::RIGHT_SHIFT, KEY_RIGHT_SHIFT},
        {Graphics::Keycode::RIGHT_CONTROL, KEY_RIGHT_CONTROL},
        {Graphics::Keycode::RIGHT_ALT, KEY_RIGHT_ALT},
        {Graphics::Keycode::RIGHT_SUPER, KEY_RIGHT_SUPER},
        {Graphics::Keycode::KB_MENU, KEY_KB_MENU},
        {Graphics::Keycode::LEFT_BRACKET, KEY_LEFT_BRACKET},
        {Graphics::Keycode::RIGHT_BRACKET, KEY_RIGHT_BRACKET},
        {Graphics::Keycode::GRAVE, KEY_GRAVE},
        {Graphics::Keycode::KP_0, KEY_KP_0},
        {Graphics::Keycode::KP_1, KEY_KP_1},
        {Graphics::Keycode::KP_2, KEY_KP_2},
        {Graphics::Keycode::KP_3, KEY_KP_3},
        {Graphics::Keycode::KP_4, KEY_KP_4},
        {Graphics::Keycode::KP_5, KEY_KP_5},
        {Graphics::Keycode::KP_6, KEY_KP_6},
        {Graphics::Keycode::KP_7, KEY_KP_7},
        {Graphics::Keycode::KP_8, KEY_KP_8},
        {Graphics::Keycode::KP_9, KEY_KP_9},
        {Graphics::Keycode::KP_DECIMAL, KEY_KP_DECIMAL},
        {Graphics::Keycode::KP_DIVIDE, KEY_KP_DIVIDE},
        {Graphics::Keycode::KP_MULTIPLY, KEY_KP_MULTIPLY},
        {Graphics::Keycode::KP_SUBTRACT, KEY_KP_SUBTRACT},
        {Graphics::Keycode::KP_ADD, KEY_KP_ADD},
        {Graphics::Keycode::KP_ENTER, KEY_KP_ENTER},
        {Graphics::Keycode::KP_EQUAL, KEY_KP_EQUAL},
        {Graphics::Keycode::BACK, KEY_BACK},
        {Graphics::Keycode::MENU, KEY_MENU},
        {Graphics::Keycode::VOLUME_UP, KEY_VOLUME_UP},
        {Graphics::Keycode::VOLUME_DOWN, KEY_VOLUME_DOWN},
    };
}

namespace Graphics
{
    bool Input::isKeyPressed(Keycode code) noexcept
    {
        auto it = KEY_MAPPER.find(code);

        if (it == KEY_MAPPER.end())
            return false;
        return ::IsKeyPressed(it->second);
    }

    bool Input::isKeyDown(Keycode code) noexcept
    {
        auto it = KEY_MAPPER.find(code);

        if (it == KEY_MAPPER.end())
            return false;
        return ::IsKeyDown(it->second);
    }

    bool Input::isKeyReleased(Keycode code) noexcept
    {
        auto it = KEY_MAPPER.find(code);

        if (it == KEY_MAPPER.end())
            return false;
        return ::IsKeyReleased(it->second);
    }

    bool Input::isKeyUp(Keycode code) noexcept
    {
        auto it = KEY_MAPPER.find(code);

        if (it == KEY_MAPPER.end())
            return false;
        return ::IsKeyUp(it->second);
    }
}
