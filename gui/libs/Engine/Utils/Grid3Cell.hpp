/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Grid3Cell
*/

#ifndef GRID3CELL_HPP_
#define GRID3CELL_HPP_

#include <functional>
#include <optional>

#include "Vector3.hpp"
#include "ECS/GameObject.hpp"

namespace utils {
    class Grid3Cell {
        public:
            Grid3Cell() noexcept = default;
            Grid3Cell(const Grid3Cell &other) noexcept = default;
            Grid3Cell(Grid3Cell &&other) noexcept = default;
            ~Grid3Cell() noexcept = default;

            /**
            * @brief Get the size of this Cell.
            */
            const Vector3f &getSize(void) const noexcept;

            /**
            * @brief Get the position of center of this Cell.
            */
            const Vector3f &getPosition(void) const noexcept;

            /**
            * @brief Get the object contained in this cell.
            */
            std::optional<std::reference_wrapper<ecs::GameObject>> getObject(void) noexcept;

            /**
            * @brief Change the object contained in this cell.
            */
            void setObject(std::optional<std::reference_wrapper<ecs::GameObject>> newObject) noexcept;
            /**
            * @brief Change the position of the center of this Cell (Will move the cell).
            * @param newPosition New position for the center of the Cell.
            */
            void setPosition(const Vector3f &newPosition) noexcept;

            /**
            * @brief Change the size of this Cell.
            * @param newSize New size of the Cell.
            */
            void setSize(const Vector3f &newSize) noexcept;

        protected:
        private:
            Vector3f position;
            Vector3f size;
            std::optional<std::reference_wrapper<ecs::GameObject>> object;
    };
}

#endif /* !GRID3CELL_HPP_ */
