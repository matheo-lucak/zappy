/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Sound
*/

#include <raylib.h>
#include <memory>
#include "Sound.hpp"

namespace Graphics
{
    Sound::Sound(std::string_view filepath)
    {
        m_sound = std::shared_ptr<::Sound>(new ::Sound{}, [](::Sound *a) { UnloadSound(*a); delete a; });
        *m_sound = ::LoadSound(filepath.data());
        setVolume(1.0f);
        m_pitch = 1.0f;
    }

    Sound::Sound(Graphics::Sound &&other) noexcept :
        m_sound{std::move(other.m_sound)},
        m_volume{other.m_volume},
        m_pitch{other.m_pitch}
    {
    }

    Sound::~Sound() noexcept
    {
    }

    float Sound::getVolume() const noexcept
    {
        return m_volume;
    }

    float Sound::getPitch() const noexcept
    {
        return m_pitch;
    }

    void Sound::setVolume(float volume) noexcept
    {
        ::SetSoundVolume(*m_sound, volume);
        m_volume = volume;
    }

    void Sound::setPitch(float pitch) noexcept
    {
        ::SetSoundPitch(*m_sound, m_pitch);
        m_pitch = pitch;
    }

    bool Sound::isPlaying() const noexcept
    {
        return ::IsSoundPlaying(*m_sound);
    }

    void Sound::play() const noexcept
    {
        ::PlaySound(*m_sound);
    }

    void Sound::pause() const noexcept
    {
        ::PauseSound(*m_sound);
    }

    void Sound::stop() const noexcept
    {
        ::StopSound(*m_sound);
    }

    void Sound::resume() const noexcept
    {
        ::ResumeSound(*m_sound);
    }
}
