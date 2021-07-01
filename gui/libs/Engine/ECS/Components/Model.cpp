/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Model
*/

#include "Model.hpp"
#include "ECS/GameObject.hpp"

ecs::Model::Model(ecs::GameObject &gameObject, std::string_view path) noexcept : m_tr{&gameObject.transform()}
{
    m_model = std::make_shared<Graphics::Model>(path);
}

ecs::Model::Model(ecs::GameObject &gameObject, std::string_view path, std::string_view texturePath) noexcept : m_tr{&gameObject.transform()}
{
    m_model = std::make_shared<Graphics::Model>(path);
    if (texturePath != "") {
        m_texture = std::make_shared<Graphics::Texture2D>(texturePath);
        m_model->setMaterialTexture(*m_texture);
    }
}

ecs::Model::Model(const ecs::Model &other) noexcept : m_tr{other.m_tr}, m_model{other.m_model}, m_texture{other.m_texture}
{
}

ecs::Model::Model(ecs::Model &&other) noexcept : m_tr{other.m_tr}, m_model{std::move(other.m_model)}, m_texture{std::move(other.m_texture)}
{
}

ecs::Model &ecs::Model::operator=(const Model &other) noexcept
{
    m_model = other.m_model;
    m_texture = other.m_texture;
    return *this;
}

ecs::Model &ecs::Model::operator=(Model &&other) noexcept
{
    m_model = std::move(other.m_model);
    m_texture = std::move(other.m_texture);
    return *this;
}

void ecs::Model::draw() const noexcept
{
    auto pos = m_model->position;
    auto scale = m_model->scaling;
    auto roation_axis = m_model->rotation_angle;
    auto m = const_cast<Graphics::Model *>(m_model.get());

    m->position += m_tr->getPosition();
    m->scaling *= m_tr->getScale();
    m->setRotation(m_tr->getRotation());
    m_model->draw();
    m->position = pos;
    m->scaling = scale;
    m->setRotation(roation_axis);
}

utils::Vector3f &ecs::Model::position() noexcept
{
    return m_model->position;
}

utils::Vector3f &ecs::Model::rotationAxis() noexcept
{
    return m_model->rotation_axis;
}

float &ecs::Model::rotationAngle() noexcept
{
    return m_model->rotation_angle;
}

utils::Vector3f &ecs::Model::scaling() noexcept
{
    return m_model->scaling;
}

utils::Color &ecs::Model::color() noexcept
{
    return m_model->color;
}

void ecs::Model::setRotation(utils::Vector3f rotation_axis)
{
    m_tr->setRotation(rotation_axis);
}

std::unique_ptr<ecs::IComponent> ecs::Model::copy(ecs::GameObject &copyOn) const noexcept
{
    auto res = std::make_unique<ecs::Model>(*this);
    res->m_tr = &copyOn.transform();
    return res;
}

void ecs::Model::display(std::ostream& stream) const
{
    stream << "Model:" << std::endl;
    stream << "\tscale: " << m_model->scaling << std::endl;
    stream << "\tposition: " << m_model->position << std::endl;
    stream << "\trotation axis: " << m_model->rotation_axis << std::endl;
    stream << "\trotation angle: " << m_model->rotation_angle << std::endl;
}