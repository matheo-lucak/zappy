/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** ResourceInitialization
*/

#include "ResourceInitialization.hpp"

namespace Graphics
{
    ResourceInitialization::ResourceInitialization(std::string_view message) noexcept
    {
        m_message = message;
    }

    const char* ResourceInitialization::what() const noexcept
    {
        return m_message.data();
    }
};
