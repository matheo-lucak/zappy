/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Cube
*/

#pragma once

#include <optional>
#include "IDrawable.hpp"
#include "Vector3.hpp"
#include "Color.hpp"
#include "Texture2D.hpp"

namespace Graphics
{
    class Cube : public IDrawable3D
    {
    protected:
        Texture2D *m_texture;

    public:
        utils::Vector3f position;
        float side_length;
        utils::Color color;

    public:
        Cube(const utils::Vector3f &position = utils::Vector3f::zero(), float side_length = 1.0f, utils::Color color = utils::Color{}) noexcept;
        Cube(float x, float y, float z, float side_length = 1.0f, utils::Color color = utils::Color{}) noexcept;
        Cube(const Cube &) noexcept = default;
        Cube(Cube &&) noexcept = default;
        ~Cube() noexcept = default;

        Cube &operator=(const Cube &) noexcept = default;
        Cube &operator=(Cube &&) noexcept = default;

        void setTexture(Texture2D *texture) noexcept;
        void removeTexture(void) noexcept;

    protected:
        void draw() const noexcept override;
    };
};
