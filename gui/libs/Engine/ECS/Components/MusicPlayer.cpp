/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** MusicPlayer
*/

#include "MusicPlayer.hpp"

ecs::MusicPlayer::MusicPlayer(std::string_view filepath) : Graphics::Music{filepath}
{
}

std::unique_ptr<ecs::IComponent> ecs::MusicPlayer::copy(ecs::GameObject &copyOn) const noexcept
{
    (void)copyOn;
    return std::make_unique<ecs::MusicPlayer>(*this);
}

void ecs::MusicPlayer::display(std::ostream& stream) const
{
    stream << "Music Player: ";
    if (isPlaying()) {
        stream << "[X] Playing" << std::endl;
    } else {
        stream << "[ ] Paused";
    }
    stream << std::endl;
    stream << "\tplaying for: " << getTimePlayed();
    stream << "\tvolume: " << getVolume() << std::endl;
    stream << "\tpitch: " << getPitch() << std::endl;
}