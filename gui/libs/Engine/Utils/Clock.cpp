/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock()
{
    this->start = std::chrono::high_resolution_clock::now();
}

Clock::~Clock()
{
}

void Clock::reset(void)
{
    start = std::chrono::high_resolution_clock::now();
}

float Clock::time(void)
{
    std::chrono::duration<float> timeElapsed;

    this->end = std::chrono::high_resolution_clock::now();
    timeElapsed = this->end - this->start;
    return timeElapsed.count();
}