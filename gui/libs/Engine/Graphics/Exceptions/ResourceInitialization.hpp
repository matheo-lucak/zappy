/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** ResourceInitialization
*/

#pragma once

#include <string_view>
#include <exception>

namespace Graphics
{
    class ResourceInitialization : public std::exception
    {
    public:
        ResourceInitialization(std::string_view message) noexcept;
        ~ResourceInitialization() noexcept override = default;

        const char *what() const noexcept override;

    protected:
        std::string_view m_message;
    };
};
