/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

typedef enum command_type_e
{
    CMD_FORWARD,
    CMD_RIGHT,
    CMD_LEFT,
    CMD_LOOK,
    CMD_INVENTORY,
    CMD_BROADCAST,
    CMD_CONNECT_NBR,
    CMD_FORK,
    CMD_EJECT,
    CMD_TAKE,
    CMD_SET_OBJECT,
    CMD_INCANTATION
} command_type_t;

#endif /* !COMMANDS_H_ */
