/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Music
*/

#pragma once

#include <string_view>
#include <raylib.h>

namespace Graphics
{
    class Music
    {
    protected:
        ::Music m_music;
        float m_volume;
        float m_pitch;

    public:
        Music(std::string_view filepath) noexcept;
        Music(const Graphics::Music &) noexcept = default;
        Music(Graphics::Music &&other) noexcept;
        ~Music() noexcept;

        Music &operator=(const Music &) noexcept = default;
        Music &operator=(Music &&other) noexcept;

        float getVolume() const noexcept;
        float getPitch() const noexcept;
        void setVolume(float volume) noexcept;
        void setPitch(float pitch) noexcept;

        void toggleLooping(bool value) noexcept;

        bool isPlaying() const noexcept;
        float getTimeLength() const noexcept;
        float getTimePlayed() const noexcept;

        void update() const noexcept;
        void play() const noexcept;
        void stop() const noexcept;
        void pause() const noexcept;
        void resume() const noexcept;
    };
}
