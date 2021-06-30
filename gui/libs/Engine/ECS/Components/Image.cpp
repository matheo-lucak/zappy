/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Image
*/

#include "Image.hpp"
#include "GameObject.hpp"

ecs::Image::Image(ecs::GameObject &gameObject, const std::string &path) noexcept : Graphics::Texture2D{path}, m_tr{&gameObject.transform()}
{
}

void ecs::Image::draw() const noexcept
{
    auto pos = position;
    float scl = scale;
    ecs::Image *t = const_cast<ecs::Image *>(this);
    t->position += m_tr->getPosition();
    t->scale *= m_tr->getScale().x;
    Graphics::Texture2D::draw();
    t->position = pos;
    t->scale = scl;
}

utils::Vector2f ecs::Image::getSize() const noexcept
{
    return Graphics::Texture2D::getSize() * m_tr->getScale();
}

std::unique_ptr<ecs::IComponent> ecs::Image::copy(ecs::GameObject &copyOn) const noexcept
{
    auto res = std::make_unique<ecs::Image>(*this);
    res->m_tr = &copyOn.transform();
    return res;
}

void ecs::Image::display(std::ostream& stream) const
{
    stream << "Image:" << std::endl;
    stream << "\tposition: " << position << std::endl;
}