/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_inventory
*/

#include "server/request/handler.h"
#include "server/response/response.h"
#include "simulation/inventory.h"

void request_handler_cmd_inventory(server_t *s, client_t *c, request_t *r)
{
    unsigned int food = inventory_get_food_info(c->drone->inventory);
    unsigned int linemate = inventory_get_linemate_info(c->drone->inventory);
    unsigned int deraumere = inventory_get_deraumere_info(c->drone->inventory);
    unsigned int sibur = inventory_get_sibur_info(c->drone->inventory);
    unsigned int mendiane = inventory_get_mendiane_info(c->drone->inventory);
    unsigned int phiras = inventory_get_phiras_info(c->drone->inventory);
    unsigned int thystame = inventory_get_thystame_info(c->drone->inventory);

    client_add_response(c, response_create(RESPONSE_INVENTORY,
        food, linemate, deraumere, sibur,
        mendiane, phiras, thystame)
    );
}
