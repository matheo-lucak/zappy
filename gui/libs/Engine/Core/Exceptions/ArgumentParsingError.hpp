/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** ArgumentParsingError
*/

#pragma once

#include <string_view>
#include <exception>

namespace indie
{
    class ArgumentParsingError : public std::exception
    {
    public:
        ArgumentParsingError(std::string_view message) noexcept;
        ~ArgumentParsingError() noexcept override = default;

        const char *what() const noexcept override;

    protected:
        std::string_view m_message;
    };
};
