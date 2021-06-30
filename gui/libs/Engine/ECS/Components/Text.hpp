/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Text
*/

#pragma once

#include "IComponent.hpp"
#include "Graphics/Text.hpp"

namespace ecs
{
    class GameObject;
    class Transform;

    class Text : public IComponent, public Graphics::Text {
        public:
            Text(GameObject &gameObject, const std::string &text) noexcept;
            Text(const Text &) = default;
            Text(Text &&) noexcept = default;
            ~Text() noexcept = default;

            Text &operator=(const Text &) noexcept = default;
            Text &operator=(Text &&) noexcept = default;

            std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept override;
            void display(std::ostream& stream) const override;

        protected:
            void draw() const noexcept override;
        private:
            ecs::Transform *m_tr;
    };
} // namespace ecs