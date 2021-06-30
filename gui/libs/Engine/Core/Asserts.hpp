/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Asserts
*/

#pragma once

#include <stdexcept>

#define ZAPPY_CORE_ASSERT(m__cond, m__msg)  \
    if (m__cond) { throw std::runtime_error(m__msg); }
