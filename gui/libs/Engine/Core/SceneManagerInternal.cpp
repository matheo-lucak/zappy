/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** SceneManagerInternal
*/

#include <algorithm>
#include <functional>
#include <functional>

#include "SceneManagerInternal.hpp"
#include "Scene.hpp"
#include "GameObject.hpp"
#include "ECS.hpp"
#include "Asserts.hpp"
#include "Utils/deserializer/deserializer.hpp"

using namespace zappy;

std::unique_ptr<Scene> SceneManagerInternal::m_scene{nullptr};
int SceneManagerInternal::m_activeSceneBuildIdx{-1};
std::vector<std::string> SceneManagerInternal::m_paths{};
bool SceneManagerInternal::m_quit{false};
int SceneManagerInternal::m_wantNewScene{-1};

void SceneManagerInternal::LoadBuildScenes(std::string_view path)
{
    (void)path;
    ZAPPY_CORE_ASSERT(m_paths.size(), "A build scene conf can be set just once");
    m_paths = deserializer::sceneConf::deserialize(path);
}

void SceneManagerInternal::AskLoadScene(unsigned int buildIdx)
{
    ZAPPY_CORE_ASSERT(buildIdx >= m_paths.size(), "Scene index out of range");
    m_wantNewScene = buildIdx;
}

void SceneManagerInternal::LoadScene()
{
    m_activeSceneBuildIdx = m_wantNewScene;
    m_wantNewScene = -1;
    m_scene = std::make_unique<Scene>();
    deserializer::scene::deserialize(m_paths[m_activeSceneBuildIdx], *m_scene);

    for (auto &obj : m_scene->objects)
    {
        obj->activate();
    }
    DeepExecuteObject([](auto &object)
                      {
                          for (auto &script : object.m_scripts)
                          {
                              script->Start();
                          }
                      });
}

int SceneManagerInternal::getActiveSceneBuildIdx() noexcept
{
    return m_activeSceneBuildIdx;
}

void SceneManagerInternal::QuitApplication() noexcept
{
    m_quit = true;
}

void SceneManagerInternal::ToggleMusicMute(bool value) noexcept
{
    m_scene->isMusicMuted = value;
}

ecs::GameObject &SceneManagerInternal::InstantiateObject(std::unique_ptr<ecs::GameObject> object)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    ecs::GameObject &obj = *m_scene->objects.emplace_back(std::move(object));
    obj.setActive(true);
    return obj;
}

ecs::GameObject &SceneManagerInternal::InstantiateObject(std::unique_ptr<ecs::GameObject> object, const utils::Vector3f &pos)
{
    auto &obj = InstantiateObject(std::move(object));
    auto &tr = obj.getComponent<ecs::Transform>();
    tr.setPosition(pos);
    return obj;
}

ecs::GameObject &SceneManagerInternal::InstantiateObject(std::unique_ptr<ecs::GameObject> object, const utils::Vector3f &pos, const utils::Vector3f &rot)
{
    auto &obj = InstantiateObject(std::move(object));
    auto &tr = obj.getComponent<ecs::Transform>();
    tr.setPosition(pos);
    tr.setRotation(rot);
    return obj;
}

void SceneManagerInternal::AskDestroyObject(ecs::GameObject &object)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    m_scene->deleting.push_back(object);
}

void SceneManagerInternal::DestroyObject(ecs::GameObject &object)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    DeepFindObject([&object](const auto &obj)
                   { return obj == object; },
                   [](auto &list, auto i)
                   {
                       list.erase(list.begin() + i);
                       return -1;
                   });
}

void SceneManagerInternal::CommissionObject(ecs::GameObject &object)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    m_scene->commissioning.push_back(object);
}

bool SceneManagerInternal::DeepFindObjectHelper(const ObjectFinder &finder, const ObjectFindAction &action, std::vector<std::unique_ptr<ecs::GameObject>> &list)
{
    for (std::size_t i = 0; i < list.size(); ++i)
    {
        bool keepSeach = true;
        if (finder(*list[i]))
        {
            int res = action(list, i);
            if (res < 0)
            {
                return true;
            }
            keepSeach = !!res;
        }
        if (keepSeach)
        {
            if (DeepFindObjectHelper(finder, action, list[i]->m_children))
            {
                return true;
            }
        }
    }
    return false;
}

void SceneManagerInternal::DeepFindObject(ObjectFinder finder, ObjectFindAction action)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    if (!finder || !action)
        return;
    DeepFindObjectHelper(finder, action, m_scene->objects);
}

void SceneManagerInternal::DeepExecuteObject(ObjectAction action)
{
    SceneManagerInternal::DeepFindObject([](const auto &obj)
                                         { return true; },
                                         [&action](auto &list, auto i)
                                         {
                                             action(*list[i]);
                                             return 1;
                                         });
}

