/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Drawable3D
*/

#include "Drawable.hpp"

ecs::Drawable2D::Drawable2D(std::unique_ptr<Graphics::IDrawable2D> drawable) : m_drawable{std::move(drawable)}
{
    if (!m_drawable) {
        throw std::runtime_error{"Drawable2D object must be not null"};
    }
}

Graphics::IDrawable2D &ecs::Drawable2D::get() noexcept
{
    return *m_drawable;
}

ecs::Drawable2D &ecs::Drawable2D::operator=(std::unique_ptr<Graphics::IDrawable2D> &&drawable) noexcept
{
    m_drawable = std::move(drawable);
    return *this;
}

void ecs::Drawable2D::draw() const noexcept
{
    m_drawable->draw();
}

std::unique_ptr<ecs::IComponent> ecs::Drawable2D::copy(ecs::GameObject &copyOn) const noexcept
{
    return nullptr;
}

void ecs::Drawable2D::display(std::ostream& stream) const
{
    stream << "Drawable2D";
}

ecs::Drawable3D::Drawable3D(std::unique_ptr<Graphics::IDrawable3D> drawable) : m_drawable{std::move(drawable)}
{
    if (!m_drawable) {
        throw std::runtime_error{"Drawable3D object must be not null"};
    }
}

Graphics::IDrawable3D &ecs::Drawable3D::get() noexcept
{
    return *m_drawable;
}

ecs::Drawable3D &ecs::Drawable3D::operator=(std::unique_ptr<Graphics::IDrawable3D> &&drawable) noexcept
{
    m_drawable = std::move(drawable);
    return *this;
}

void ecs::Drawable3D::draw() const noexcept
{
    m_drawable->draw();
}

std::unique_ptr<ecs::IComponent> ecs::Drawable3D::copy(ecs::GameObject &copyOn) const noexcept
{
    return nullptr;
}

void ecs::Drawable3D::display(std::ostream& stream) const
{
    stream << "Drawable3D";
}