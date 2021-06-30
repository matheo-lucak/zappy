/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** component
*/

#include "deserializer.hpp"
#include "ECS.hpp"
#include "Utils/Vector3.hpp"
#include "Utils/Vector2.hpp"
#include <fstream>
#include <regex>
#include <iostream>
#include <nlohmann/json.hpp>
#include <array>
#include <algorithm>

using json = nlohmann::json;

namespace utils
{
    void from_json(const json &j, utils::Vector3f &vect)
    {
        if (j.is_number()) {
            j.get_to(vect.x);
            vect.z = (vect.y = vect.x);
            return;
        }
        auto all = j.find("all");
        if (all != j.end()) {
            (*all).get_to(vect.x);
            vect.z = (vect.y = vect.x);
        } else {
            j.at("x").get_to(vect.x);
            j.at("y").get_to(vect.y);
            j.at("z").get_to(vect.z);
        }
    }
    void from_json(const json &j, utils::Vector2f &vect)
    {
        if (j.is_number()) {
            j.get_to(vect.x);
            vect.y = vect.x;
            return;
        }
        auto all = j.find("all");
        if (all != j.end()) {
            (*all).get_to(vect.x);
            vect.y = vect.x;
        } else {
            j.at("x").get_to(vect.x);
            j.at("y").get_to(vect.y);
        }
    }
    void from_json(const json &j, utils::Color &c)
    {
        if (j.is_string()) {
            c = Color::NameToColor(j.get<std::string>());
            return;
        }
        unsigned int r = j.at("r").get<unsigned int>();
        unsigned int g = j.at("g").get<unsigned int>();
        unsigned int b = j.at("b").get<unsigned int>();
        const auto &a = j.find("a");
        if (r > 255 || g > 255 || b > 255
        || (a != j.end() && (*a).get<unsigned int>() > 255)) {
            throw std::runtime_error("A color must be between 0 and 255");
        }
        c.r = r;
        c.g = g;
        c.b = b;
        if (a != j.end()) {
            c.a = (*a).get<unsigned int>();
        }
    }
} // namespace utils

namespace ecs
{
    void from_json(const json &j, ecs::Transform &tr)
    {
        const auto &position = j.find("position");
        const auto &rotation = j.find("rotation");
        const auto &scale = j.find("scale");

        if (position != j.end()) {
            tr.setPosition((*position).get<utils::Vector3f>());
        }
        if (rotation != j.end()) {
            tr.setRotation((*rotation).get<utils::Vector3f>());
        }
        if (scale != j.end()) {
            tr.setScale((*scale).get<utils::Vector3f>());
        }
    }
} // namespace ecs

static ecs::GameObject *component_arg{nullptr};

