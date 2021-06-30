/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** SoundHandler
*/

#include "SoundHandler.hpp"
#include "GameObject.hpp"
#include "ECS.hpp"
#include "Core.hpp"
#include "Utils.hpp"

SCRIPT_INIT(SoundHandler)

SoundHandler::SoundHandler(ecs::GameObject &gameObject) noexcept : ecs::Script{gameObject}
{
}

std::unique_ptr<ecs::Script> SoundHandler::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<SoundHandler>(copyOn);
}

void SoundHandler::Start() noexcept
{
    int inc = 0;
    m_icons[inc++] = gameObject.FindChildByName("Music");
    m_icons[inc++] = gameObject.FindChildByName("MusicMute");
    m_icons[inc++] = gameObject.FindChildByName("Sound");
    m_icons[inc++] = gameObject.FindChildByName("SoundMute");

    utils::Vector2f offset{ 20.0f, 20.0f };

    for (unsigned int i = 0; i < m_icons.size(); ++i) {
        auto &icon = *m_icons[i];
        if (i && i % 2) {
            icon.setActive(false);
        }
        auto size = icon.getComponent<ecs::Image>().getSize();
        if (i && !(i % 2)) {
            offset.x -= offset.x - size.x;
        }
        icon.transform().setPosition(icon.transform().getPosition() - size - offset);
        auto &btn = icon.getComponent<ecs::Button>();
        btn.setSize(size / icon.transform().getScale());
        btn.setCallback([this, i]() {
            SwitchIcon(i);
        });
    }
}

void SoundHandler::SwitchIcon(int clickedID) noexcept
{
    m_icons[clickedID]->setActive(false);
    m_icons[clickedID + ((clickedID + 1) % 2 ? 1 : -1)]->setActive(true);
    if (clickedID < 2) {
        zappy::SceneManager::ToggleMusicMute(!clickedID);
    }
}