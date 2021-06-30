/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** GameObject
*/

#include "GameObject.hpp"
#include <stdexcept>

namespace ecs
{
    std::size_t GameObject::uniqueIdCounter{0};

    GameObject::GameObject(const std::string &name):
        m_isActive(true), m_uniqueId{++uniqueIdCounter}, m_name(name)
    {
        m_transform = &addComponent<Transform>();
    }

    GameObject::GameObject(const GameObject &other) noexcept :
        m_isActive(other.m_isActive), m_uniqueId{++uniqueIdCounter}, m_name(other.m_name), m_tag(other.m_tag)
    {
        addComponent<Transform>(other.getComponent<Transform>());
        m_transform = &getComponent<Transform>();
        for (std::size_t i = 1; i < other.m_components.size(); ++i) {
            m_componentsType.emplace_back(other.m_componentsType[i]);
            m_components.emplace_back(other.m_components[i]->copy(*this));
            zappy::SceneManagerInternal::OnComponentAdded(*this, *m_components[i], other.m_componentsType[i]);
        }
        for (const auto &script : other.m_scripts) {
            m_scripts.emplace_back(script->copy(*this));
        }
        for (const auto &child : other.m_children) {
            m_children.emplace_back(std::make_unique<GameObject>(*child));
        }
        m_parent = other.m_parent;
    }

    const std::string& GameObject::getName() const noexcept
    {
        return m_name;
    }

    void GameObject::setTag(const std::string &tag) noexcept
    {
        m_tag = tag;
    }

    const std::string& GameObject::getTag() const noexcept
    {
        return m_tag;
    }

    void GameObject::setActive(bool isActive) noexcept
    {
        if (m_isActive == isActive) return;

        if (isActive == false) {
            m_isActive = false;
            for (auto &type : m_componentsType) {
                zappy::SceneManagerInternal::OnComponentRemoved(*this, type);
            }
            for (auto &child : m_children) {
                child->setActive(false);
            }
            return;
        }
        zappy::SceneManagerInternal::CommissionObject(*this);
    }

    void GameObject::activate() noexcept
    {
        m_isActive = true;
        for (size_t i = 0; i < m_components.size(); ++i) {
            zappy::SceneManagerInternal::OnComponentAdded(*this, *m_components[i], m_componentsType[i]);
        }
        for (auto &script : m_scripts) {
            script->Awake();
        }
        for (auto &child : m_children) {
            child->activate();
        }
    }

    bool GameObject::getActive() const noexcept
    {
        return m_isActive;
    }

    ecs::Transform &GameObject::transform() noexcept
    {
        return *m_transform;
    }

    void GameObject::addScript(std::unique_ptr<ecs::Script> script)
    {
        auto &btn = m_scripts.emplace_back(std::move(script));
        if (m_isActive) {
            btn->Awake();
            btn->Start();
        }
    }

    const std::vector<std::unique_ptr<IComponent>>& GameObject::getComponents() const noexcept
    {
        return m_components;
    }

    GameObject &GameObject::Instantiate(std::unique_ptr<GameObject> object)
    {
        return zappy::SceneManagerInternal::InstantiateObject(std::move(object));
    }

    GameObject &GameObject::Instantiate(const GameObject &object)
    {
        return zappy::SceneManagerInternal::InstantiateObject(std::make_unique<GameObject>(object));
    }

    GameObject &GameObject::Instantiate(const GameObject &object, const utils::Vector3f &position)
    {
        return zappy::SceneManagerInternal::InstantiateObject(std::make_unique<GameObject>(object), position);
    }

    GameObject &GameObject::Instantiate(const GameObject &object, const utils::Vector3f &position, const utils::Vector3f &rotation)
    {
        return zappy::SceneManagerInternal::InstantiateObject(std::make_unique<GameObject>(object), position, rotation);
    }

    GameObject &GameObject::InstantiateChild(std::unique_ptr<GameObject> object)
    {
        auto &obj = *m_children.emplace_back(std::move(object));
        for (std::size_t i = 0; i < obj.m_components.size(); ++i) {
            zappy::SceneManagerInternal::OnComponentAdded(obj, *obj.m_components[i], obj.m_componentsType[i]);
        }
        return obj;
    }

    GameObject &GameObject::InstantiateChild(const GameObject &object)
    {
        return *m_children.emplace_back(std::make_unique<GameObject>(object));
    }

    void GameObject::Destroy(GameObject &object)
    {
        zappy::SceneManagerInternal::AskDestroyObject(object);
    }

    GameObject *GameObject::FindGameObjectByName(const std::string &name)
    {
        return zappy::SceneManagerInternal::FindGameObjectByName(name);
    }

    GameObject *GameObject::FindChildByName(const std::string &name)
    {
        return zappy::SceneManagerInternal::FindGameObjectByNameInList(name, m_children);
    }

    GameObject &GameObject::FindPrefabByName(const std::string &name)
    {
        return zappy::SceneManagerInternal::FindPrefabByName(name);
    }

    std::list<ecs::GameObject *> GameObject::FindGameObjectsByTag(const std::string &tag)
    {
        return zappy::SceneManagerInternal::FindGameObjectsByTag(tag);
    }

    bool GameObject::operator==(const GameObject &other) const noexcept
    {
        return m_uniqueId == other.m_uniqueId;
    }

    ssize_t GameObject::findComponent(const std::type_index &typeinfo) const noexcept
    {
        for (std::size_t i = 0; i < m_componentsType.size(); ++i) {
            if (typeinfo == m_componentsType[i]) {
                return i;
            }
        }
        return -1;
    }

    std::ostream& operator<<(std::ostream& stream, const GameObject& gameObject)
    {
        stream << "GameObject: Name = '" << gameObject.getName() << '\'';
        if (!gameObject.getTag().empty()) {
            stream << "  Tag = '" << gameObject.getTag() << '\'';
        }
        if (gameObject.getActive()) {
            stream << " [X] Active";
        } else {
            stream << " [ ] Off";
        }
        stream << '\n';

        auto& components = gameObject.getComponents();

        if (components.empty()) {
            stream << "No component.";
        } else {
            stream << "Components:\n";
            for (auto it = components.begin(); it != components.end(); it++) {
                stream << *(it->get());
                if (it < components.end() - 1)
                    stream << '\n';
            }
        }
        stream << "\nChilds (" << gameObject.m_children.size() << "):" << '\n';
        for (const auto &child : gameObject.m_children) {
            stream << *child;
        }
        return stream;
    }
};
