/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** NetworkManager
*/

#pragma once

#include <queue>
#include <SFML/Network.hpp>

#include "ECS/Script.hpp"
#include "ECS/Components/Model.hpp"

#include "net/Request.hpp"
#include "net/Response.hpp"

class NetworkManager : public ecs::Script {
    public:
        NetworkManager(ecs::GameObject &gameObject) noexcept;
        ~NetworkManager() = default;

        std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

        void Awake() noexcept override;
        void Start() noexcept override;
        void Update() noexcept override;

        void addRequest(Request &&r);
        Response getResponse();

        bool isResponseAvaible();

    public:
        sf::SocketSelector      m_selector;
        sf::TcpSocket           m_socket;
        std::string             m_buffer;
        unsigned int            m_port;
        std::string             m_host;
        bool                    m_alive;

        std::queue<Request>     m_pending_requests;
        std::queue<Response>    m_pending_responses;
};

DECLARE_AS_SCRIPT(NetworkManager)
