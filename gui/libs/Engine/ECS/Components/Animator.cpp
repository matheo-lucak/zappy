/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Animator
*/

#include "ECS/Components/Animator.hpp"
#include "ECS/Components/Model.hpp"

ecs::Animator::Animator(std::string_view path, ecs::Model &model, bool is_looping) noexcept : Graphics::ModelAnimator{path, *model.m_model, is_looping}
{
}

std::unique_ptr<ecs::IComponent> ecs::Animator::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<ecs::Animator>(*this);
}

void ecs::Animator::display(std::ostream& stream) const
{
    stream << "Animator" << std::endl;
}