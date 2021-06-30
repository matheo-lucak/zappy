/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Model
*/

#include "raymath.h"
#include "Model.hpp"

namespace Graphics
{
    Model::Model(std::string_view filepath, const utils::Vector3f &position, const utils::Vector3f &rotation_axis, float rotation_angle, const utils::Vector3f &scale) noexcept :
        position{position},
        rotation_axis{rotation_axis},
        rotation_angle{rotation_angle},
        scaling{scale}
    {
        m_model = ::LoadModel(filepath.data());
    }

    Model::Model(std::string_view filepath, float x, float y, float z, const utils::Vector3f &rotation_axis, float rotation_angle, const utils::Vector3f &scale) noexcept :
        position{x, y, z},
        rotation_axis{rotation_axis},
        rotation_angle{rotation_angle},
        scaling{scale}
    {
        m_model = ::LoadModel(filepath.data());
    }

    Model::Model(const Mesh &mesh, const utils::Vector3f &position, const utils::Vector3f &rotation_axis, float rotation_angle, const utils::Vector3f &scale) noexcept :
        position{position},
        rotation_axis{rotation_axis},
        rotation_angle{rotation_angle},
        scaling{scale}
    {
        m_model = ::LoadModelFromMesh(mesh.m_mesh);
    }

    Model::Model(const Mesh &mesh, float x, float y, float z, const utils::Vector3f &rotation_axis, float rotation_angle, const utils::Vector3f &scale) noexcept :
        position{x, y, z},
        rotation_axis{rotation_axis},
        rotation_angle{rotation_angle},
        scaling{scale}
    {
        m_model = ::LoadModelFromMesh(mesh.m_mesh);
    }

    Model::Model(Model &&other) noexcept
    {
        m_model = other.m_model;
        position = other.position;
        rotation_axis = other.rotation_axis;
        rotation_angle = other.rotation_angle;
        scaling = other.scaling;
        other.m_model = {};
    }

    Model::~Model() noexcept
    {
        ::UnloadModelKeepMeshes(m_model);
    }

    Model &Model::operator=(Model &&other) noexcept
    {
        m_model = other.m_model;
        position = other.position;
        rotation_axis = other.rotation_axis;
        rotation_angle = other.rotation_angle;
        scaling = other.scaling;
        other.m_model = {};
        return *this;
    }

    void Model::setMaterialTexture(const Texture2D &texture) noexcept
    {
        ::SetMaterialTexture(&m_model.materials[0], MAP_DIFFUSE, texture.m_texture);
    }

    void Model::setRotation(utils::Vector3f rotation_axis) noexcept
    {
        ::Vector3 converted_rotation_axis = (::Vector3){DEG2RAD * rotation_axis.x, DEG2RAD * rotation_axis.y, DEG2RAD * rotation_axis.z};

        m_model.transform = MatrixRotateXYZ(converted_rotation_axis);
    }


    void Model::draw() const noexcept
    {
        ::Vector3 converted_position = (::Vector3){position.x, position.y, position.z};
        ::Vector3 converted_scale = (::Vector3){scaling.x, scaling.y, scaling.z};
        ::Color   converted_color = (::Color){color.r, color.g, color.b, color.a};

        ::DrawModel(m_model, converted_position, converted_scale.x, converted_color);
    }
}
