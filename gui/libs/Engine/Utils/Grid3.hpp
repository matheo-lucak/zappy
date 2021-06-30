/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Grid
*/

#ifndef GRID3_HPP_
#define GRID3_HPP_

#include <optional>
#include <vector>

#include "Utils/Vector3.hpp"
#include "Grid3Cell.hpp"

namespace utils
{
    class Grid3 {
        public:
            Grid3() = delete;
            Grid3(const Vector3u &size, const Vector3f &position = Vector3f{0, 0, 0}) noexcept;
            ~Grid3() noexcept = default;

            /**
            * @brief Get the cell in the grid at the given index.
            * @param x width index in the grid (starting from 0).
            * @param y height index in the grid (starting from 0).
            * @param z depth index in the grid (starting from 0).
            */
            Grid3Cell & at(const unsigned int &x, const unsigned int &y, const unsigned int &z);
            Grid3Cell & at(const Vector3u &coords);

            bool isValidCoords(const unsigned int &x, const unsigned int &y, const unsigned int &z) const;
            bool isValidCoords(const Vector3u &coords) const;


            Vector3u posToCoord(Vector3f position) const;
            Vector3f coordToPos(Vector3u coords);

            /**
            * @brief Update cells sizes.
            */
            void updateCellsSize(void) noexcept;

            /**
            * @brief Update cells position.
            */
            void updateCellsPosition(void) noexcept;

            /**
            * @brief Change the gap between cells.
            * @param newGap New gap applied.
            */
            void setCellGap(const utils::Vector3f &newGap) noexcept;

            /**
            * @brief Change the size of each cells.
            * @param newSize New size applied.
            */
            void setCellSize(const utils::Vector3f &newSize) noexcept;

            /**
            * @brief Change the position of the grid (corner left top).
            * @param newPosition New position applied.
            */
            void setPosition(const utils::Vector3f &newPosition) noexcept;

            Vector3f position;
            const Vector3u size;
            Vector3f cellSize;
            Vector3f cellGap;
        protected:
        private:
            std::vector<Grid3Cell> cells;
    };
}
#endif /* !GRID3_HPP_ */
