/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Button
*/

#include "Button.hpp"
#include "Transform.hpp"
#include "GameObject.hpp"
#include "ECS/Components/Image.hpp"
#include "Graphics/Mouse.hpp"

ecs::Button::Button(ecs::GameObject &gameObject) noexcept : m_tr{&gameObject.transform()}, m_callback{nullptr}, m_size{1}
{
    if (gameObject.hasComponent<ecs::Image>()) {
        m_img = &gameObject.getComponent<ecs::Image>();
    }
    colorHover   = { 220, 220, 220, 255 };
    colorPressed = { 180, 180, 180, 255 };
    colorHold    = { 200, 200, 200, 255 };
}

void ecs::Button::update() noexcept
{
    if (!isHover(Graphics::Mouse::getPosition())) {
        m_img->color = utils::Color::White;
        return;
    }
    if (Graphics::Mouse::isButtonDown(Graphics::MouseButton::BUTTON_LEFT)) {
        if (m_img) {
            m_img->color = colorHold;
        }
    } else if (Graphics::Mouse::isButtonReleased(Graphics::MouseButton::BUTTON_LEFT)) {
        (*this)();
        if (m_img) {
            m_img->color = colorPressed;
        }
    } else if (m_img) {
        m_img->color = colorHover;
    }
}

void ecs::Button::setCallback(std::nullptr_t) noexcept
{
    m_callback = nullptr;
}

void ecs::Button::operator()() const
{
    if (m_callback) {
        m_callback();
    }
}

void ecs::Button::setSize(const utils::Vector2f &size) noexcept
{
    m_size = size;
}

utils::Vector2f const &ecs::Button::getSize() const noexcept
{
    return m_size;
}

void ecs::Button::setOrigin(const utils::Vector2f &origin) noexcept
{
    m_origin = origin;
}

utils::Vector2f const &ecs::Button::getOrigin() const noexcept
{
    return m_origin;
}

bool ecs::Button::isHover(const utils::Vector2f &pos) const noexcept
{
    const auto &p = m_tr->getPosition();
    auto size = m_size * m_tr->getScale();

    if ((p.x - m_origin.x) <= pos.x && pos.x <= (p.x + size.x - m_origin.x)
    &&  (p.y - m_origin.y) <= pos.y && pos.y <= (p.y + size.y - m_origin.y)) {
        return true;
    }
    return false;
}

std::unique_ptr<ecs::IComponent> ecs::Button::copy(ecs::GameObject &copyOn) const noexcept
{
    auto res = std::make_unique<ecs::Button>(*this);
    res->m_tr = &copyOn.transform();
    if (copyOn.hasComponent<ecs::Image>()) {
        res->m_img = &copyOn.getComponent<ecs::Image>();
    }
    return std::move(res);
}

void ecs::Button::display(std::ostream& stream) const
{
    std::cout << "Button" << std::endl;
}