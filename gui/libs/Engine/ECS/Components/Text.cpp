/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Text
*/

#include "Text.hpp"
#include "GameObject.hpp"

ecs::Text::Text(ecs::GameObject &gameObject, const std::string &text) noexcept : Graphics::Text{text}, m_tr{&gameObject.transform()}
{
}

void ecs::Text::draw() const noexcept
{
    auto previous_position = position;
    auto previous_size = size;
    ecs::Text *t = const_cast<ecs::Text *>(this);
    t->position += m_tr->getPosition();
    t->size *= m_tr->getScale().y;
    Graphics::Text::draw();
    t->position = previous_position;
    t->size = previous_size;
}

std::unique_ptr<ecs::IComponent> ecs::Text::copy(ecs::GameObject &copyOn) const noexcept
{
    auto res = std::make_unique<ecs::Text>(*this);
    res->m_tr = &copyOn.transform();
    return res;
}

void ecs::Text::display(std::ostream& stream) const
{
    stream << "Text:" << std::endl;
    stream << "\ttext: {" << text << "}" << std::endl;
    stream << "\tposition: " << position << std::endl;
    stream << "\tcolor: " << color << std::endl;
    stream << "\tsize: " << size << std::endl;
}