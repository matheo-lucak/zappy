/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Explosion
*/

#include <iostream>

#include "GameObject.hpp"
#include "ECS.hpp"
#include "Core.hpp"

#include "Explosion.hpp"
#include "Player.hpp"

SCRIPT_INIT(Explosion)

Explosion::Explosion(ecs::GameObject &gameObject, float lifeTime) noexcept :
    ecs::Script{gameObject},
    m_lifeTime(lifeTime)
{
}

std::unique_ptr<ecs::Script> Explosion::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<Explosion>(copyOn);
}

void Explosion::Awake() noexcept
{
    m_clock.reset();
}

void Explosion::Update() noexcept
{
    if (m_clock.time() > m_lifeTime) {
       ecs::GameObject::Destroy(gameObject);
    }
}

void Explosion::OnTrigger(ecs::GameObject &other) noexcept
{
    if (other.getTag() == "Player") {
        auto &player = other.getScript<Player>();

        player.takeDamage();
    }

}
