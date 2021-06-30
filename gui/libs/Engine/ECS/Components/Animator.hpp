/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Animator
*/

#pragma once

#include <string_view>

#include "ECS/Components/IComponent.hpp"
#include "Graphics/ModelAnimator.hpp"

namespace ecs
{
    class Animator : public IComponent, public Graphics::ModelAnimator {
        public:
            Animator(std::string_view path, ecs::Model &model, bool is_looping = false) noexcept;
            Animator(const Animator &) noexcept = default;
            Animator(Animator &&) noexcept = default;
            ~Animator() noexcept = default;

            Animator &operator=(const Animator &) noexcept = default;
            Animator &operator=(Animator &&) noexcept = default;

            std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept override;
            void display(std::ostream& stream) const override;

        protected:
        private:
    };
} // namespace ecs