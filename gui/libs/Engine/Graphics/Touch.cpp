/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Touch
*/

#include <raylib.h>
#include "Touch.hpp"

namespace Graphics
{
    utils::Vector2f Touch::getPosition() noexcept
    {
        ::Vector2 position = ::GetTouchPosition(0);

        return utils::Vector2f{position.x, position.y};
    }
}
