/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Time
*/

#pragma once

#include <chrono>

namespace indie
{
    class Application;

    class Time {
        public:
            Time() = delete;
            ~Time() = delete;

            static std::chrono::nanoseconds DeltaTime() noexcept;
            static double DeltaTimeSec() noexcept;
            static std::chrono::nanoseconds FullTime() noexcept;
            static double FullTimeSec() noexcept;

        private:
            static std::chrono::time_point<std::chrono::steady_clock> m_launchTime;
            static std::chrono::time_point<std::chrono::steady_clock> m_frameStart;
            static std::chrono::nanoseconds m_lastFrameDuration;
            static double m_lastFrameDurationSec;

            static void StartFrame() noexcept;

            friend class Application;
    };
} // namespace indie

