/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Script
*/

#pragma once

#include <memory>
#include <string_view>

namespace ecs
{
    class GameObject;

    class Script {
        public:
            Script(GameObject &gameObject) noexcept : gameObject{gameObject} {}
            Script(const Script &) noexcept = delete;
            Script(Script &&) noexcept = delete;
            virtual ~Script() noexcept = default;

            Script &operator=(const Script &) noexcept = delete;
            Script &operator=(Script &&) noexcept = delete;

            virtual std::unique_ptr<Script> copy(ecs::GameObject &copyOn) const noexcept = 0;

            virtual void Awake() noexcept {}
            virtual void Start() noexcept {}
            virtual void Update() noexcept {}
            virtual void LateUpdate() noexcept {}
            virtual void OnApplicationQuit() noexcept {}
            virtual void OnDestroy() noexcept {}
            virtual void OnTrigger(GameObject &other) noexcept {}
            virtual void OnCollision(GameObject &other) noexcept {}

            GameObject &gameObject;

        protected:
        private:
    };
} // namespace ecs

#define DECLARE_AS_SCRIPT(__className)         \
    std::unique_ptr<__className> create##__className(ecs::GameObject &);

#define SCRIPT_INIT(__className)    \
    class __className;              \
    std::unique_ptr<__className> create##__className(ecs::GameObject &gameObject) { return std::make_unique<__className>(gameObject); }   \

namespace indie::deserializer::script
{
    void addScriptFactory(std::string_view className, std::unique_ptr<ecs::Script> (*func)(ecs::GameObject &));
} // namespace indie::deserializer::script

#define ReferenceScript(__className) \
    indie::deserializer::script::addScriptFactory(#__className, \
        reinterpret_cast<std::unique_ptr<ecs::Script> (*)(ecs::GameObject &)>(&create##__className))
