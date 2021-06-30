/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Image
*/

#pragma once

#include "IComponent.hpp"
#include "Graphics/Texture2D.hpp"

namespace ecs
{
    class GameObject;
    class Transform;

    class Image : public IComponent, public Graphics::Texture2D {
        public:
            Image(GameObject &gameObject, const std::string &Image) noexcept;
            Image(const Image &) noexcept = default;
            Image(Image &&) noexcept = default;
            ~Image() noexcept = default;

            Image &operator=(const Image &) noexcept = default;
            Image &operator=(Image &&) noexcept = default;

            std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept override;
            void display(std::ostream& stream) const override;

            utils::Vector2f getSize() const noexcept override;

        protected:
            void draw() const noexcept override;
        private:
            ecs::Transform *m_tr;
    };
} // namespace ecs