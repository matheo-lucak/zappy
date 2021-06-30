/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Drawable3D
*/

#pragma once

#include "IComponent.hpp"
#include "Graphics/IDrawable.hpp"

namespace ecs
{
    class Drawable2D : public IComponent, public Graphics::IDrawable2D {
        public:
            Drawable2D(std::unique_ptr<Graphics::IDrawable2D> drawable);
            Drawable2D(const Drawable2D &) noexcept = delete;
            Drawable2D(Drawable2D &&) noexcept = default;
            ~Drawable2D() noexcept = default;

            Graphics::IDrawable2D &get() noexcept;
            Drawable2D &operator=(std::unique_ptr<Graphics::IDrawable2D> &&drawable) noexcept;

            Drawable2D &operator=(const Drawable2D &) noexcept = delete;
            Drawable2D &operator=(Drawable2D &&) noexcept = default;

            std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept override;
            void display(std::ostream& stream) const override;

        protected:
        private:
            std::unique_ptr<Graphics::IDrawable2D> m_drawable;

            void draw() const noexcept override;
    };

    class Drawable3D : public IComponent, public Graphics::IDrawable3D {
        public:
            Drawable3D(std::unique_ptr<Graphics::IDrawable3D> drawable);
            Drawable3D(const Drawable3D &) noexcept = delete;
            Drawable3D(Drawable3D &&) noexcept = default;
            ~Drawable3D() noexcept = default;

            Graphics::IDrawable3D &get() noexcept;
            Drawable3D &operator=(std::unique_ptr<Graphics::IDrawable3D> &&drawable) noexcept;

            Drawable3D &operator=(const Drawable3D &) noexcept = delete;
            Drawable3D &operator=(Drawable3D &&) noexcept = default;

            std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept override;
            void display(std::ostream& stream) const override;

        protected:
        private:
            std::unique_ptr<Graphics::IDrawable3D> m_drawable;

            void draw() const noexcept override;
    };
} // namespace ecs