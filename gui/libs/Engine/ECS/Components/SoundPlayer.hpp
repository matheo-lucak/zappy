/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** SoundPlayer
*/

#pragma once

#include "IComponent.hpp"
#include "Graphics/Sound.hpp"

namespace ecs
{
    class SoundPlayer : public IComponent, public Graphics::Sound {
        public:
            SoundPlayer(std::string_view filepath);
            SoundPlayer(const SoundPlayer &) noexcept = default;
            SoundPlayer(SoundPlayer &&) noexcept = default;
            ~SoundPlayer() noexcept = default;

            SoundPlayer &operator=(const SoundPlayer &) noexcept = default;
            SoundPlayer &operator=(SoundPlayer &&) noexcept = default;

            std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept override;
            void display(std::ostream& stream) const override;

        protected:
        private:
    };
} // namespace ecs
