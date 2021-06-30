/*
** EPITECH PROJECT, 2021
** IndieStudio [WSL: Ubuntu]
** File description:
** Mesh
*/

#pragma once

#include <raylib.h>

namespace Graphics
{
    class Mesh
    {
        friend class Model;
    
    private:
        ::Mesh m_mesh;

    public:
        Mesh();
        ~Mesh();
    };
}
