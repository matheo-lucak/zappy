/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Clock
*/

#pragma once

#include <chrono>

class Clock {
    public:
        Clock();
        ~Clock();

        // reset the clock time
        void reset(void);

        // get the time elapsed since declaration or last reset
        float time(void);

    protected:
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::chrono::time_point<std::chrono::high_resolution_clock> end;
};
