/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Model
*/

#pragma once

#include <string_view>
#include <memory>
#include <string>

#include "ECS/Components/IComponent.hpp"
#include "Graphics/IDrawable.hpp"
#include "Graphics/Model.hpp"
#include "Graphics/Texture2D.hpp"

namespace ecs
{
    class GameObject;
    class Transform;
    class Animator;

    class Model : public IComponent, public Graphics::IDrawable3D {
        public:
            Model(ecs::GameObject &gameObject, std::string_view path) noexcept;
            Model(ecs::GameObject &gameObject, std::string_view path, std::string_view texturePath) noexcept;
            Model(const Model &other) noexcept;
            Model(Model &&) noexcept;
            ~Model() noexcept = default;

            Model &operator=(const Model &) noexcept;
            Model &operator=(Model &&) noexcept;

            std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept override;
            void display(std::ostream& stream) const override;

            utils::Vector3f &position() noexcept;
            utils::Vector3f &rotationAxis() noexcept;
            float &rotationAngle() noexcept;
            utils::Vector3f &scaling() noexcept;
            utils::Color &color() noexcept;

            void setRotation(utils::Vector3f);

        protected:
            void draw() const noexcept override;
        private:
            ecs::Transform *m_tr;
            std::shared_ptr<Graphics::Model> m_model;
            std::shared_ptr<Graphics::Texture2D> m_texture;

            friend ecs::Animator;
    };
} // namespace ecs