/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** scene
*/

#include "deserializer.hpp"
#include "Scene.hpp"
#include "GameObject.hpp"
#include "Utils/string.hpp"
#include <fstream>
#include <regex>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace zappy::deserializer::object
{
    std::unique_ptr<ecs::GameObject> parseObjectNomination(json &obj, const std::string &relativePath,
                                        const std::vector<std::unique_ptr<ecs::GameObject>> &prefabList);
} // namespace object

namespace zappy::deserializer::scene
{
    static void parsePrefabArray(json &value, Scene &scene, const std::string &relativePath)
    {
        if (value.empty()) {
            return;
        }
        scene.prefabs.reserve(scene.prefabs.size() + value.size());
        for (auto &p : value) {
            scene.prefabs.emplace_back(object::deserialize(relativePath + p.get<std::string>(), scene.prefabs));
        }
    }

    static void parseObjectArray(json &value, Scene &scene, const std::string &relativePath)
    {
        if (value.empty()) {
            return;
        }
        scene.objects.reserve(scene.objects.size() + value.size());
        for (auto &obj : value) {
            scene.objects.emplace_back(object::parseObjectNomination(obj, relativePath, scene.prefabs));
        }
    }

    void deserialize(std::string_view path, Scene &scene)
    {
        std::string p{path};
        std::ifstream stream{p};

        if (!stream) {
            throw std::runtime_error("Could not open file '" + p + "'");
        }
        json j;
        stream >> j;
        auto slash = path.find_last_of('/');
        std::string relativePath{slash == std::string::npos ? "./" : path.substr(0, slash + 1)};

        auto prefabs = j.find("prefabs");
        if (prefabs != j.end()) {
            parsePrefabArray(*prefabs, scene, relativePath);
        }
        for (auto &[key, value] : j.items()) {
            if (key == "comment") {
                continue;
            } else if (key == "prefabs") {
                continue;
            } else if (key == "objects") {
                parseObjectArray(value, scene, relativePath);
            } else {
                throw std::runtime_error("Invalid key '" + key + "'");
            }
        }
    }
} // namespace scene
