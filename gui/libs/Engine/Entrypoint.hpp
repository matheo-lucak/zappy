/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Entrypoint
*/

#pragma once

#include <cstdlib>

#include "Core/Application.hpp"
#include "Core/Exceptions/ArgumentHelpException.hpp"
#include "Core/Exceptions/ArgumentParsingError.hpp"

int main(int ac, char **av)
{
    std::unique_ptr<zappy::Application> app = nullptr;

    std::srand(std::time(nullptr));

    try {
        app = CreateApplication({static_cast<unsigned int>(ac), av});
    } catch (zappy::ArgumentParsingError &e) {
        std::cout << e.what() << std::endl;
        return 84;
    } catch (zappy::ArgumentHelpException &e) {
        return 0;
    }
    app->run();
    return 0;
}
