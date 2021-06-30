/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** ModelAnimator
*/

#pragma once

#include <string_view>
#include <raylib.h>
#include "Model.hpp"

namespace Graphics
{
    class ModelAnimator
    {
    protected:
        Model *m_model;
        ::ModelAnimation *m_animations;
        int m_nb_animations;
        int m_animation_index;
        int m_frame_index;

    public:
        bool is_looping;

    public:
        ModelAnimator(std::string_view filepath, Model &model, bool is_looping = false) noexcept;
        ModelAnimator(const ModelAnimator &) noexcept = default;
        ModelAnimator(ModelAnimator &&) noexcept;
        ~ModelAnimator() noexcept;

        ModelAnimator &operator=(const ModelAnimator &) noexcept = default;
        ModelAnimator &operator=(ModelAnimator &&) noexcept = default;

        int getNbAnimations(void) const noexcept;
        bool setCurrentAnimation(int index) noexcept;

        bool update(void) noexcept;
        void resetCurrentFrame(void) noexcept;
        void restart(void) noexcept;
    };
}