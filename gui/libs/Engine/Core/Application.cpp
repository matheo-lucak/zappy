/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
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

char *indie::ApplicationCmdLineArgs::at(unsigned int idx)
{
    if (idx >= count) {
        throw std::runtime_error("Out of range.");
    }
    return args[idx];
}

indie::Application::Application(indie::ApplicationCmdLineArgs args, std::string_view name, std::string_view sceneConfPath, int width, int height, int fps) :
    port{0},
    machine{"localhost"},
    m_window{name, width, height, fps}
{
    std::cout << "App Created" << std::endl;
    parse_args(args);
    indie::SceneManagerInternal::LoadBuildScenes(sceneConfPath);
    application = this;
}

indie::Application::~Application() noexcept
{
    std::cout << "App Ended" << std::endl;
}

indie::Application *indie::Application::get() const noexcept
{
    return application;
}

void indie::Application::parse_args(indie::ApplicationCmdLineArgs args)
{
    std::string arg;
    int flag = -1;

    std::cout << "Parsing arguments!\n";
    while (1) {
        flag = getopt_long_only(args.count,
                                args.args,
                                indie::ApplicationCmdLineArgs::short_options,
                                indie::ApplicationCmdLineArgs::long_options,
                                NULL);
        switch (flag) {
            case 'p':
                arg = optarg;
                if (!std::all_of(arg.begin(), arg.end(), ::isdigit))
                    throw indie::ArgumentParsingError("The argument given for 'port' flag is invalid, must be a positive integer.");

                port = std::atoi(optarg);
                break;
            case 'h':
                machine = optarg;
                break;
            case 'd':
                std::cout << "USAGE: ./zappy_ai -p port -h machine\n"
                             "\tport\tis the port number\n"
                             "\tmachine\tis the name of the machine; localhost by default" << std::endl;

                throw indie::ArgumentHelpException("Help flag detected");
            case '?':
                throw indie::ArgumentParsingError("Unknown flag or a missing argument was encountered during parsing");
            case -1:
                goto end;
        }
    }
    end:
    std::cout << "Arguments parsed!\n";
}

void indie::Application::run()
{
    std::cout << "Initializing" << std::endl;

    Graphics::AudioContext audioContext{};
    indie::SceneManager::LoadScene(0);
    Time::StartFrame();
    UpdateLoop();
    indie::SceneManagerInternal::DeepExecuteObject([](auto &object) {
        for (auto &script : object.m_scripts) {
            script->OnApplicationQuit();
        }
    });
    indie::SceneManagerInternal::DeepExecuteObject([](auto &object) {
        for (auto &script : object.m_scripts) {
            script->OnDestroy();
        }
    });
    indie::SceneManagerInternal::m_scene->objects.clear();
}

void indie::Application::UpdateLoop()
{
    std::cout << "Running loop" << std::endl;
    while (!m_window.shouldClose())
    {
        { // Frame Initialization
            if (indie::SceneManagerInternal::m_wantNewScene != -1) {
                indie::SceneManagerInternal::LoadScene();
            }
            for (auto &obj : indie::SceneManagerInternal::m_scene->commissioning) {
                obj.get().activate();
            }
            indie::SceneManagerInternal::m_scene->commissioning.clear();
            Time::StartFrame();
        }
        { // Physics
            UpdateColliders();
            for (auto &animator : indie::SceneManagerInternal::m_scene->animators) {
                animator.second.get().update();
            }
        }
        { // Input Events
            for (auto &pair : indie::SceneManagerInternal::m_scene->buttons) {
                auto &btn = pair.second.get();
                btn.update();
            }
        }
        { // Game Logic
            indie::SceneManagerInternal::DeepExecuteObject([](auto &object) {
                if (object.getActive() == false)
                    return;
                for (auto &script : object.m_scripts) {
                    script->Update();
                }
            });
            indie::SceneManagerInternal::DeepExecuteObject([](auto &object) {
                if (object.getActive() == false)
                    return;
                for (auto &script : object.m_scripts) {
                    script->LateUpdate();
                }
            });
        }
        { // Scene Rendering
            if (!indie::SceneManagerInternal::m_scene->isMusicMuted) {
                for (auto &music : indie::SceneManagerInternal::m_scene->musics) {
                    music.second.get().update();
                }
            }
            m_window.toggleDrawing(true);
            m_window.toggleDrawing3D(true);
            for (auto &drawable : indie::SceneManagerInternal::m_scene->drawable3d) {
                m_window.draw(drawable.second.get());
            }
            m_window.toggleDrawing3D(false);
            for (auto &drawable : indie::SceneManagerInternal::m_scene->drawable2d) {
                m_window.draw(drawable.second.get());
            }
            m_window.toggleDrawing(false);
        }
        { // Decommissioning
            for (auto &obj : indie::SceneManagerInternal::m_scene->deleting) {
                ecs::GameObject &object = obj.get();
                for (auto &script : object.m_scripts) {
                    script->OnDestroy();
                }
                object.setActive(false);
                indie::SceneManagerInternal::DestroyObject(object);
            }
            indie::SceneManagerInternal::m_scene->deleting.clear();
            if (indie::SceneManagerInternal::m_quit) {
                break;
            }
        }
    }
}

void indie::Application::UpdateColliders()
{
    auto &colliders = indie::SceneManagerInternal::m_scene->colliders;
    for (size_t i1 = 0; i1 < colliders.size(); ++i1) {
        auto &obj1 = colliders[i1].first.get();
        auto &collider1 = colliders[i1].second.get();
        for (size_t i2 = i1 + 1; i2 < colliders.size(); ++i2) {
            auto &obj2 = colliders[i2].first.get();
            auto &collider2 = colliders[i2].second.get();
            HandleCollision(obj1, collider1, obj2, collider2);
        }
    }
}

void indie::Application::HandleCollision(
                        ecs::GameObject &obj1, ecs::BoxCollider &collider1,
                        ecs::GameObject &obj2, ecs::BoxCollider &collider2)
{
    if ((collider1.isStatic()  && collider2.isStatic())
    ||  (!collider1.isStatic() && !collider2.isStatic())
    ||  (collider1.isTrigger() && collider2.isTrigger())) {
        return;
    }
    auto collision = collider1.collide(collider2);
    if (!collision.has_value()) {
        return;
    }
    if (collider1.isTrigger() || collider2.isTrigger()) {
        for (auto &script : obj1.m_scripts) {
            script->OnTrigger(obj2);
        }
        for (auto &script : obj2.m_scripts) {
            script->OnTrigger(obj1);
        }
        return;
    }
    auto &rect = collision.value();
    auto lenX = rect.max.x - rect.min.x;
    auto lenZ = rect.max.z - rect.min.z;
    auto pos = collider2.isStatic() ? obj1.transform().getPosition()
                                    : obj2.transform().getPosition();
    if (lenX >= lenZ) {
        pos.z += lenZ * (rect.max.z <= pos.z ? 1 : -1);
    } else {
        pos.x += lenX * (rect.max.x <= pos.x ? 1 : -1);
    }
    if (collider2.isStatic()) {
        obj1.transform().setPosition(pos);
    } else {
        obj2.transform().setPosition(pos);
    }

    for (auto &script : obj1.m_scripts) {
        script->OnCollision(obj2);
    }
    for (auto &script : obj2.m_scripts) {
        script->OnCollision(obj1);
    }
}