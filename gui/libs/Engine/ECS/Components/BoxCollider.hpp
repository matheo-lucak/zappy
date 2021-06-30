/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** BoxCollider
*/

#ifndef BOXCOLLIDER_HPP_
#define BOXCOLLIDER_HPP_

#include <optional>

#include "Utils/Vector3.hpp"
#include "ECS/Components/IComponent.hpp"
#include "Utils/Rectangle3.hpp"

namespace ecs
{
    class Transform;

    class BoxCollider : public IComponent
    {
        public:
            BoxCollider(ecs::Transform &transform) noexcept;
            BoxCollider(const BoxCollider &other) noexcept = default;
            BoxCollider(BoxCollider &&other) noexcept = default;
            ~BoxCollider() noexcept override = default;

            /**
            * @brief Detect collision between with another Collider.
            * @param other Collider which you want to detect collision with.
            */
            std::optional<utils::Rectangle3> collide(const ecs::BoxCollider &other) noexcept;

            /**
            * @brief Return the center position of the BoxCollider as a Vector3.
            */
            utils::Vector3f const &getCenter(void) const noexcept;

            /**
            * @brief Return the size of the BoxCollider as a Vector3.
            */
            utils::Vector3f const &getSize(void) const noexcept;

            /**
            * @brief Change the center of the BoxCollider.
            * @param newCenter new center of the BoxCollider as a Rectangle3.
            */
            void setCenter(const utils::Vector3f &newCenter) noexcept;

            /**
            * @brief Change the size of the BoxCollider.
            * @param newSize new size of the BoxCollider as a Rectangle3.
            */
            void setSize(const utils::Vector3f &newSize) noexcept;

            /**
             * @brief Return the isStatic property. If static, the object is
             *        not supposed to move (ex: a wall).
             */
            bool isStatic() const noexcept;

            /**
             * @brief Change the isStatic property. If static, the object is
             *        not supposed to move (ex: a wall).
             */
            void setIsStatic(bool isStatic) noexcept;

            /**
             * @brief Return the isTrigger property. If trigger, no collision
             *        will happen, but OnTrigger will be called.
             */
            bool isTrigger() const noexcept;

            /**
             * @brief Change the isTrigger property. If trigger, no collision
             *        will happen, but OnTrigger will be called.
             */
            void setIsTrigger(bool isTrigger) noexcept;

            std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept override;
            void display(std::ostream& stream) const override;

        protected:
        private:
            ecs::Transform *m_tr;
            utils::Vector3f center;
            utils::Vector3f size;
            bool m_isStatic;
            bool m_isTrigger;
    };
}
#endif /* !BOXCOLLIDER_HPP_ */