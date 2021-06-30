/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** gameobject
*/

#include "deserializer.hpp"
#include "ECS.hpp"
#include "Utils/string.hpp"
#include <fstream>
#include <regex>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace zappy::deserializer::component
{
    void parseComponent(ecs::GameObject &object, const json &j);
} // namespace component

namespace zappy::deserializer::object
{
    std::unique_ptr<ecs::GameObject> parseObject(json &obj, const std::string &relativePath, const std::vector<std::unique_ptr<ecs::GameObject>> &prefabList);

    std::unique_ptr<ecs::GameObject> parseObjectNomination(json &obj, const std::string &relativePath,
                                        const std::vector<std::unique_ptr<ecs::GameObject>> &prefabList)
    {
        if (obj.size() != 1) {
            throw std::runtime_error("Inalid object nomination '" + obj.dump() + "'");
        }
        auto &[type, objVal] = *obj.items().begin();
        if (type == "prefab") {
            auto prefabName = objVal.get<std::string>();
            auto it = std::find_if(prefabList.begin(), prefabList.end(), [&prefabName](const auto &prefab) { return prefab->getName() == prefabName; });
            if (it != prefabList.end()) {
                return std::make_unique<ecs::GameObject>(**it);
            } else {
                throw std::runtime_error("Prefab not found '" + prefabName + "'");
            }
        } else if (type == "object") {
            if (objVal.is_string()) {
                return deserializer::object::deserialize(relativePath + objVal.get<std::string>(), prefabList);
            } else if (objVal.is_object()) {
                return deserializer::object::parseObject(objVal, relativePath, prefabList);
            } else {
                throw std::runtime_error("Invalid object value '" + obj.dump() + "'");
            }
        } else if (type == "comment") {
            return std::make_unique<ecs::GameObject>("Empty");
        }
        throw std::runtime_error("Invlid object type '" + type + "'");
        return nullptr;
    }

    std::unique_ptr<ecs::GameObject> parseObject(json &obj, const std::string &relativePath, const std::vector<std::unique_ptr<ecs::GameObject>> &prefabList)
    {
        auto res = std::make_unique<ecs::GameObject>(obj.at("name").get<std::string>());
        res->setActive(false);
        auto tag = obj.find("tag");
        if (tag != obj.end()) {
            res->setTag((*tag).get<std::string>());
        }
        for (auto &component : obj["components"]) {
            component::parseComponent(*res, component);
        }
        for (auto &child : obj["childs"]) {
            res->InstantiateChild(parseObjectNomination(child, relativePath, prefabList));
        }
        for (auto &scriptName : obj["scripts"]) {
            res->addScript(script::scriptFactory(scriptName.get<std::string>(), *res));
        }
        return res;
    }

    std::unique_ptr<ecs::GameObject> deserialize(std::string_view path, const std::vector<std::unique_ptr<ecs::GameObject>> &prefabList)
    {
        std::string p{path};
        std::ifstream stream{p};

        if (!stream) {
            throw std::runtime_error("Could not open file '" + p + "'");
        }
        auto slash = path.find_last_of('/');
        std::string relativePath{slash == std::string::npos ? "./" : path.substr(0, slash + 1)};
        json j;
        stream >> j;
        return parseObject(j, relativePath, prefabList);
    }
} // namespace gameobject
