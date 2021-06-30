/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Player
*/

#pragma once

#include "Map.hpp"
#include "Clock.hpp"
#include "ECS/Script.hpp"
#include "Graphics.hpp"

class Player : public ecs::Script {
    public:
        Player(ecs::GameObject &gameObject) noexcept;
        ~Player() noexcept override = default;

        std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

        void Start() noexcept override;
        void Awake() noexcept override;
        void Update() noexcept override;

        void setPlayerID(int id) noexcept;

        float getSpeed() const noexcept;
        void setSpeed(float value) noexcept;

        unsigned int getBlastRange() const noexcept;
        void setBlastRange(unsigned int value) noexcept;

        unsigned int getHP() const noexcept;
        void setHP(unsigned int value) noexcept;

        unsigned int getNbBombPowerUpsUsed() const noexcept;
        void increaseNbBombPowerUpsUsed() noexcept;

        unsigned int getNbSpeedPowerUpsUsed() const noexcept;
        void increaseNbSpeedPowerUpsUsed() noexcept;

        unsigned int getNbFirePowerUpsUsed() const noexcept;
        void increaseNbFirePowerUpsUsed() noexcept;

        unsigned int getNbExtraLifePowerUpsUsed() const noexcept;
        void increaseNbExtraLifePowerUpsUsed() noexcept;

        unsigned int getNbBoxDestroyed() const noexcept;
        void increaseNbBoxDestroyed() noexcept;

        bool addBomb(bool add_slot) noexcept;

        void takeDamage() noexcept;
    protected:
    private:
        void HandleMovement() noexcept;
        void HandleBombs() noexcept;

    private:
        Map *               m_map                     = nullptr;
        int                 m_id;
        unsigned int        m_hp                      = 3;
        bool                m_alive                   = true;
        float               m_speed                   = 10.0f;
        unsigned int        m_free_bomb_nb            = 0;
        unsigned int        m_max_bomb_nb             = 1;
        unsigned int        m_blast_range             = 2;
        float               m_bomb_reloading_time     = 3.0f;
        Clock               m_bomb_reloading_clock;
        unsigned int        m_bomb_powerups_used      = 0;
        unsigned int        m_speed_powerups_used     = 0;
        unsigned int        m_fire_powerups_used      = 0;
        unsigned int        m_extralife_powerups_used = 0;
        unsigned int        m_box_destroyed           = 0;
        Clock               m_protection_clock;
        Graphics::Keycode   m_kup;
        Graphics::Keycode   m_kdown;
        Graphics::Keycode   m_kleft;
        Graphics::Keycode   m_kright;
        Graphics::Keycode   m_kbomb;
        ecs::Model        * m_model;
};

DECLARE_AS_SCRIPT(Player)