ecs::GameObject *SceneManagerInternal::FindGameObjectByName(const std::string &name)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    return FindGameObjectByNameInList(name, m_scene->objects);
}

ecs::GameObject *SceneManagerInternal::FindGameObjectByNameInList(const std::string &name, std::vector<std::unique_ptr<ecs::GameObject>> &list)
{
    ecs::GameObject *res = nullptr;
    DeepFindObjectHelper([&name](const auto &obj)
                         { return obj.getName() == name; },
                         [&res](auto &list, auto i)
                         {
                             res = &*list[i];
                             return -1;
                         },
                         list);
    return res;
}

ecs::GameObject &SceneManagerInternal::FindPrefabByName(const std::string &name)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    auto it = std::find_if(m_scene->prefabs.begin(), m_scene->prefabs.end(),
                           [&name](const auto &obj)
                           { return obj->getName() == name; });
    ZAPPY_CORE_ASSERT(it == m_scene->prefabs.end(), "No prefab named '" + name + "'");
    return **it;
}

std::list<ecs::GameObject *> SceneManagerInternal::FindGameObjectsByTag(const std::string &tag)
{
    std::list<ecs::GameObject *> res;
    DeepFindObject([&tag](const auto &obj)
                   { return obj.getTag() == tag; },
                   [&res](auto &list, auto i)
                   {
                       res.emplace_back(&*list[i]);
                       return 0;
                   });
    return res;
}

void SceneManagerInternal::OnComponentAdded(ecs::GameObject &object, ecs::IComponent &component, const std::type_index &type)
{
    if (object.getActive() == false)
        return;
    if (type == std::type_index{typeid(ecs::BoxCollider)})
    {
        OnComponentAdded(object, *reinterpret_cast<ecs::BoxCollider *>(&component));
    }
    else if (type == std::type_index{typeid(ecs::Button)})
    {
        OnComponentAdded(object, *reinterpret_cast<ecs::Button *>(&component));
    }
    else if (type == std::type_index{typeid(ecs::MusicPlayer)})
    {
        OnComponentAdded(object, *reinterpret_cast<ecs::MusicPlayer *>(&component));
    }
    else if (type == std::type_index{typeid(ecs::Animator)})
    {
        OnComponentAdded(object, *reinterpret_cast<ecs::Animator *>(&component));
    }
    else if (type == std::type_index{typeid(ecs::Text)})
    {
        OnDrawable2DComponentAdded(object, *reinterpret_cast<ecs::Text *>(&component));
    }
    else if (type == std::type_index{typeid(ecs::Image)})
    {
        OnDrawable2DComponentAdded(object, *reinterpret_cast<ecs::Image *>(&component));
    }
    else if (type == std::type_index{typeid(ecs::Model)})
    {
        OnDrawable3DComponentAdded(object, *reinterpret_cast<ecs::Model *>(&component));
    }
    else if (type == std::type_index{typeid(ecs::Drawable2D)})
    {
        OnDrawable2DComponentAdded(object, *reinterpret_cast<ecs::Drawable2D *>(&component));
    }
    else if (type == std::type_index{typeid(ecs::Drawable3D)})
    {
        OnDrawable3DComponentAdded(object, *reinterpret_cast<ecs::Drawable3D *>(&component));
    }
}
void SceneManagerInternal::OnDrawable2DComponentAdded(ecs::GameObject &object, Graphics::IDrawable2D &component)
{
    if (object.getActive() == false)
        return;
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    m_scene->drawable2d.push_back(std::pair<std::reference_wrapper<ecs::GameObject>, std::reference_wrapper<Graphics::IDrawable2D>>{object, component});
}
void SceneManagerInternal::OnDrawable3DComponentAdded(ecs::GameObject &object, Graphics::IDrawable3D &component)
{
    if (object.getActive() == false)
        return;
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    m_scene->drawable3d.push_back(std::pair<std::reference_wrapper<ecs::GameObject>, std::reference_wrapper<Graphics::IDrawable3D>>{object, component});
}
template <>
void SceneManagerInternal::OnComponentAdded<ecs::BoxCollider>(ecs::GameObject &object, ecs::BoxCollider &component)
{
    if (object.getActive() == false)
        return;
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    m_scene->colliders.emplace_back(std::pair<ecs::GameObject &, std::reference_wrapper<ecs::BoxCollider>>{object, component});
}
template <>
void SceneManagerInternal::OnComponentAdded<ecs::Button>(ecs::GameObject &object, ecs::Button &component)
{
    if (object.getActive() == false)
        return;
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    m_scene->buttons.emplace_back(std::pair<ecs::GameObject &, std::reference_wrapper<ecs::Button>>{object, component});
}
template <>
void SceneManagerInternal::OnComponentAdded<ecs::MusicPlayer>(ecs::GameObject &object, ecs::MusicPlayer &component)
{
    if (object.getActive() == false)
        return;
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    m_scene->musics.emplace_back(std::pair<ecs::GameObject &, std::reference_wrapper<ecs::MusicPlayer>>{object, component});
}
template <>
void SceneManagerInternal::OnComponentAdded<ecs::Animator>(ecs::GameObject &object, ecs::Animator &component)
{
    if (object.getActive() == false)
        return;
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    m_scene->animators.emplace_back(std::pair<ecs::GameObject &, std::reference_wrapper<ecs::Animator>>{object, component});
}

