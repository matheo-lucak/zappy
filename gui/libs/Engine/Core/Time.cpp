/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Time
*/

#include "Time.hpp"

std::chrono::time_point<std::chrono::steady_clock> indie::Time::m_launchTime{std::chrono::steady_clock::now()};
std::chrono::time_point<std::chrono::steady_clock> indie::Time::m_frameStart{m_launchTime};
std::chrono::nanoseconds indie::Time::m_lastFrameDuration{0};
double indie::Time::m_lastFrameDurationSec{0};

std::chrono::nanoseconds indie::Time::DeltaTime() noexcept
{
    return m_lastFrameDuration;
}

double indie::Time::DeltaTimeSec() noexcept
{
    return m_lastFrameDurationSec;
}

std::chrono::nanoseconds indie::Time::FullTime() noexcept
{
    return std::chrono::steady_clock::now() - m_launchTime;
}

double indie::Time::FullTimeSec() noexcept
{
    return std::chrono::duration<double>(std::chrono::steady_clock::now() - m_launchTime).count();
}

void indie::Time::StartFrame() noexcept
{
    m_lastFrameDuration = (std::chrono::steady_clock::now() - m_frameStart);
    m_lastFrameDurationSec = std::chrono::duration<double>(m_lastFrameDuration).count();
    m_frameStart = std::chrono::steady_clock::now();
}