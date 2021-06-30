/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** BoxCollider
*/

#include "BoxCollider.hpp"
#include "ECS/GameObject.hpp"

namespace ecs
{
    BoxCollider::BoxCollider(ecs::Transform &transform) noexcept :
        m_tr{&transform},
        center{0, 0, 0},
        size{1},
        m_isStatic{false},
        m_isTrigger{false}
    {
    }

    std::optional<utils::Rectangle3> BoxCollider::collide(const ecs::BoxCollider &other) noexcept
    {
        utils::Vector3f abscenter = this->center + m_tr->getPosition();
        utils::Vector3f abssize = size * m_tr->getScale();
        utils::Vector3f otherCenter = other.getCenter() + other.m_tr->getPosition();
        const utils::Vector3f &otherSize = other.getSize() * other.m_tr->getScale();
        utils::Rectangle3 intersection;

        if (otherCenter.x - otherSize.x / 2 > abscenter.x + abssize.x / 2 || otherCenter.x + otherSize.x / 2 < abscenter.x - abssize.x / 2 ||
            otherCenter.y - otherSize.y / 2 > abscenter.y + abssize.y / 2 || otherCenter.y + otherSize.y / 2 < abscenter.y - abssize.y / 2 ||
            otherCenter.z - otherSize.z / 2 > abscenter.z + abssize.z / 2 || otherCenter.z + otherSize.z / 2 < abscenter.z - abssize.z / 2) {
            return {};
        }
        intersection.min.x = std::max(abscenter.x - abssize.x / 2, otherCenter.x - otherSize.x / 2);
        intersection.min.y = std::max(abscenter.y - abssize.y / 2, otherCenter.y - otherSize.y / 2);
        intersection.min.z = std::max(abscenter.z - abssize.z / 2, otherCenter.z - otherSize.z / 2);
        intersection.max.x = std::min(abscenter.x + abssize.x / 2, otherCenter.x + otherSize.x / 2);
        intersection.max.y = std::min(abscenter.y + abssize.y / 2, otherCenter.y + otherSize.y / 2);
        intersection.max.z = std::min(abscenter.z + abssize.z / 2, otherCenter.z + otherSize.z / 2);
        return intersection;
    }

    utils::Vector3f const &BoxCollider::getCenter(void) const noexcept
    {
        return this->center;
    }

    utils::Vector3f const &BoxCollider::getSize(void) const noexcept
    {
        return this->size;
    }

    void BoxCollider::setCenter(const utils::Vector3f &newCenter) noexcept
    {
        this->center = newCenter;
    }

    void BoxCollider::setSize(const utils::Vector3f &newSize) noexcept
    {
        this->size = newSize;
    }

    bool BoxCollider::isStatic() const noexcept
    {
        return this->m_isStatic;
    }

    void BoxCollider::setIsStatic(bool isStatic) noexcept
    {
        this->m_isStatic = isStatic;
    }

    bool BoxCollider::isTrigger() const noexcept
    {
        return m_isTrigger;
    }

    void BoxCollider::setIsTrigger(bool isTrigger) noexcept
    {
        m_isTrigger = isTrigger;
    }

    std::unique_ptr<IComponent> BoxCollider::copy(ecs::GameObject &copyOn) const noexcept
    {
        auto res = std::make_unique<BoxCollider>(*this);
        res->m_tr = &copyOn.transform();
        return res;
    }

    void BoxCollider::display(std::ostream& stream) const
    {
        stream << "BoxCollider: ";
        if (this->m_isStatic) {
            stream << "[X] Static";
        } else {
            stream << "[ ] Dynamic";
        }
        stream << std::endl;
        stream << "\tcenter = " << this->center << std::endl;
        stream << "\tsize   = " << this->size << std::endl;
    }
}