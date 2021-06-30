/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-guillaume.bogard-coquard
** File description:
** Entrypoint
*/

#pragma once

#include <cstdlib>

#include "Core/Application.hpp"
#include "Core/Exceptions/ArgumentHelpException.hpp"
#include "Core/Exceptions/ArgumentParsingError.hpp"

indie::Application *indie::Application::application = nullptr;

int main(int ac, char **av)
{
    std::unique_ptr<indie::Application> app = nullptr;

    std::srand(std::time(nullptr));

    try {
        app = CreateApplication({static_cast<unsigned int>(ac), av});
    } catch (indie::ArgumentParsingError &e) {
        std::cout << e.what() << std::endl;
        return 84;
    } catch (indie::ArgumentHelpException &e) {
        return 0;
    }
    app->run();
    return 0;
}
