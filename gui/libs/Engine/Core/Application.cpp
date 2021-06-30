/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Application
*/

#include <stdexcept>
#include <iostream>
#include <algorithm>

#include "Core/Application.hpp"
#include "Core/Scene.hpp"
#include "Core/SceneManager.hpp"
#include "Core/SceneManagerInternal.hpp"
#include "Core/Time.hpp"
#include "ECS.hpp"
#include "Graphics.hpp"
#include "ArgumentParsingError.hpp"
#include "ArgumentHelpException.hpp"

zappy::Application *application = nullptr;

char *zappy::ApplicationCmdLineArgs::at(unsigned int idx)
{
    if (idx >= count)
    {
        throw std::runtime_error("Out of range.");
    }
    return args[idx];
}

zappy::Application::Application(zappy::ApplicationCmdLineArgs args, std::string_view name, std::string_view sceneConfPath, int width, int height, int fps) : port{0},
                                                                                                                                                             machine{"localhost"},
                                                                                                                                                             m_window{name, width, height, fps}
{
    std::cout << "App Created" << std::endl;
    parse_args(args);
    zappy::SceneManagerInternal::LoadBuildScenes(sceneConfPath);
    ::application = this;
}

zappy::Application::~Application() noexcept
{
    std::cout << "App Ended" << std::endl;
}

void zappy::Application::parse_args(zappy::ApplicationCmdLineArgs args)
{
    std::string arg;
    int flag = -1;

    std::cout << "Parsing arguments!\n";
    while (1)
    {
        flag = getopt_long_only(args.count,
                                args.args,
                                zappy::ApplicationCmdLineArgs::short_options,
                                zappy::ApplicationCmdLineArgs::long_options,
                                NULL);
        switch (flag)
        {
        case 'p':
            arg = optarg;
            if (!std::all_of(arg.begin(), arg.end(), ::isdigit))
                throw zappy::ArgumentParsingError("The argument given for 'port' flag is invalid, must be a positive integer.");

            port = std::atoi(optarg);
            break;
        case 'h':
            machine = optarg;
            break;
        case 'd':
            std::cout << "USAGE: ./zappy_ai -p port -h machine\n"
                         "\tport\tis the port number\n"
                         "\tmachine\tis the name of the machine; localhost by default"
                      << std::endl;

            throw zappy::ArgumentHelpException("Help flag detected");
        case '?':
            throw zappy::ArgumentParsingError("Unknown flag or a missing argument was encountered during parsing");
        case -1:
            goto end;
        }
    }
end:
    std::cout << "Arguments parsed!\n";
}

void zappy::Application::run()
{
    std::cout << "Initializing" << std::endl;

    Graphics::AudioContext audioContext{};
    zappy::SceneManager::LoadScene(0);
    Time::StartFrame();
    UpdateLoop();
    zappy::SceneManagerInternal::DeepExecuteObject([](auto &object)
                                                   {
                                                       for (auto &script : object.m_scripts)
                                                       {
                                                           script->OnApplicationQuit();
                                                       }
                                                   });
    zappy::SceneManagerInternal::DeepExecuteObject([](auto &object)
                                                   {
                                                       for (auto &script : object.m_scripts)
                                                       {
                                                           script->OnDestroy();
                                                       }
                                                   });
    zappy::SceneManagerInternal::m_scene->objects.clear();
}

