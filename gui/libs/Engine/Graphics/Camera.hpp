/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Camera
*/

#pragma once

#include "Utils/Vector3.hpp"
#include <raylib.h>

namespace Graphics
{
    class Camera
    {
            friend class Window;

        public:
            static Camera camera;

            Camera(const Camera &) noexcept = delete;
            Camera(Camera &&) noexcept = delete;
            ~Camera() noexcept = default;
    
            Camera &operator=(const Camera &) noexcept = delete;
            Camera &operator=(Camera &&) noexcept = delete;
    
            void setPosition(const utils::Vector3f &pos) noexcept;
            utils::Vector3f getPosition() const noexcept;
            void setTarget(const utils::Vector3f &target) noexcept;
            utils::Vector3f getTarget() const noexcept;
            void lock(bool value) noexcept;
            bool isLocked() const noexcept;

        public:
            ::Camera3D m_camera;

        private:
            bool m_locked;

            Camera() noexcept;
    };
} // namespace Graphicso