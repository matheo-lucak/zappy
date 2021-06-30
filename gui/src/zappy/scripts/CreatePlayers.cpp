/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** CreatePlayers
*/

#include "CreatePlayers.hpp"
#include "GameObject.hpp"
#include "ECS.hpp"
#include "Core.hpp"
#include "Player.hpp"

SCRIPT_INIT(CreatePlayers)

CreatePlayers::CreatePlayers(ecs::GameObject &gameObject) noexcept : ecs::Script{gameObject}
{
}

std::unique_ptr<ecs::Script> CreatePlayers::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<CreatePlayers>(copyOn);
}

void CreatePlayers::Start() noexcept
{
    constexpr int nbPlayers = 2;
    auto &playerBp = ecs::GameObject::FindPrefabByName("Player");
    std::string modelPath  {"../src/assets/models/player/player1.obj"};
    std::string texturePath{"../src/assets/models/player/player1.mtl"};
    std::array<utils::Vector3f, 4> pos = {{
        { 3.0f, 2.0f, 3.0f },
        { 59.0f, 2.0f, 59.0f },
        { 59.0f, 2.0f, 3.0f },
        { 3.0f, 2.0f, 59.0f },
    }};

    for (int i = 0; i < nbPlayers; ++i) {
        auto &gm = ecs::GameObject::Instantiate(playerBp);
        gm.transform().setPosition(pos[i]);
        modelPath[34] = (char)(i + '1');
        texturePath[34] = (char)(i + '1');
        auto &md = gm.addComponent<ecs::Model>(gm, modelPath, texturePath);
        md.rotationAngle() = 90;
        md.setRotation(utils::Vector3f{ -90.0f, 0.0f, 0.0f});
        gm.getScript<Player>().setPlayerID(i);
    }
    Graphics::Camera::camera.lock(true);
    Graphics::Camera::camera.setPosition({ 30.0f, 60.0f, -10.0f });
    Graphics::Camera::camera.setTarget(  { 30.0f,  2.0f,  25.0f });
}

void CreatePlayers::Update() noexcept
{
    if (Graphics::Input::isKeyPressed(Graphics::Keycode::ESCAPE)) {
        indie::SceneManager::QuitApplication();
    }
}