/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** script
*/

#include "deserializer.hpp"
#include "Script.hpp"
#include <unordered_map>

namespace zappy::deserializer::script
{
    static std::unordered_map<std::string, ScriptCreator> factories{};

    std::unique_ptr<ecs::Script> scriptFactory(std::string_view className, ecs::GameObject &gameObject)
    {
        return factories.at(std::string{className})(gameObject);
    }

    void addScriptFactory(std::string_view className, ScriptCreator func)
    {
        factories[std::string{className}] = func;
    }
} // namespace zappy::deserializer::script
