/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Text
*/

#pragma once

#include <string>
#include "IDrawable.hpp"
#include "Color.hpp"
#include "Vector2.hpp"

namespace Graphics
{
    class Text : public IDrawable2D
    {
    public:
        std::string text;
        utils::Vector2f position;
        utils::Color color;
        float size;

    public:
        Text(const std::string &text, const utils::Vector2f &position = utils::Vector2f::zero(), const utils::Color &color = utils::Color::White, float size = 1.0f) noexcept;
        virtual ~Text() noexcept override = default;

    protected:
        void draw() const noexcept override;
    };
};
