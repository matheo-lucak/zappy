/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** ArgumentParsingError
*/

#include "ArgumentParsingError.hpp"

namespace indie
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
