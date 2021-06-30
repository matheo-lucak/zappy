/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** ArgumentHelpException
*/

#include "ArgumentHelpException.hpp"

namespace zappy
{
    ArgumentHelpException::ArgumentHelpException(std::string_view message) noexcept
    {
        m_message = message;
    }

    const char* ArgumentHelpException::what() const noexcept
    {
        return m_message.data();
    }
};
