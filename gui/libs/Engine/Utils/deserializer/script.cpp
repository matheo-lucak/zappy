/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** script
*/

#include "deserializer.hpp"
#include "Script.hpp"
#include <unordered_map>

namespace indie::deserializer::script
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
} // namespace indie::deserializer::script