void zappy::Application::UpdateLoop()
{
    std::cout << "Running loop" << std::endl;
    while (!m_window.shouldClose())
    {
        { // Frame Initialization
            if (zappy::SceneManagerInternal::m_wantNewScene != -1)
            {
                zappy::SceneManagerInternal::LoadScene();
            }
            for (auto &obj : zappy::SceneManagerInternal::m_scene->commissioning)
            {
                obj.get().activate();
            }
            zappy::SceneManagerInternal::m_scene->commissioning.clear();
            Time::StartFrame();
        }
        { // Physics
            UpdateColliders();
            for (auto &animator : zappy::SceneManagerInternal::m_scene->animators)
            {
                animator.second.get().update();
            }
        }
        { // Input Events
            for (auto &pair : zappy::SceneManagerInternal::m_scene->buttons)
            {
                auto &btn = pair.second.get();
                btn.update();
            }
        }
        { // Game Logic
            zappy::SceneManagerInternal::DeepExecuteObject([](auto &object)
                                                           {
                                                               if (object.getActive() == false)
                                                                   return;
                                                               for (auto &script : object.m_scripts)
                                                               {
                                                                   script->Update();
                                                               }
                                                           });
            zappy::SceneManagerInternal::DeepExecuteObject([](auto &object)
                                                           {
                                                               if (object.getActive() == false)
                                                                   return;
                                                               for (auto &script : object.m_scripts)
                                                               {
                                                                   script->LateUpdate();
                                                               }
                                                           });
        }
        { // Scene Rendering
            if (!zappy::SceneManagerInternal::m_scene->isMusicMuted)
            {
                for (auto &music : zappy::SceneManagerInternal::m_scene->musics)
                {
                    music.second.get().update();
                }
            }
            m_window.toggleDrawing(true);
            m_window.toggleDrawing3D(true);
            for (auto &drawable : zappy::SceneManagerInternal::m_scene->drawable3d)
            {
                m_window.draw(drawable.second.get());
            }
            m_window.toggleDrawing3D(false);
            for (auto &drawable : zappy::SceneManagerInternal::m_scene->drawable2d)
            {
                m_window.draw(drawable.second.get());
            }
            m_window.toggleDrawing(false);
        }
        { // Decommissioning
            for (auto &obj : zappy::SceneManagerInternal::m_scene->deleting)
            {
                ecs::GameObject &object = obj.get();
                for (auto &script : object.m_scripts)
                {
                    script->OnDestroy();
                }
                object.setActive(false);
                zappy::SceneManagerInternal::DestroyObject(object);
            }
            zappy::SceneManagerInternal::m_scene->deleting.clear();
            if (zappy::SceneManagerInternal::m_quit)
            {
                break;
            }
        }
    }
}

void zappy::Application::UpdateColliders()
{
    auto &colliders = zappy::SceneManagerInternal::m_scene->colliders;
    for (size_t i1 = 0; i1 < colliders.size(); ++i1)
    {
        auto &obj1 = colliders[i1].first.get();
        auto &collider1 = colliders[i1].second.get();
        for (size_t i2 = i1 + 1; i2 < colliders.size(); ++i2)
        {
            auto &obj2 = colliders[i2].first.get();
            auto &collider2 = colliders[i2].second.get();
            HandleCollision(obj1, collider1, obj2, collider2);
        }
    }
}

void zappy::Application::HandleCollision(
    ecs::GameObject &obj1, ecs::BoxCollider &collider1,
    ecs::GameObject &obj2, ecs::BoxCollider &collider2)
{
    if ((collider1.isStatic() && collider2.isStatic()) || (!collider1.isStatic() && !collider2.isStatic()) || (collider1.isTrigger() && collider2.isTrigger()))
    {
        return;
    }
    auto collision = collider1.collide(collider2);
    if (!collision.has_value())
    {
        return;
    }
    if (collider1.isTrigger() || collider2.isTrigger())
    {
        for (auto &script : obj1.m_scripts)
        {
            script->OnTrigger(obj2);
        }
        for (auto &script : obj2.m_scripts)
        {
            script->OnTrigger(obj1);
        }
        return;
    }
    auto &rect = collision.value();
    auto lenX = rect.max.x - rect.min.x;
    auto lenZ = rect.max.z - rect.min.z;
    auto pos = collider2.isStatic() ? obj1.transform().getPosition()
                                    : obj2.transform().getPosition();
    if (lenX >= lenZ)
    {
        pos.z += lenZ * (rect.max.z <= pos.z ? 1 : -1);
    }
    else
    {
        pos.x += lenX * (rect.max.x <= pos.x ? 1 : -1);
    }
    if (collider2.isStatic())
    {
        obj1.transform().setPosition(pos);
    }
    else
    {
        obj2.transform().setPosition(pos);
    }

    for (auto &script : obj1.m_scripts)
    {
        script->OnCollision(obj2);
    }
    for (auto &script : obj2.m_scripts)
    {
        script->OnCollision(obj1);
    }
}