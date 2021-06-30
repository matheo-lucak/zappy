/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Application
*/

#pragma once

#include <memory>
#include <string_view>
#include <getopt.h>

#include "Graphics/Window.hpp"

int main(int ac, char **av);

namespace ecs
{
    class GameObject;
    class BoxCollider;
} // namespace ecs

namespace indie
{
    struct ApplicationCmdLineArgs
    {
    public:
        unsigned int count;
        char **args;

        static constexpr char short_options[] = "p:h:";

        static constexpr struct option long_options[] = {
            {.name = "port",        .has_arg = 1, .flag = NULL, .val = 'p'},
            {.name = "machine",     .has_arg = 1, .flag = NULL, .val = 'h'},
            {.name = "help",        .has_arg = 0, .flag = NULL, .val = 'd'},
            {.name = NULL,          .has_arg = 0, .flag = NULL, .val = 0}
        };

        inline char *operator[](unsigned int idx) noexcept
        {
            return args[idx];
        }

        inline const char *operator[](unsigned int idx) const noexcept
        {
            return args[idx];
        }

        char *at(unsigned int idx);
    };

    class Application
    {
    public:
        static indie::Application *application;
        unsigned int port;
        std::string machine;

    public:
        Application(indie::ApplicationCmdLineArgs args, std::string_view name, std::string_view sceneConfPath, int width, int height, int fps = 60);
        virtual ~Application() noexcept;

        indie::Application *get() const noexcept;

    private:
        Graphics::Window m_window;

        void parse_args(indie::ApplicationCmdLineArgs args);
        void run();
        void UpdateLoop();
        void UpdateColliders();
        void HandleCollision(ecs::GameObject &obj1, ecs::BoxCollider &collider1,
                                 ecs::GameObject &obj2, ecs::BoxCollider &collider2);
        friend int ::main(int ac, char **av);
    };
} // namespace indie

/**
 * @brief Create an Application object, MUST be provided by the User
 * 
 * @param args Command line arguments given at the start of the bin
 * @return std::unique_ptr<Application>
 */
std::unique_ptr<indie::Application> CreateApplication(indie::ApplicationCmdLineArgs args);
