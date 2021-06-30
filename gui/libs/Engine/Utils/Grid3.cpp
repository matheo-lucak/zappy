/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Grid3
*/

#include <iostream>

#include "Grid3.hpp"

namespace utils
{
    Grid3::Grid3(const Vector3u &pSize, const Vector3f &pPosition) noexcept :
        position(pPosition),
        size(pSize),
        cellSize(1, 1, 1),
        cellGap(0, 0, 0)
    {
        cells.reserve(pSize.x * pSize.y * pSize.z);
        for (unsigned int z = 0; z < this->size.z; z += 1) {
            for (unsigned int y = 0; y < this->size.y; y += 1) {
                for (unsigned int x = 0; x < this->size.x; x += 1) {
                    this->cells.push_back(Grid3Cell());
                }
            }
        }
        this->updateCellsSize();
        this->updateCellsPosition();
    }

    Grid3Cell & Grid3::at(const unsigned int &x, const unsigned int &y, const unsigned int &z)
    {
        unsigned int index = 0;

        if (isValidCoords(x, y, z) == false) {
            throw std::runtime_error("Out of range.");
        }
        index = x + y * this->size.x + z * this->size.x * this->size.y;
        return this->cells[index];
    }

    Grid3Cell & Grid3::at(const Vector3u &coords)
    {
        return at(coords.x, coords.y, coords.z);
    }

    bool Grid3::isValidCoords(const unsigned int &x, const unsigned int &y, const unsigned int &z) const
    {
        return x < this->size.x && y < this->size.y && z < this->size.z;
    }

    bool Grid3::isValidCoords(const Vector3u &coords) const
    {
        return isValidCoords(coords.x, coords.y, coords.z);
    }

    Vector3u Grid3::posToCoord(Vector3f pos) const
    {
        Vector3f tmp = pos - this->position;
        return tmp / cellSize;
    }

    Vector3f Grid3::coordToPos(Vector3u coords)
    {
        return at(coords).getPosition();
    }

    void Grid3::setCellGap(const utils::Vector3f &newGap) noexcept
    {
        this->cellGap = newGap;
        this->updateCellsPosition();
    }

    void Grid3::setCellSize(const utils::Vector3f &newSize) noexcept
    {
        this->cellSize = newSize;
        this->updateCellsSize();
        this->updateCellsPosition();
    }

    void Grid3::setPosition(const utils::Vector3f &newPosition) noexcept
    {
        this->position = newPosition;
        this->updateCellsPosition();
    }

    void Grid3::updateCellsSize(void) noexcept
    {
        for (auto &i : cells) {
            i.setSize(this->cellSize);
        }
    }

    void Grid3::updateCellsPosition(void) noexcept
    {
        Vector3f tmp = this->position;

        for (unsigned int z = 0; z < this->size.z || z < 1; z += 1) {
            tmp.z += this->cellSize.z / 2;
            for (unsigned int y = 0; y < this->size.y || y < 1; y += 1) {
                tmp.y += this->cellSize.y / 2;
                for (unsigned int x = 0; x < this->size.x || x < 1; x += 1) {
                    tmp.x += this->cellSize.x / 2;
                    this->cells[x + y * this->size.x + z * this->size.y * this->size.x].setPosition(tmp);
                    tmp.x += this->cellSize.x / 2;
                    tmp.x += this->cellGap.x;
                }
                tmp.y += this->cellSize.y / 2;
                tmp.y -= this->cellGap.y;
                tmp.x = this->position.x;
            }
            tmp.z += this->cellSize.z / 2;
            tmp.z += this->cellGap.z;
            tmp.y = this->position.y;
        }
    }
}
