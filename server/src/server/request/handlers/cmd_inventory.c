/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_inventory
*/

#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_cmd_inventory(server_t *s, client_t *c, request_t *r)
{
    response_t *response = NULL;
    const item_slot_t *food_slot = inventory_get_item_info(c->drone->inventory, RESOURCE_FOOD);
    unsigned int food_amount = food_slot ? food_slot->quantity : 0;
    const item_slot_t *linemate_slot = inventory_get_item_info(c->drone->inventory, RESOURCE_LINEMATE);
    unsigned int linemate_amount = linemate_slot ? linemate_slot->quantity : 0;
    const item_slot_t *deraumere_slot = inventory_get_item_info(c->drone->inventory, RESOURCE_DERAUMERE);
    unsigned int deraumere_amount = linemate_slot ? linemate_slot->quantity : 0;
    const item_slot_t *sibur_slot = inventory_get_item_info(c->drone->inventory, RESOURCE_SIBUR);
    unsigned int sibur_amount = linemate_slot ? linemate_slot->quantity : 0;
    const item_slot_t *mendiane_slot = inventory_get_item_info(c->drone->inventory, RESOURCE_MENDIANE);
    unsigned int mendiane_amount = linemate_slot ? linemate_slot->quantity : 0;
    const item_slot_t *phiras_slot = inventory_get_item_info(c->drone->inventory, RESOURCE_PHIRAS);
    unsigned int phiras_amount = phiras_slot ? phiras_slot->quantity : 0;
    const item_slot_t *thystame_slot = inventory_get_item_info(c->drone->inventory, RESOURCE_THYSTAME);
    unsigned int thystame_amount = thystame_slot ? thystame_slot->quantity : 0;

    client_add_response(c, response_create(RESPONSE_INVENTORY,
        food_amount, linemate_amount, deraumere_amount, sibur_amount,
        mendiane_amount, phiras_amount, thystame_amount));
}
