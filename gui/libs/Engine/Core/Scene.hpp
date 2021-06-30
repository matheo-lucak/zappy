/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Scene
*/

#pragma once

#include <memory>
#include <vector>

#include "ECS/Components/Animator.hpp"
#include "ECS/Components/BoxCollider.hpp"
#include "ECS/Components/Button.hpp"
#include "ECS/Components/MusicPlayer.hpp"
#include "ECS/GameObject.hpp"
#include "Graphics/IDrawable.hpp"

namespace zappy
{
    class Scene {
        public:
            Scene() noexcept;
            ~Scene() noexcept = default;

            bool isMusicMuted;
            using ObjectList = std::vector<std::unique_ptr<ecs::GameObject>>;
            ObjectList objects;
            ObjectList prefabs;
            std::vector<std::reference_wrapper<ecs::GameObject>> commissioning;
            std::vector<std::pair<std::reference_wrapper<ecs::GameObject>, std::reference_wrapper<ecs::BoxCollider>>> colliders;
            std::vector<std::pair<std::reference_wrapper<ecs::GameObject>, std::reference_wrapper<ecs::Button>>> buttons;
            std::vector<std::pair<std::reference_wrapper<ecs::GameObject>, std::reference_wrapper<ecs::MusicPlayer>>> musics;
            std::vector<std::pair<std::reference_wrapper<ecs::GameObject>, std::reference_wrapper<ecs::Animator>>> animators;
            std::vector<std::pair<std::reference_wrapper<ecs::GameObject>, std::reference_wrapper<Graphics::IDrawable2D>>> drawable2d;
            std::vector<std::pair<std::reference_wrapper<ecs::GameObject>, std::reference_wrapper<Graphics::IDrawable3D>>> drawable3d;
            std::vector<std::reference_wrapper<ecs::GameObject>> deleting;
    };
} // namespace zappy