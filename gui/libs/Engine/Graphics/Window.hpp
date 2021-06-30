/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Window
*/

#pragma once

#include <string_view>
#include "IDrawable.hpp"

namespace Graphics
{
    class Window
    {
    public:
        enum State
        {
            UNKNOWN = -1,
            FULLSCREEN,
            HIDDEN,
            MINIMIZED,
            MAXIMIZED,
            FOCUSED
        };

    public:
        Window(std::string_view title, int width, int height, int fps = 60);
        ~Window() noexcept;

        bool shouldClose() const noexcept;

        int getFPS() const noexcept;
        void setFPS(int fps) noexcept;
        State getState() const noexcept;

        void toggleDrawing(bool value) noexcept;
        void toggleDrawing3D(bool value) noexcept;
        void toggleFullscreen(bool value) const noexcept;

        void draw(IDrawable2D &to_render);
        void draw(IDrawable3D &to_render);
    };
};
