/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** AudioContext
*/

#pragma once

namespace Graphics
{
    class AudioContext
    {
    public:
        AudioContext();
        ~AudioContext() noexcept;
    
        void setMasterVolume(float volume) const noexcept;
        int getNbSoundsPlaying(void) const noexcept;
    };
}
