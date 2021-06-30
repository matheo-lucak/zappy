/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** string
*/

#pragma once

#include <algorithm>
#include <string_view>
#include <cctype>

namespace utils::string
{
    inline constexpr bool startswith(std::string_view haystack, std::string_view needle) noexcept
    {
        return needle.length() <= haystack.length() 
            && std::equal(needle.begin(), needle.end(), haystack.begin());
    }

    inline constexpr bool icompare(std::string_view a, std::string_view b) noexcept
    {
        if (a.size() != b.size()) {
            return false;
        }
        for (std::size_t i = 0; i < a.size(); ++i) {
            if (std::tolower(a[i]) != std::tolower(b[i])) {
                return false;
            }
        }
        return true;
    }
} // namespace utils::string
