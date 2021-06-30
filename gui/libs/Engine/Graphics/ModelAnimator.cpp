/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** ModelAnimator
*/

#include <stdlib.h>
#include "ModelAnimator.hpp"

namespace Graphics
{
    ModelAnimator::ModelAnimator(std::string_view filepath, Model &model, bool is_looping) noexcept :
        m_model{&model},
        m_animations{nullptr},
        m_nb_animations{0},
        m_animation_index{0},
        m_frame_index{0},
        is_looping{is_looping}
    {
        m_animations = ::LoadModelAnimations(filepath.data(), &m_nb_animations);
    }

    ModelAnimator::ModelAnimator(ModelAnimator &&other) noexcept :
        m_model{other.m_model},
        m_animations{other.m_animations},
        m_nb_animations{other.m_nb_animations},
        m_animation_index{other.m_animation_index},
        m_frame_index{other.m_frame_index},
        is_looping{other.is_looping}
    {
        other.m_model = nullptr;
        other.m_animations = nullptr;
    }

    ModelAnimator::~ModelAnimator() noexcept
    {
        if (m_animations) {
            ::UnloadModelAnimations(m_animations, m_nb_animations);
        }
    }

    int ModelAnimator::getNbAnimations(void) const noexcept
    {
        return m_nb_animations;
    }

    bool ModelAnimator::setCurrentAnimation(int index) noexcept
    {
        if (index < 0 || index >= getNbAnimations())
            return false;
        m_animation_index = index;
        resetCurrentFrame();
        return true;
    }

    bool ModelAnimator::update(void) noexcept
    {
        m_frame_index += 1;
        if (m_frame_index >= m_animations[m_animation_index].frameCount) {
            if (is_looping)
                m_frame_index = 0;
            else
                return false;
        }
        ::UpdateModelAnimation(m_model->m_model, m_animations[m_animation_index], m_frame_index);
        return true;
    }

    void ModelAnimator::resetCurrentFrame(void) noexcept
    {
        m_frame_index = 0;
    }

    void ModelAnimator::restart(void) noexcept
    {
        resetCurrentFrame();
        update();
    }
}
