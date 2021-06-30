/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Texture2D
*/

#include "Texture2D.hpp"

namespace Graphics
{
    Texture2D::Texture2D(std::string_view filepath, const utils::Vector2f &position, float rotation, float scale, utils::Color color) noexcept :
        position{position},
        rotation{rotation},
        scale{scale},
        color{color}
    {
        m_texture = ::LoadTexture(filepath.data());
    }

    Texture2D::Texture2D(std::string_view filepath, float x, float y, float rotation, float scale, utils::Color color) noexcept :
        position{x, y},
        rotation{rotation},
        scale{scale},
        color{color}
    {
        m_texture = ::LoadTexture(filepath.data());
    }

    Texture2D::Texture2D(const Image &image, const utils::Vector2f &position, float rotation, float scale, utils::Color color) noexcept :
        position{position},
        rotation{rotation},
        scale{scale},
        color{color}
    {
        m_texture = ::LoadTextureFromImage(image.m_image);
    }

    Texture2D::Texture2D(const Image &image, float x, float y, float rotation, float scale, utils::Color color) noexcept :
        position{x, y},
        rotation{rotation},
        scale{scale},
        color{color}
    {
        m_texture = ::LoadTextureFromImage(image.m_image);
    }

    Texture2D::Texture2D(Graphics::Texture2D &&other) noexcept :
        m_texture{other.m_texture},
        position{other.position},
        rotation{other.rotation},
        scale{other.scale},
        color{other.color}
    {
        other.m_texture = {};
    }

    Texture2D::~Texture2D() noexcept
    {
        ::UnloadTexture(m_texture);
    }

    void Texture2D::draw() const noexcept
    {
        ::Vector2 converted_position = (::Vector2){position.x, position.y};

        ::DrawTextureEx(m_texture, converted_position, rotation, scale,
                    CLITERAL(::Color){color.r, color.g, color.b, color.a});
    }

    utils::Vector2f Texture2D::getSize() const noexcept
    {
        utils::Vector2f size{m_texture.width, m_texture.height};
        return size * scale;
    }
}
