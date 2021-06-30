/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Music
*/

#include "Music.hpp"
#include "ResourceInitialization.hpp"

namespace Graphics
{
    Music::Music(std::string_view filepath) noexcept
    {
        m_music = ::LoadMusicStream(filepath.data());
        setVolume(1.0f);
        setPitch(1.0f);
    }

    Music::Music(Graphics::Music &&other) noexcept : m_music{other.m_music}, m_volume{other.m_volume}, m_pitch{other.m_pitch}
    {
        other.m_music = {};
    }

    Music::~Music() noexcept
    {
        ::UnloadMusicStream(m_music);
    }

    Music &Music::operator=(Music &&other) noexcept
    {
        m_music = other.m_music;
        m_volume = other.m_volume;
        m_pitch = other.m_pitch;
        other.m_music = {};
        return *this;
    }

    float Music::getVolume() const noexcept
    {
        return m_volume;
    }

    float Music::getPitch() const noexcept
    {
        return m_pitch;
    }

    void Music::setVolume(float volume) noexcept
    {
        ::SetMusicVolume(m_music, volume);
        m_volume = volume;
    }

    void Music::setPitch(float pitch) noexcept
    {
        ::SetMusicPitch(m_music, pitch);
        m_pitch = pitch;
    }

    void Music::toggleLooping(bool value) noexcept
    {
        m_music.looping = value;
    }

    bool Music::isPlaying() const noexcept
    {
        return ::IsMusicStreamPlaying(m_music);
    }

    float Music::getTimeLength() const noexcept
    {
        return ::GetMusicTimeLength(m_music);
    }

    float Music::getTimePlayed() const noexcept
    {
        return ::GetMusicTimePlayed(m_music);
    }

    void Music::update() const noexcept
    {
        ::UpdateMusicStream(m_music);
    }

    void Music::play() const noexcept
    {
        ::PlayMusicStream(m_music);
    }
    
    void Music::stop() const noexcept
    {
        ::StopMusicStream(m_music);
    }

    void Music::pause() const noexcept
    {
        ::PauseMusicStream(m_music);
    }

    void Music::resume() const noexcept
    {
        ::ResumeMusicStream(m_music);
    }
}
