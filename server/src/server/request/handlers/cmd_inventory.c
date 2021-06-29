/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** cmd_inventory
*/

#include "server/request/handler.h"
#include "server/response/response.h"
#include "simulation/inventory.h"

void request_handler_cmd_inventory(__attribute__((unused))server_t *s,
                                client_t *c,
                                __attribute__((unused))request_t *r)
{
    unsigned int food = inventory_get_food_amount(c->drone->inventory);
    unsigned int linemate = inventory_get_linemate_amount(c->drone->inventory);
    unsigned int deraumere = inventory_get_deraumere_amount(c->drone->inventory);
    unsigned int sibur = inventory_get_sibur_amount(c->drone->inventory);
    unsigned int mendiane = inventory_get_mendiane_amount(c->drone->inventory);
    unsigned int phiras = inventory_get_phiras_amount(c->drone->inventory);
    unsigned int thystame = inventory_get_thystame_amount(c->drone->inventory);

    client_add_response(c, response_create(RESPONSE_INVENTORY,
        food, linemate, deraumere, sibur,
        mendiane, phiras, thystame)
    );
}
