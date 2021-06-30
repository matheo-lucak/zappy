/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** AudioContext
*/

#include <raylib.h>
#include "AudioContext.hpp"
#include "ResourceInitialization.hpp"

namespace Graphics
{
    AudioContext::AudioContext()
    {
        ::InitAudioDevice();
        if (!::IsAudioDeviceReady())
            throw ResourceInitialization("Graphics: Unexpected error encountered during audio context initialization.");
    }

    AudioContext::~AudioContext() noexcept
    {
        ::CloseAudioDevice();
    }

    void AudioContext::setMasterVolume(float volume) const noexcept
    {
        ::SetMasterVolume(volume);
    }

    int AudioContext::getNbSoundsPlaying(void) const noexcept
    {
        return ::GetSoundsPlaying();
    }
}
