/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Window
*/

#include <raylib.h>
#include "Window.hpp"
#include "ResourceInitialization.hpp"
#include "Camera.hpp"

namespace Graphics
{
    Window::Window(std::string_view title, int width, int height, int fps)
    {
        ::SetTraceLogLevel(LOG_WARNING | LOG_ERROR | LOG_FATAL);
        ::InitWindow(width, height, title.data());
        if (!::IsWindowReady())
            throw ResourceInitialization("Graphics: Unexpected error encountered during window initialization.");
        setFPS(fps);
        ::SetExitKey(KEY_NULL);
        ::SetCameraMode(Camera::camera.m_camera, ::CAMERA_FREE);
        toggleFullscreen(true);
    }

    Window::~Window() noexcept
    {
        ::CloseWindow();
    }

    bool Window::shouldClose() const noexcept
    {
        return ::WindowShouldClose();
    }

    int Window::getFPS() const noexcept
    {
        return ::GetFPS();
    }

    void Window::setFPS(int fps) noexcept
    {
        ::SetTargetFPS(fps);
    }

    Window::State Window::getState() const noexcept
    {
        if (::IsWindowFocused())
            return Window::State::FOCUSED;
        if (::IsWindowFullscreen())
            return Window::State::FULLSCREEN;
        if (::IsWindowHidden())
            return Window::State::HIDDEN;
        if (::IsWindowMaximized())
            return Window::State::MAXIMIZED;
        if (::IsWindowMinimized())
            return Window::State::MINIMIZED;
        return Window::State::UNKNOWN;
    }

    void Window::toggleDrawing(bool value) noexcept
    {
        if (value == true) {
            if (!Camera::camera.isLocked()) {
                ::UpdateCamera(&Camera::camera.m_camera);
            }
            ::BeginDrawing();
            ::ClearBackground(RAYWHITE);
        } else {
            ::EndDrawing();
        }
    }

    void Window::toggleDrawing3D(bool value) noexcept
    {
        if (value == true) {
            ::BeginMode3D(Camera::camera.m_camera);
        } else {
            ::EndMode3D();
        }
    }

    void Window::toggleFullscreen(bool value) const noexcept
    {
        bool isFull = ::IsWindowFullscreen();

        if (value != isFull) {
            ::ToggleFullscreen();
        }
    }

    void Window::draw(IDrawable2D &to_render)
    {
        to_render.draw();
    }

    void Window::draw(IDrawable3D &to_render)
    {
        to_render.draw();
    }
};
