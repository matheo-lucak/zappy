/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Grid3Cell
*/

#include "Grid3Cell.hpp"

namespace utils {
    const Vector3f &Grid3Cell::getSize(void) const noexcept
    {
        return this->size;
    }

    const Vector3f &Grid3Cell::getPosition(void) const noexcept
    {
        return this->position;
    }

    std::optional<std::reference_wrapper<ecs::GameObject>> Grid3Cell::getObject(void) noexcept
    {
        return this->object;
    }

    void Grid3Cell::setObject(std::optional<std::reference_wrapper<ecs::GameObject>> newObject) noexcept
    {
        this->object = newObject;
        setPosition(position);
    }

    void Grid3Cell::setPosition(const Vector3f &newPosition) noexcept
    {
        this->position = newPosition;
        if (object.has_value()) {
            object.value().get().transform().setPosition(this->position);
        }
    }

    void Grid3Cell::setSize(const Vector3f &newSize) noexcept
    {
        this->size = newSize;
    }
}