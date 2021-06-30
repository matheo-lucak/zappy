/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** SoundPlayer
*/

#include "SoundPlayer.hpp"

ecs::SoundPlayer::SoundPlayer(std::string_view filepath) : Graphics::Sound{filepath}
{
}

std::unique_ptr<ecs::IComponent> ecs::SoundPlayer::copy(ecs::GameObject &copyOn) const noexcept
{
    (void)copyOn;
    return std::make_unique<ecs::SoundPlayer>(*this);
}

void ecs::SoundPlayer::display(std::ostream& stream) const
{
    stream << "Sound Player: ";
    if (isPlaying()) {
        stream << "[X] Playing";
    } else {
        stream << "[ ] Paused";
    }
    stream << std::endl;
    stream << "\tvolume: " << getVolume() << std::endl;
}