/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Model
*/

#pragma once

#include <string_view>
#include <raylib.h>
#include "IDrawable.hpp"
#include "Mesh.hpp"
#include "Texture2D.hpp"
#include "Vector3.hpp"
#include "Color.hpp"

namespace ecs
{
    class Model;
} // namespace ecs


namespace Graphics
{
    class Model : public IDrawable3D
    {
        friend class ModelAnimator;

    protected:
        ::Model m_model;

    public:
        utils::Vector3f position;
        utils::Vector3f rotation_axis;
        float rotation_angle;
        utils::Vector3f scaling;
        utils::Color color{utils::Color::White};

    public:
        Model(std::string_view filepath, const utils::Vector3f &position = utils::Vector3f::zero(), const utils::Vector3f &rotation_axis = utils::Vector3f{1.0f, 0.0f, 0.0f}, float rotation_angle = 0.0f, const utils::Vector3f &scaling = utils::Vector3f::one()) noexcept;
        Model(std::string_view filepath, float x, float y, float z, const utils::Vector3f &rotation_axis = utils::Vector3f{1.0f, 0.0f, 0.0f}, float rotation_angle = 0.0f, const utils::Vector3f &scaling = utils::Vector3f::one()) noexcept;
        Model(const Mesh &mesh, const utils::Vector3f &position = utils::Vector3f::zero(), const utils::Vector3f &rotation_axis = utils::Vector3f{1.0f, 0.0f, 0.0f}, float rotation_angle = 0.0f, const utils::Vector3f &scaling = utils::Vector3f::one()) noexcept;
        Model(const Mesh &mesh, float x, float y, float z, const utils::Vector3f &rotation_axis = utils::Vector3f{1.0f, 0.0f, 0.0f}, float rotation_angle = 0.0f, const utils::Vector3f &scaling = utils::Vector3f::one()) noexcept;
        Model(const Model &) noexcept = default;
        Model(Model &&other) noexcept;
        ~Model() noexcept;

        Model &operator=(const Model &) noexcept = default;
        Model &operator=(Model &&other) noexcept;

        void setMaterialTexture(const Texture2D &texture) noexcept;
        void setRotation(utils::Vector3f) noexcept;

        friend ecs::Model;

    protected:
        void draw() const noexcept override;
    };
}
