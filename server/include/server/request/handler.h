/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** handler
*/

#ifndef HANDLER_H_
#define HANDLER_H_

#include "server/server.h"

typedef struct request_s request_t;

typedef void (*request_handler_t)(
    server_t *,
    client_t *,
    request_t *
);

void request_handler_default(server_t *s, client_t *c, request_t *r);

void request_handler_cmd_forward(server_t *, client_t *, request_t *);
void request_handler_cmd_right(server_t *, client_t *, request_t *);
void request_handler_cmd_left(server_t *, client_t *, request_t *);
void request_handler_cmd_look(server_t *, client_t *, request_t *);
void request_handler_cmd_inventory(server_t *, client_t *, request_t *);
void request_handler_cmd_broadcast(server_t *, client_t *, request_t *);
void request_handler_cmd_connect_nbr(server_t *, client_t *, request_t *);
void request_handler_cmd_fork(server_t *, client_t *, request_t *);
void request_handler_cmd_eject(server_t *, client_t *, request_t *);
void request_handler_cmd_take(server_t *, client_t *, request_t *);
void request_handler_cmd_set(server_t *, client_t *, request_t *);
void request_handler_cmd_incantation(server_t *, client_t *, request_t *);

void request_handler_gui_map_size(server_t *, client_t *, request_t *);
void request_handler_gui_tile_content(server_t *, client_t *, request_t *);
void request_handler_gui_map_content(server_t *, client_t *, request_t *);
void request_handler_gui_team_names(server_t *, client_t *, request_t *);
void request_handler_gui_player_position(server_t *, client_t *, request_t *);
void request_handler_gui_player_level(server_t *, client_t *, request_t *);
void request_handler_gui_player_inventory(server_t *, client_t *, request_t *);
void request_handler_gui_time_unit_request(server_t *, client_t *, request_t *);
void request_handler_gui_time_unit_modif(server_t *, client_t *, request_t *);

#endif /* !HANDLER_H_ */
