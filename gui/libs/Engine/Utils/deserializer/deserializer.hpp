/*
** EPITECH PROJECT, 2021
** test
** File description:
** deserializer
*/

#pragma once

#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include <optional>

namespace zappy
{
    class Scene;
} // namespace zappy

namespace ecs
{
    class GameObject;
    class Script;
} // namespace ecs

namespace zappy::deserializer
{
    namespace sceneConf
    {
        std::vector<std::string> deserialize(std::string_view path);
    } // namespace sceneConf
    
    namespace scene
    {
        void deserialize(std::string_view path, Scene &scene);
    } // namespace scene
    
    namespace object
    {
        std::unique_ptr<ecs::GameObject> deserialize(std::string_view path, const std::vector<std::unique_ptr<ecs::GameObject>> &prefabList);
    } // namespace gameobject

    namespace script
    {
        using ScriptCreator =  std::unique_ptr<ecs::Script> (*)(ecs::GameObject &gameObject);
        std::unique_ptr<ecs::Script> scriptFactory(std::string_view className, ecs::GameObject &gameObject);
        void addScriptFactory(std::string_view className, ScriptCreator func);
    } // namespace script

    namespace component
    {
        void deserialize(ecs::GameObject &object, std::string name, const std::vector<std::string> &args);
    } // namespace component

} // namespace zappy
