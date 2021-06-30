/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Asserts
*/

#pragma once

#include <stdexcept>

#define INDIE_CORE_ASSERT(m__cond, m__msg)  \
    if (m__cond) { throw std::runtime_error(m__msg); }
