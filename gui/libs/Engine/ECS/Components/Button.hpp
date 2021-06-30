/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Button
*/

#pragma once

#include <functional>
#include <memory>

#include "IComponent.hpp"
#include "Utils.hpp"

namespace ecs
{
    class Transform;
    class Image;

    class Button : public IComponent {
        public:
            Button(GameObject &gameObject) noexcept;
            Button(const Button &) = default;
            Button(Button &&) noexcept = default;
            ~Button() noexcept override = default;

            template <typename Callable, typename... Args>
            void setCallback(Callable&& callback, Args&&... args) noexcept
            {
                if constexpr (std::is_invocable_v<Callable, Args...>) {
                    m_callback = CallBack<Callable, Args...>{std::forward<Callable>(callback), std::forward<Args>(args)...};
                }
            }
            void setCallback(std::nullptr_t) noexcept;
            void operator()() const;

            void setSize(const utils::Vector2f &size) noexcept;
            utils::Vector2f const &getSize() const noexcept;
            void setOrigin(const utils::Vector2f &origin) noexcept;
            utils::Vector2f const &getOrigin() const noexcept;

            void update() noexcept;
            bool isHover(const utils::Vector2f &pos) const noexcept;

            Button &operator=(const Button &) noexcept = delete;
            Button &operator=(Button &&) noexcept = delete;

            std::unique_ptr<IComponent> copy(GameObject &copyOn) const noexcept override;
            void display(std::ostream& stream) const override;

            utils::Color colorHover;
            utils::Color colorPressed;
            utils::Color colorHold;

        protected:
        private:
            template <typename Callable, typename... Args>
            class CallBack {
                public:
                    CallBack(Callable&& func, Args&&... args) noexcept :
                        m_callback(std::forward<std::decay_t<Callable>>(func)),
                        m_args(std::forward<Args>(args)...)
                    {};
                    CallBack(const CallBack &) noexcept = default;
                    CallBack(CallBack &&) noexcept = default;
                    ~CallBack() noexcept = default;
            
                    CallBack &operator=(const CallBack &) noexcept = default;
                    CallBack &operator=(CallBack &&) noexcept = default;
            
                    void operator()() const
                    {
                        if constexpr (std::is_invocable_v<Callable, Args...>) {
                            std::apply(m_callback, m_args);
                        }
                    }

                protected:
                private:
                    static_assert(std::is_invocable_v<Callable, Args...>, "Not  invocable");

                    std::decay_t<Callable> m_callback;
                    std::tuple<Args...> m_args;
            };

            Transform *m_tr;
            ecs::Image *m_img;
            std::function<void()> m_callback;
            utils::Vector2f m_size;
            utils::Vector2f m_origin;
    };
} // namespace ecs
