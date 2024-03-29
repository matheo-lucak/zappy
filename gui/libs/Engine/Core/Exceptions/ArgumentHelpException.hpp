/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** ArgumentHelpException
*/

#pragma once

#include <string_view>
#include <exception>

namespace zappy
{
    class ArgumentHelpException : public std::exception
    {
    public:
        ArgumentHelpException(std::string_view message) noexcept;
        ~ArgumentHelpException() noexcept override = default;

        const char *what() const noexcept override;

    protected:
        std::string_view m_message;
    };
};
