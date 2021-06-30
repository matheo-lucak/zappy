/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** NetworkManager
*/

#include <iostream>

#include "Core/Application.hpp"

#include "GameObject.hpp"
#include "ECS.hpp"
#include "Core.hpp"

#include "NetworkManager.hpp"

SCRIPT_INIT(NetworkManager)

NetworkManager::NetworkManager(ecs::GameObject &gameObject) noexcept :
    ecs::Script{gameObject},
    m_port(application->port),
    m_host(application->machine),
    m_alive(true)
{
    sf::TcpSocket::Status status = m_socket.connect(m_host, m_port);

    if (status != sf::TcpSocket::Status::Done) {
        std::cerr << "Could not connect to" << m_host << " : " << m_port << std::endl;
        m_alive = false;
    } else {
        std::cout << "Connected to " << m_host << " : " << m_port << std::endl;
        m_selector.add(m_socket);
    }
}

std::unique_ptr<ecs::Script> NetworkManager::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<NetworkManager>(copyOn);
}

void NetworkManager::Start() noexcept
{
    std::cout << "NetworkManager start" << std::endl;
}

void NetworkManager::Awake() noexcept
{
}

void NetworkManager::Update() noexcept
{
    constexpr size_t READ_SIZE = 4096;

    m_selector.wait(sf::seconds(0.01f));

    // Read from server
    if (m_selector.isReady(m_socket)) {
        char buffer[READ_SIZE + 1];
        size_t nb_bytes = 0;
        sf::TcpSocket::Status status;

        status = m_socket.receive(buffer, READ_SIZE, nb_bytes);
        if (status == sf::TcpSocket::Status::Error ||
            status == sf::TcpSocket::Status::Disconnected) {
            m_alive = false;
            std::cerr << "Disconnection from host" << std::endl;
        }
        buffer[nb_bytes] = '\0';
        m_buffer.append((char *)buffer);
    }

    // Parse requests
    std::string delim = ",";
    std::string chunk;
    size_t pos = 0;

    while ((pos = m_buffer.find(delim, 0)) != std::string::npos) {
        if (delim.find(m_buffer[0]) != std::string::npos) {
            m_buffer.erase(0, 1);
            continue;
        }
        chunk = m_buffer.substr(0, pos);
        Response r = Response(chunk);

        if (r.m_is_valid) {
            m_pending_responses.push(r);
            std::cout << "New response: \"" << chunk << "\"" << std::endl;
        } else {
            std::cout << "New Bad response: \"" << chunk << "\"" << std::endl;
        }
        m_buffer.erase(0, chunk.length());
    }

    // Send responses
    while (!m_pending_requests.empty()) {
        const Request &r = m_pending_requests.front();

        if (r.data.size() > 0 ) {
            m_socket.send(r.data.c_str(), r.data.size());
        }
        m_pending_requests.pop();
    }
}

void NetworkManager::addRequest(Request &&r)
{
    m_pending_requests.push(r);
}

Response NetworkManager::getResponse()
{
    Response r = m_pending_responses.front();
    m_pending_responses.pop();
    return r;
}

bool NetworkManager::isResponseAvaible()
{
    return !m_pending_responses.empty();
}
        