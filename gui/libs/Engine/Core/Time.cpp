/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Time
*/

#include "Time.hpp"

std::chrono::time_point<std::chrono::steady_clock> zappy::Time::m_launchTime{std::chrono::steady_clock::now()};
std::chrono::time_point<std::chrono::steady_clock> zappy::Time::m_frameStart{m_launchTime};
std::chrono::nanoseconds zappy::Time::m_lastFrameDuration{0};
double zappy::Time::m_lastFrameDurationSec{0};

std::chrono::nanoseconds zappy::Time::DeltaTime() noexcept
{
    return m_lastFrameDuration;
}

double zappy::Time::DeltaTimeSec() noexcept
{
    return m_lastFrameDurationSec;
}

std::chrono::nanoseconds zappy::Time::FullTime() noexcept
{
    return std::chrono::steady_clock::now() - m_launchTime;
}

double zappy::Time::FullTimeSec() noexcept
{
    return std::chrono::duration<double>(std::chrono::steady_clock::now() - m_launchTime).count();
}

void zappy::Time::StartFrame() noexcept
{
    m_lastFrameDuration = (std::chrono::steady_clock::now() - m_frameStart);
    m_lastFrameDurationSec = std::chrono::duration<double>(m_lastFrameDuration).count();
    m_frameStart = std::chrono::steady_clock::now();
}