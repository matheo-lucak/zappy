/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** sceneConf
*/

#include "deserializer.hpp"
#include <fstream>
#include <regex>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace indie::deserializer::sceneConf
{
    std::vector<std::string> deserialize(std::string_view path)
    {
        std::string p{path};
        std::ifstream stream{p};

        if (!stream) {
            throw std::runtime_error("Could not open file '" + p + "'");
        }
        json j;
        stream >> j;
        std::vector<std::string> scenes;
        auto slash = path.find_last_of('/');
        std::string relativePath{slash == std::string::npos ? "./" : path.substr(0, slash + 1)};

        for (const auto &[key, value] : j.items()) {
            if (key == "comment") {
                continue;
            } else if (key == "scenes") {
                scenes.reserve(value.size());
                for (const auto &p : value) {
                    scenes.emplace_back(relativePath + p.get<std::string>());
                }
            } else {
                throw std::runtime_error("Invlid key '" + key + "'");
            }
        }
        return scenes;
    }
} // namespace sceneConf