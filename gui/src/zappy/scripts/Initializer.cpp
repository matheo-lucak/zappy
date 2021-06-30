/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Initializer
*/

#include "Initializer.hpp"
#include "GameObject.hpp"
#include "ECS.hpp"
#include "Core.hpp"
#include "Utils.hpp"
#include "Bomb.hpp"

SCRIPT_INIT(Initializer)

Initializer::Initializer(ecs::GameObject &gameObject) noexcept : ecs::Script{gameObject}
{
}

std::unique_ptr<ecs::Script> Initializer::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<Initializer>(copyOn);
}

void Initializer::Start() noexcept
{
    gameObject.FindChildByName("Title")->setActive(false);
    auto &bomb = gameObject.Instantiate(gameObject.FindPrefabByName("Bomb"), 0);
    bomb.getScript<Bomb>().detonationTime  = 10;
}

void Initializer::CreateMenu() noexcept
{
    std::cout << "Creating Menu" << std::endl;
    auto &btn = ecs::GameObject::FindPrefabByName("Button");
    auto btnSize = btn.getComponent<ecs::Image>().getSize();
    btn.transform().setPosition(btn.transform().getPosition() - (btnSize / 2));
    float offset = 30;
    utils::Vector3f pos;

    {
        auto &play = ecs::GameObject::Instantiate(btn);
        pos = play.transform().getPosition();
        pos.x -= (btnSize.x / 2) + offset;
        play.transform().setPosition(pos);
        play.getComponent<ecs::Text>().text = "Play";
        play.getComponent<ecs::Button>().setCallback([]() {
            indie::SceneManager::LoadScene(indie::SceneManager::getActiveSceneBuildIdx() + 1);
        });
    }

    {
        auto &quit = ecs::GameObject::Instantiate(btn);
        pos = quit.transform().getPosition();
        pos.x += (btnSize.x / 2) + offset;
        quit.transform().setPosition(pos);
        quit.getComponent<ecs::Text>().text = "Quit";
        quit.getComponent<ecs::Button>().setCallback([]() {
            indie::SceneManager::QuitApplication();
        });
    }

    {
        auto &title = *gameObject.FindChildByName("Title");
        pos = title.transform().getPosition();
        pos.x -= title.getComponent<ecs::Image>().getSize().x * 0.40f;
        title.transform().setPosition(pos);
        title.setActive(true);
    }
}

void Initializer::Update() noexcept
{
    if (Graphics::Input::isKeyPressed(Graphics::Keycode::ESCAPE)) {
        indie::SceneManager::QuitApplication();
    }
}