/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** ArgumentParsingError
*/

#include "ArgumentParsingError.hpp"

namespace zappy
{
    ArgumentParsingError::ArgumentParsingError(std::string_view message) noexcept
    {
        m_message = message;
    }

    const char* ArgumentParsingError::what() const noexcept
    {
        return m_message.data();
    }
};
