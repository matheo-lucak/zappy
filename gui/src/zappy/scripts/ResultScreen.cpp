/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** ResultScreen
*/

#include <iostream>

#include "GameObject.hpp"
#include "ECS.hpp"
#include "Core.hpp"
#include "Utils.hpp"
#include "Player.hpp"

#include "ResultScreen.hpp"

SCRIPT_INIT(ResultScreen)

std::list<ecs::GameObject *> ResultScreen::m_players{};
int ResultScreen::m_idx{-1};

ResultScreen::ResultScreen(ecs::GameObject &gameObject) noexcept : ecs::Script{gameObject}
{
}

std::unique_ptr<ecs::Script> ResultScreen::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<ResultScreen>(copyOn);
}

void ResultScreen::Awake() noexcept
{
    if (m_idx == -1) {
        m_players = ecs::GameObject::FindGameObjectsByTag("Player");
        m_idx = 0;
    }
    SetPositions();
}

void ResultScreen::SetPositions() noexcept
{
    auto &panelImg = gameObject.getComponent<ecs::Image>();
    auto panelSize = panelImg.getSize();
    gameObject.transform().setPosition(gameObject.transform().getPosition() - (panelSize / 2));
    auto &roundBtn = *gameObject.FindChildByName("RoundCross");
    roundBtn.getComponent<ecs::Button>().setCallback([]() { indie::SceneManager::LoadScene(0); });
    auto &rbtnImg = roundBtn.getComponent<ecs::Image>();
    roundBtn.transform().setPosition({gameObject.transform().getPosition().x + panelSize.x - rbtnImg.getSize().x,
                                    gameObject.transform().getPosition().y, 0.0f});

    const utils::Vector2f start{ 50.0f, 210.0f };
    constexpr  float offset_step = 25.0f;
    utils::Vector2f offset{ 20.0f, offset_step };
    std::array<std::string, 4> names = {
        "BombUp",
        "ExtraLife",
        "FireUp",
        "SpeedUp",
    };
    std::array<int, 4> values = {
        3, 4, 0, 2
    };

    utils::Vector2f size;
    for (unsigned int i = 0; i < names.size(); ++i, offset.y += offset_step + size.y) {
        auto &gm = *gameObject.FindChildByName(names[i]);
        gm.transform().setPosition(gameObject.transform().getPosition() + start + offset);
        std::string t = "You picked it " + std::to_string(values[i]) + "x (+" + std::to_string(values[i] * 100) + ")";
        auto &text = gm.addComponent<ecs::Text>(gm, t);
        size = gm.getComponent<ecs::Image>().getSize();
        text.position = { size.x + offset_step, size.y * 0.20f };
        text.size = size.y * 0.70;
    }

    constexpr float arrowDistFromMid = 270.0f;
    auto &arrowLeft = *gameObject.FindChildByName("ArrowLeft");
    arrowLeft.transform().setPosition(gameObject.transform().getPosition() + utils::Vector2f{(panelSize.x / 2) - arrowDistFromMid, 50.0f});
    arrowLeft.getComponent<ecs::Button>().setCallback([this]() {
        if (m_idx == 0) {
            return;
        }
        --m_idx;
        SetData();
    });
    auto &arrowRight = *gameObject.FindChildByName("ArrowRight");
    arrowRight.transform().setPosition(gameObject.transform().getPosition() + utils::Vector2f{(panelSize.x / 2) + arrowDistFromMid - 35.0f, 50.0f});
    arrowRight.getComponent<ecs::Button>().setCallback([this]() {
        if (static_cast<std::size_t>(m_idx) == m_players.size() - 1) {
            return;
        }
        ++m_idx;
        SetData();
    });
    auto &playerName = gameObject.getComponent<ecs::Text>();
    playerName.text = "Player " + std::to_string(m_idx + 1);
    playerName.position = { panelSize.x / 2 - 80.0f, 50.0f };
    playerName.color = utils::Color::Black;
    playerName.size = 44;

    auto &score = *gameObject.FindChildByName("Score");
    score.transform().setPosition(gameObject.transform().getPosition());
    auto &scoreTxt = score.getComponent<ecs::Text>();
    scoreTxt.text = "Score: " + std::to_string(42);
    scoreTxt.position = { panelSize.x / 2 - 120.0f, 150.0f };
    scoreTxt.color = utils::Color::White;
    scoreTxt.size = 54;
    SetData();
}

void ResultScreen::SetData() noexcept
{
    std::array<std::string, 4> names = {
        "BombUp",
        "ExtraLife",
        "FireUp",
        "SpeedUp",
    };
    unsigned int totalScore = 0;
    int i = 0;
    Player *pl = nullptr;
    for (auto &node : m_players) {
        if (i == m_idx) {
            pl = &(*node).getScript<Player>();
        }
        ++i;
    }
    totalScore = pl->getNbBoxDestroyed() * 10;
    std::array<unsigned int, 4> values = {
        pl->getNbBombPowerUpsUsed(),
        pl->getNbSpeedPowerUpsUsed(),
        pl->getNbFirePowerUpsUsed(),
        pl->getNbExtraLifePowerUpsUsed(),
    };

    gameObject.getComponent<ecs::Text>().text = "Player " + std::to_string(m_idx + 1);
    for (unsigned int i = 0; i < names.size(); ++i) {
        auto &gm = *gameObject.FindChildByName(names[i]);
        std::string t = "You picked it " + std::to_string(values[i]) + "x (+" + std::to_string(values[i] * 100) + ")";
        gm.getComponent<ecs::Text>().text = t;
        totalScore += values[i] * 100;
    }
    gameObject.FindChildByName("Score")->getComponent<ecs::Text>().text = "Score: " + std::to_string(totalScore);
}

void ResultScreen::Update() noexcept
{
}
