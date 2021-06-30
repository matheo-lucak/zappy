/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** MusicPlayer
*/

#pragma once

#include "IComponent.hpp"
#include "Graphics/Music.hpp"

namespace ecs
{
    class MusicPlayer : public IComponent, public Graphics::Music {
        public:
            MusicPlayer(std::string_view filepath);
            MusicPlayer(const MusicPlayer &) noexcept = default;
            MusicPlayer(MusicPlayer &&) noexcept = default;
            ~MusicPlayer() noexcept = default;

            MusicPlayer &operator=(const MusicPlayer &) noexcept = default;
            MusicPlayer &operator=(MusicPlayer &&) noexcept = default;

            std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept override;
            void display(std::ostream& stream) const override;

        protected:
        private:
    };
} // namespace ecs