void SceneManagerInternal::OnComponentRemoved(ecs::GameObject &object, const std::type_index &type)
{
    if (type == std::type_index{typeid(ecs::BoxCollider)})
    {
        OnComponentRemoved<ecs::BoxCollider>(object);
    }
    else if (type == std::type_index{typeid(ecs::Button)})
    {
        OnComponentRemoved<ecs::Button>(object);
    }
    else if (type == std::type_index{typeid(ecs::MusicPlayer)})
    {
        OnComponentRemoved<ecs::MusicPlayer>(object);
    }
    else if (type == std::type_index{typeid(ecs::Animator)})
    {
        OnComponentRemoved<ecs::Animator>(object);
    }
    else if (type == std::type_index{typeid(ecs::Text)})
    {
        OnComponentRemoved<Graphics::IDrawable2D>(object);
    }
    else if (type == std::type_index{typeid(ecs::Image)})
    {
        OnComponentRemoved<Graphics::IDrawable2D>(object);
    }
    else if (type == std::type_index{typeid(ecs::Model)})
    {
        OnComponentRemoved<Graphics::IDrawable3D>(object);
    }
    else if (type == std::type_index{typeid(ecs::Drawable2D)})
    {
        OnComponentRemoved<Graphics::IDrawable2D>(object);
    }
    else if (type == std::type_index{typeid(ecs::Drawable3D)})
    {
        OnComponentRemoved<Graphics::IDrawable3D>(object);
    }
}
template <>
void SceneManagerInternal::OnComponentRemoved<ecs::BoxCollider>(ecs::GameObject &object)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    auto it = std::find_if(m_scene->colliders.begin(), m_scene->colliders.end(),
                           [&object](const auto &pair)
                           {
                               return object == pair.first;
                           });
    ZAPPY_CORE_ASSERT(it == m_scene->colliders.end(), "The corresponding object could not been found");
    m_scene->colliders.erase(it);
}
template <>
void SceneManagerInternal::OnComponentRemoved<ecs::Button>(ecs::GameObject &object)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    auto it = std::find_if(m_scene->buttons.begin(), m_scene->buttons.end(),
                           [&object](const auto &pair)
                           {
                               return object == pair.first;
                           });
    ZAPPY_CORE_ASSERT(it == m_scene->buttons.end(), "The corresponding object could not been found");
    m_scene->buttons.erase(it);
}
template <>
void SceneManagerInternal::OnComponentRemoved<ecs::MusicPlayer>(ecs::GameObject &object)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    auto it = std::find_if(m_scene->musics.begin(), m_scene->musics.end(),
                           [&object](const auto &pair)
                           {
                               return object == pair.first;
                           });
    ZAPPY_CORE_ASSERT(it == m_scene->musics.end(), "The corresponding object could not been found");
    m_scene->musics.erase(it);
}
template <>
void SceneManagerInternal::OnComponentRemoved<ecs::Animator>(ecs::GameObject &object)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    auto it = std::find_if(m_scene->animators.begin(), m_scene->animators.end(),
                           [&object](const auto &pair)
                           {
                               return object == pair.first;
                           });
    ZAPPY_CORE_ASSERT(it == m_scene->animators.end(), "The corresponding object could not been found");
    m_scene->animators.erase(it);
}
template <>
void SceneManagerInternal::OnComponentRemoved<Graphics::IDrawable2D>(ecs::GameObject &object)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    auto it = std::find_if(m_scene->drawable2d.begin(), m_scene->drawable2d.end(),
                           [&object](const auto &pair)
                           {
                               return object == pair.first;
                           });
    ZAPPY_CORE_ASSERT(it == m_scene->drawable2d.end(), "The corresponding object could not been found");
    m_scene->drawable2d.erase(it);
}
template <>
void SceneManagerInternal::OnComponentRemoved<Graphics::IDrawable3D>(ecs::GameObject &object)
{
    ZAPPY_CORE_ASSERT(m_scene == nullptr, "A scene must be set");
    auto it = std::find_if(m_scene->drawable3d.begin(), m_scene->drawable3d.end(),
                           [&object](const auto &pair)
                           {
                               return object == pair.first;
                           });
    ZAPPY_CORE_ASSERT(it == m_scene->drawable3d.end(), "The corresponding object could not been found");
    m_scene->drawable3d.erase(it);
}