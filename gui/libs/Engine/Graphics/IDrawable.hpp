/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** IDrawable
*/

#pragma once

namespace ecs
{
    class Drawable2D;
    class Drawable3D;
} // namespace ecs

namespace Graphics
{
    class IDrawable2D
    {
    public:
        virtual ~IDrawable2D() noexcept = default;

    private:
        friend class Window;
        friend class ecs::Drawable2D;

        virtual void draw() const noexcept = 0;
    };

    class IDrawable3D
    {
        friend class Window;

    public:
        virtual ~IDrawable3D() noexcept = default;

    private:
        friend class Window;
        friend class ecs::Drawable3D;

        virtual void draw() const noexcept = 0;
    };
};
