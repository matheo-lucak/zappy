/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** GameObject
*/

#pragma once

#include <ostream>
#include <string>
#include <memory>
#include <vector>
#include <functional>
#include <cstddef>
#include <typeindex>
#include <iostream>
#include <list>
#include "IComponent.hpp"
#include "Transform.hpp"
#include "ECS/Script.hpp"
#include "Core/SceneManagerInternal.hpp"
#include "Core/Asserts.hpp"

namespace ecs
{
    class GameObject
    {
    public:
        GameObject(const std::string &name);
        GameObject(const GameObject &) noexcept;
        GameObject(GameObject &&) noexcept = default;
        virtual ~GameObject() noexcept = default;

        const std::string& getName() const noexcept;
        void setTag(const std::string &tag) noexcept;
        const std::string& getTag() const noexcept;
        void setActive(bool isActive) noexcept;
        bool getActive() const noexcept;
        ecs::Transform &transform() noexcept;

        const std::vector<std::unique_ptr<IComponent>>& getComponents() const noexcept;

        template <typename ComponentType, typename... Args>
        ComponentType &addComponent(Args&&... args)
        {
            static_assert(std::is_base_of<IComponent, ComponentType>(), "Given type doesn't inherit from ecs::IComponent.");
            INDIE_CORE_ASSERT(hasComponent<ComponentType>(), "Component already present");
            m_componentsType.emplace_back(typeid(ComponentType));
            auto &compptr = m_components.emplace_back(std::make_unique<ComponentType>(std::forward<Args>(args)...));
            indie::SceneManagerInternal::OnComponentAdded<ComponentType>(*this, *reinterpret_cast<ComponentType *>(compptr.get()));
            return *reinterpret_cast<ComponentType *>(compptr.get());
        }
        void addScript(std::unique_ptr<ecs::Script> script);

        template<typename ComponentType>
        ComponentType &getComponent()
        {
            ssize_t idx = findComponent(std::type_index{typeid(ComponentType)});
            if (idx == -1) {
                INDIE_CORE_ASSERT(true, "Component not found");
            }
            return **reinterpret_cast<std::unique_ptr<ComponentType> *>(&m_components[idx]);
        }
        template<typename ComponentType>
        ComponentType const &getComponent() const
        {
            ssize_t idx = findComponent(std::type_index{typeid(ComponentType)});
            if (idx == -1) {
                INDIE_CORE_ASSERT(true, "Component not found");
            }
            return **reinterpret_cast<std::unique_ptr<ComponentType> const *>(&m_components[idx]);
        }

        template<typename ComponentType>
        ComponentType &getScript()
        {
            auto it = std::find_if(m_scripts.begin(), m_scripts.end(),
                                [](auto &s) {
                                    return dynamic_cast<ComponentType *>(&*s) != nullptr;
                                });
            return *reinterpret_cast<ComponentType *>(&**it);
        }
        template<typename ComponentType>
        ComponentType const &getScript() const
        {
            auto it = std::find_if(m_scripts.begin(), m_scripts.end(),
                                [](auto &s) {
                                    return dynamic_cast<ComponentType *>(&*s) != nullptr;
                                });
            return *reinterpret_cast<ComponentType *>(&**it);
        }

        template<typename ComponentType>
        void removeComponent()
        {
            ssize_t idx = findComponent(std::type_index{typeid(ComponentType)});
            if (idx == -1) {
                INDIE_CORE_ASSERT(true, "Component not found");
            }
            indie::SceneManagerInternal::OnComponentRemoved(*this, m_componentsType[idx]);
            m_components.erase(m_components.begin() + idx);
            m_componentsType.erase(m_componentsType.begin() + idx);
        }

        template<typename ComponentType>
        bool hasComponent() const noexcept
        {
            return findComponent(std::type_index{typeid(ComponentType)}) != -1;
        }

        static GameObject &Instantiate(std::unique_ptr<GameObject> object);
        static GameObject &Instantiate(const GameObject &object);
        static GameObject &Instantiate(const GameObject &object, const utils::Vector3f &position);
        static GameObject &Instantiate(const GameObject &object, const utils::Vector3f &position, const utils::Vector3f &rotation);
        GameObject &InstantiateChild(std::unique_ptr<GameObject> object);
        GameObject &InstantiateChild(const GameObject &object);
        static void Destroy(GameObject &object);
        static GameObject *FindGameObjectByName(const std::string &name);
        GameObject *FindChildByName(const std::string &name);
        static GameObject &FindPrefabByName(const std::string &name);
        static std::list<ecs::GameObject *> FindGameObjectsByTag(const std::string &tag);

        GameObject &operator=(const GameObject &) noexcept = delete;
        GameObject &operator=(GameObject &&) noexcept = delete;
        bool operator==(const GameObject &other) const noexcept;

    protected:
        bool m_isActive;
        std::size_t m_uniqueId;
        std::string m_name;
        std::string m_tag;
        Transform *m_transform;
        GameObject *m_parent;
        std::vector<std::unique_ptr<GameObject>> m_children;
        std::vector<std::unique_ptr<IComponent>> m_components;
        std::vector<std::type_index> m_componentsType;
        std::vector<std::unique_ptr<ecs::Script>> m_scripts;

    private:
        ssize_t findComponent(const std::type_index &typeinfo) const noexcept;
        void activate() noexcept;

        static std::size_t uniqueIdCounter;
        friend indie::SceneManagerInternal;
        friend indie::Application;
        friend std::ostream& operator<<(std::ostream& stream, const GameObject& gameObject);
    };

    std::ostream& operator<<(std::ostream& stream, const GameObject& gameObject);
};
