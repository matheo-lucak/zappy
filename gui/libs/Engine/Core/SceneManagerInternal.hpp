/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** SceneManagerInternal
*/

#pragma once

#include <memory>
#include <vector>
#include <string>
#include <typeindex>
#include <functional>
#include <list>
#include <iostream>

#include "Utils/Vector3.hpp"
#include "Graphics/IDrawable.hpp"
#include "Graphics.hpp"

namespace ecs
{
    class IComponent;
    class GameObject;
    class BoxCollider;
    class Button;
    class MusicPlayer;
    class Animator;
} // namespace ecs

namespace zappy
{
    class Application;
} // namespace zappy

namespace zappy
{
    class Scene;

    class SceneManagerInternal {
        public:
            SceneManagerInternal() = delete;
            ~SceneManagerInternal() = delete;

            static void LoadBuildScenes(std::string_view path);

            static void AskLoadScene(unsigned int buildIdx);
            static void LoadScene();
            static int getActiveSceneBuildIdx() noexcept;

            static void QuitApplication() noexcept;

            static void ToggleMusicMute(bool value) noexcept;

            static std::unique_ptr<zappy::Scene> m_scene;
            static int m_activeSceneBuildIdx;
            static std::vector<std::string> m_paths;
            static bool m_quit;
            static int m_wantNewScene;

            static ecs::GameObject &InstantiateObject(std::unique_ptr<ecs::GameObject> object);
            static ecs::GameObject &InstantiateObject(std::unique_ptr<ecs::GameObject> object, const utils::Vector3f &pos);
            static ecs::GameObject &InstantiateObject(std::unique_ptr<ecs::GameObject> object, const utils::Vector3f &pos, const utils::Vector3f &rot);
            static void AskDestroyObject(ecs::GameObject &object);
            static void DestroyObject(ecs::GameObject &object);
            static void CommissionObject(ecs::GameObject &object);
            using ObjectFinder = std::function<bool(const ecs::GameObject &)>;
            using ObjectFindAction = std::function<int(std::vector<std::unique_ptr<ecs::GameObject>> &, std::size_t)>;
            using ObjectAction = std::function<void(ecs::GameObject &)>;
            static void DeepExecuteObject(ObjectAction action);
            static void DeepFindObject(ObjectFinder finder, ObjectFindAction action);
            static bool DeepFindObjectHelper(const ObjectFinder &finder, const ObjectFindAction &action, std::vector<std::unique_ptr<ecs::GameObject>> &list);
            static ecs::GameObject *FindGameObjectByName(const std::string &name);
            static ecs::GameObject *FindGameObjectByNameInList(const std::string &name, std::vector<std::unique_ptr<ecs::GameObject>> &list);
            static ecs::GameObject &FindPrefabByName(const std::string &name);
            static std::list<ecs::GameObject *> FindGameObjectsByTag(const std::string &tag);

            static void OnDrawable2DComponentAdded(ecs::GameObject &object, Graphics::IDrawable2D &component);
            static void OnDrawable3DComponentAdded(ecs::GameObject &object, Graphics::IDrawable3D &component);
            template<typename ComponentType>
            static void OnComponentAdded(ecs::GameObject &object, ComponentType &component)
            {
                if constexpr (std::is_base_of<Graphics::IDrawable3D, ComponentType>()) {
                    OnDrawable3DComponentAdded(object, component);
                } else if constexpr (std::is_base_of<Graphics::IDrawable2D, ComponentType>()) {
                    OnDrawable2DComponentAdded(object, component);
                }
            };
            static void OnComponentAdded(ecs::GameObject &object, ecs::IComponent &component, const std::type_index &type);

            template<typename ComponentType>
            static void OnComponentRemoved(ecs::GameObject &object) {};
            static void OnComponentRemoved(ecs::GameObject &object, const std::type_index &type);

        protected:
        private:
    };

    template<>
    void SceneManagerInternal::OnComponentAdded<ecs::Animator>(ecs::GameObject &object, ecs::Animator &component);
    template<>
    void SceneManagerInternal::OnComponentRemoved<ecs::Animator>(ecs::GameObject &object);
    template<>
    void SceneManagerInternal::OnComponentAdded<ecs::BoxCollider>(ecs::GameObject &object, ecs::BoxCollider &component);
    template<>
    void SceneManagerInternal::OnComponentRemoved<ecs::BoxCollider>(ecs::GameObject &object);
    template<>
    void SceneManagerInternal::OnComponentAdded<ecs::Button>(ecs::GameObject &object, ecs::Button &component);
    template<>
    void SceneManagerInternal::OnComponentRemoved<ecs::Button>(ecs::GameObject &object);
    template<>
    void SceneManagerInternal::OnComponentAdded<ecs::MusicPlayer>(ecs::GameObject &object, ecs::MusicPlayer &component);
    template<>
    void SceneManagerInternal::OnComponentRemoved<ecs::MusicPlayer>(ecs::GameObject &object);
    template<>
    void SceneManagerInternal::OnComponentRemoved<Graphics::IDrawable2D>(ecs::GameObject &object);
    template<>
    void SceneManagerInternal::OnComponentRemoved<Graphics::IDrawable3D>(ecs::GameObject &object);
} // namespace zappy