/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** IComponent
*/

#pragma once

#include <memory>
#include <ostream>

namespace ecs
{
    class GameObject;

    class IComponent
    {
    public:
        virtual ~IComponent() noexcept = default;

        virtual std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept = 0;
        virtual void display(std::ostream& stream) const = 0;
    };

    inline std::ostream& operator<<(std::ostream& stream, const IComponent& component)
    {
        component.display(stream);
        return stream;
    }
};
