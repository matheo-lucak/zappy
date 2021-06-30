/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Sound
*/

#pragma once

#include <string_view>
#include <raylib.h>
#include <memory>

namespace Graphics
{
    class Sound
    {
    protected:
        std::shared_ptr<::Sound> m_sound;
        float m_volume;
        float m_pitch;

    public:
        Sound(std::string_view filepath);
        Sound(const Graphics::Sound &) noexcept = default;
        Sound(Graphics::Sound &&other) noexcept;
        ~Sound() noexcept;

        Sound &operator=(const Sound &) noexcept = default;
        Sound &operator=(Sound &&) noexcept = default;

        float getVolume() const noexcept;
        float getPitch() const noexcept;
        void setVolume(float volume) noexcept;
        void setPitch(float pitch) noexcept;

        bool isPlaying() const noexcept;

        void play() const noexcept;
        void pause() const noexcept;
        void stop() const noexcept;
        void resume() const noexcept;
    };
}
