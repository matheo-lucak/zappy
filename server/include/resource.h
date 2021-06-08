/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** resource
*/

#ifndef RESOURCE_H_
#define RESOURCE_H_

typedef enum
{
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,

    // This enumerate must stay the last
    RESOURCE_NB
} resource_t;

typedef float density_t;

typedef struct resource_info_s
{
    resource_t  type;
    density_t   density;
} resource_info_t;

#endif /* !RESOURCE_H_ */
