/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Player
*/

#include <iostream>

#include "GameObject.hpp"
#include "ECS.hpp"
#include "Core.hpp"
#include "Utils.hpp"

#include "ResultScreen.hpp"
#include "Player.hpp"
#include "Bomb.hpp"

SCRIPT_INIT(Player)

Player::Player(ecs::GameObject &gameObject) noexcept : ecs::Script{gameObject}
{
    std::cout << "Player was build" << std::endl;
}

std::unique_ptr<ecs::Script> Player::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<Player>(copyOn);
}

void Player::setPlayerID(int id) noexcept
{
    m_id = id;
    std::array<std::array<Graphics::Keycode, 5>, 2> keys = {{
        { Graphics::Keycode::UP, Graphics::Keycode::DOWN, Graphics::Keycode::LEFT, Graphics::Keycode::RIGHT, Graphics::Keycode::P},
        { Graphics::Keycode::W,  Graphics::Keycode::S,    Graphics::Keycode::A,    Graphics::Keycode::D,     Graphics::Keycode::X},
    }};
    m_kup    = keys[m_id][0];
    m_kdown  = keys[m_id][1];
    m_kleft  = keys[m_id][2];
    m_kright = keys[m_id][3];
    m_kbomb  = keys[m_id][4];
}

void Player::Start() noexcept
{
    std::cout << "Player Start" << std::endl;
    m_model = &gameObject.getComponent<ecs::Model>();
    m_model->setRotation(utils::Vector3f{ 5.0f, 1.0f, 0.0f});
}

void Player::Awake() noexcept
{
    std::cout << "Player Awake" << std::endl;
    ecs::GameObject *map = ecs::GameObject::FindGameObjectByName("Map");

    if (map) {
        m_map = &map->getScript<Map>();
    }
}

void Player::Update() noexcept
{
    if (m_alive) {
        HandleMovement();
        HandleBombs();
    }
}

float Player::getSpeed() const noexcept
{
    return m_speed;
}

void Player::setSpeed(float value) noexcept
{
    m_speed = value;
}

unsigned int Player::getBlastRange() const noexcept
{
    return m_blast_range;
}

void Player::setBlastRange(unsigned int value) noexcept
{
    m_blast_range = value;
}

unsigned int Player::getHP() const noexcept
{
    return m_hp;
}

void Player::setHP(unsigned int value) noexcept
{
    m_hp = value;
}

unsigned int Player::getNbBombPowerUpsUsed() const noexcept
{
    return m_bomb_powerups_used;
}

void Player::increaseNbBombPowerUpsUsed() noexcept
{
    m_bomb_powerups_used += 1;
}

unsigned int Player::getNbSpeedPowerUpsUsed() const noexcept
{
    return m_speed_powerups_used;
}

void Player::increaseNbSpeedPowerUpsUsed() noexcept
{
    m_speed_powerups_used += 1;
}

unsigned int Player::getNbFirePowerUpsUsed() const noexcept
{
    return m_fire_powerups_used;
}

void Player::increaseNbFirePowerUpsUsed() noexcept
{
    m_fire_powerups_used += 1;
}

unsigned int Player::getNbExtraLifePowerUpsUsed() const noexcept
{
    return m_extralife_powerups_used;
}

void Player::increaseNbExtraLifePowerUpsUsed() noexcept
{
    m_extralife_powerups_used += 1;
}

unsigned int Player::getNbBoxDestroyed() const noexcept
{
    return m_box_destroyed;
}

void Player::increaseNbBoxDestroyed() noexcept
{
    m_box_destroyed += 1;
}

bool Player::addBomb(bool add_slot) noexcept
{
    if (!add_slot && m_free_bomb_nb >= m_max_bomb_nb)
        return false;
    m_free_bomb_nb += 1;
    if (add_slot)
        m_max_bomb_nb += 1;
    return true;
}

void Player::HandleMovement() noexcept
{
    utils::Vector3f pos = gameObject.transform().getPosition();

    if (Graphics::Input::isKeyDown(m_kup)) {
        pos += pos.forward() * m_speed * indie::Time::DeltaTimeSec();
        m_model->setRotation(utils::Vector3f{ -90.0f, 0.0f, 0.0f});
    }
    if (Graphics::Input::isKeyDown(m_kdown)) {
        pos += pos.back() * m_speed * indie::Time::DeltaTimeSec();
        m_model->setRotation(utils::Vector3f{ -90.0f, 180.0f, 0.0f});
    }
    if (Graphics::Input::isKeyDown(m_kleft)) {
        pos += pos.right() * m_speed * indie::Time::DeltaTimeSec();
        m_model->setRotation(utils::Vector3f{ -90.0f, -90.0f, 0.0f});
    }
    if (Graphics::Input::isKeyDown(m_kright)) {
        pos += pos.left() * m_speed * indie::Time::DeltaTimeSec();
        m_model->setRotation(utils::Vector3f{ -90.0f, 90.0f, 0.0f});
    }
    gameObject.transform().setPosition(pos);
}

void Player::HandleBombs() noexcept
{
    if (m_free_bomb_nb < m_max_bomb_nb &&
        m_bomb_reloading_clock.time() > m_bomb_reloading_time) {
        m_free_bomb_nb += 1;
        m_bomb_reloading_clock.reset();
    }

    if (Graphics::Input::isKeyPressed(m_kbomb) &&
        m_free_bomb_nb > 0) {
        if (m_map) {
            utils::Grid3 &grid = m_map->getGrid();
            utils::Vector3f pos = gameObject.transform().getPosition();
            utils::Vector3u coords = grid.posToCoord(pos);

            if (grid.isValidCoords(coords)) {
                utils::Vector3f new_pos = grid.coordToPos(coords);
                auto &bomb_prefab = ecs::GameObject::FindPrefabByName("Bomb");
                auto &bomb_obj = ecs::GameObject::Instantiate(bomb_prefab, pos);
                auto &bomb_script = bomb_obj.getScript<Bomb>();

                bomb_script.player = &gameObject;
                m_free_bomb_nb -= 1;
                bomb_obj.transform().setPosition(new_pos);
                bomb_obj.getScript<Bomb>().range = m_blast_range;
            }
        }
    }
}

void Player::takeDamage() noexcept
{
    constexpr float protection_time = 1;

    // Give the player 1s of invulnerability
    if (m_protection_clock.time() < protection_time)
        return;
    m_protection_clock.reset();
    m_hp -= 1;
    if (m_hp == 0 && m_alive) {
        const auto &res_screen_bp = ecs::GameObject::FindPrefabByName("ResultScreen");
        ecs::GameObject::Instantiate(res_screen_bp);
        m_alive = false;
    }
}