namespace nlohmann {
    template <>
    struct adl_serializer<ecs::BoxCollider> {
        static ecs::BoxCollider from_json(const json& j) {
            ecs::BoxCollider bc{component_arg->transform()};

            const auto &center = j.find("center");
            const auto &size = j.find("size");
            const auto &isStatic = j.find("static");
            const auto &isTrigger = j.find("trigger");
            if (center != j.end()) {
                bc.setCenter((*center).get<utils::Vector3f>());
            }
            if (size != j.end()) {
                bc.setSize((*size).get<utils::Vector3f>());
            }
            if (isStatic != j.end()) {
                bc.setIsStatic((*isStatic).get<bool>());
            }
            if (isTrigger != j.end()) {
                bc.setIsTrigger((*isTrigger).get<bool>());
            }
            return bc;
        }
    };
    template <>
    struct adl_serializer<ecs::Button> {
        static ecs::Button from_json(const json& j) {
            ecs::Button b{*component_arg};

            const auto &size = j.find("size");
            const auto &origin = j.find("origin");
            const auto &hover = j.find("hover");
            const auto &pressed = j.find("pressed");
            const auto &hold = j.find("hold");
            if (size != j.end()) {
                b.setSize((*size).get<utils::Vector2f>());
            }
            if (origin != j.end()) {
                b.setOrigin((*origin).get<utils::Vector2f>());
            }
            if (hover != j.end()) {
                b.colorPressed = (*hover).get<utils::Color>();
            }
            if (pressed != j.end()) {
                b.colorPressed = (*pressed).get<utils::Color>();
            }
            if (hold != j.end()) {
                b.colorPressed = (*hold).get<utils::Color>();
            }
            return b;
        }
    };
    template <>
    struct adl_serializer<ecs::SoundPlayer> {
        static ecs::SoundPlayer from_json(const json& j) {
            ecs::SoundPlayer s{j.at("path").get<std::string>()};

            const auto &volume = j.find("volume");
            if (volume != j.end()) {
                s.setVolume((*volume).get<float>());
            }
            return s;
        }
    };
    template <>
    struct adl_serializer<ecs::MusicPlayer> {
        static ecs::MusicPlayer from_json(const json& j) {
            ecs::MusicPlayer s{j.at("path").get<std::string>()};

            const auto &volume = j.find("volume");
            const auto &pitch = j.find("pitch");
            const auto &looping = j.find("looping");
            const auto &play = j.find("play");
            if (volume != j.end()) {
                s.setVolume((*volume).get<float>());
            }
            if (pitch != j.end()) {
                s.setPitch((*pitch).get<float>());
            }
            if (looping != j.end()) {
                s.toggleLooping((*looping).get<bool>());
            }
            if (play != j.end()) {
                if ((*play).get<bool>()) {
                    s.play();
                } else {
                    s.stop();
                }
            }
            return s;
        }
    };
    template <>
    struct adl_serializer<ecs::Text> {
        static ecs::Text from_json(const json& j) {
            ecs::Text t{*component_arg, j.at("text").get<std::string>()};

            const auto &position = j.find("position");
            const auto &color = j.find("color");
            const auto &size = j.find("size");
            if (position != j.end()) {
                t.position = (*position).get<utils::Vector2f>();
            }
            if (color != j.end()) {
                t.color = (*color).get<utils::Color>();
            }
            if (size != j.end()) {
                t.size = (*size).get<float>();
            }
            return t;
        }
    };
    template <>
    struct adl_serializer<ecs::Image> {
        static ecs::Image from_json(const json& j) {
            ecs::Image img{*component_arg, j.at("path").get<std::string>()};

            const auto &position = j.find("position");
            const auto &rotation = j.find("rotation");
            const auto &scale = j.find("scale");
            if (position != j.end()) {
                img.position = (*position).get<utils::Vector2f>();
            }
            if (rotation != j.end()) {
                img.rotation = (*rotation).get<float>();
            }
            if (scale != j.end()) {
                img.scale = (*scale).get<float>();
            }
            return img;
        }
    };
    template <>
    struct adl_serializer<ecs::Model> {
        static ecs::Model from_json(const json& j) {
            const auto &texture = j.find("texture");
            ecs::Model model{*component_arg, j.at("path").get<std::string>(), texture != j.end() ? (*texture).get<std::string>() : ""};

            const auto &position = j.find("position");
            const auto &rotationAngle = j.find("rotationAngle");
            const auto &rotationAxis = j.find("rotationAxis");
            const auto &scale = j.find("scale");
            if (position != j.end()) {
                model.position() = (*position).get<utils::Vector2f>();
            }
            if (rotationAngle != j.end()) {
                model.rotationAngle() = (*rotationAngle).get<float>();
            }
            if (rotationAxis != j.end()) {
                model.rotationAxis() = (*rotationAxis).get<utils::Vector2f>();
                model.setRotation(model.rotationAxis());
            }
            if (scale != j.end()) {
                model.scaling() = (*scale).get<utils::Vector3f>();
            }
            return model;
        }
    };
    template <>
    struct adl_serializer<ecs::Animator> {
        static ecs::Animator from_json(const json& j) {
            ecs::Animator a{j.at("path").get<std::string>(), component_arg->getComponent<ecs::Model>()};

            const auto &isLooping = j.find("isLooping");
            const auto &index = j.find("index");
            if (isLooping != j.end()) {
                a.is_looping = (*isLooping).get<bool>();
            }
            if (index != j.end()) {
                a.setCurrentAnimation((*index).get<unsigned int>());
            }
            return a;
        }
    };
}

namespace indie::deserializer::component
{
    void parseComponent(ecs::GameObject &object, const json &j)
    {
        auto type = j.at("type").get<std::string>();

        component_arg = &object;
        if (type == "Transform") {
            object.transform() = j.get<ecs::Transform>();
        } else if (type == "BoxCollider") {
            object.addComponent<ecs::BoxCollider>(j.get<ecs::BoxCollider>());
        } else if (type == "Button") {
            object.addComponent<ecs::Button>(j.get<ecs::Button>());
        } else if (type == "SoundPlayer") {
            object.addComponent<ecs::SoundPlayer>(j.get<ecs::SoundPlayer>());
        } else if (type == "MusicPlayer") {
            object.addComponent<ecs::MusicPlayer>(j.get<ecs::MusicPlayer>());
        } else if (type == "Text") {
            object.addComponent<ecs::Text>(j.get<ecs::Text>());
        } else if (type == "Image") {
            object.addComponent<ecs::Image>(j.get<ecs::Image>());
        } else if (type == "Model") {
            object.addComponent<ecs::Model>(j.get<ecs::Model>());
        } else if (type == "Animator") {
            object.addComponent<ecs::Animator>(j.get<ecs::Animator>());
        } else {
            throw std::runtime_error("Unknown component type '" + type + "'");
        }
    }

    void deserialize(ecs::GameObject &object, std::string_view path)
    {
        std::string p{path};
        std::ifstream stream{p};

        if (!stream) {
            throw std::runtime_error("Could not open file '" + p + "'");
        }
        json j;
        stream >> j;
        return parseComponent(object, j);
    }
} // namespace component
