/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** response
*/

#ifndef ZAPPY_RESPONSE_H_
#define ZAPPY_RESPONSE_H_

typedef struct response_s
{
    char *data;
} response_t;

#define RESPONSE_WELCOME            "WELCOME\n"
#define RESPONSE_CLIENT_NUM         "%d\n"
#define RESPONSE_XY                 "%d %d\n"

#define RESPONSE_OK                 "ok\n"
#define RESPONSE_KO                 "ko\n"
#define RESPONSE_DEAD               "dead\n"

#define RESPONSE_LOOK               "[ %s ]\n"
#define RESPONSE_INVENTORY          "[ food %d, linemate %d, deraumere %d,"\
                                    " sibur %d, mendiane %d, phiras %d,"\
                                    " thystame %d ]\n"

#define RESPONSE_BROADCAST          "message %d, %s\n"

#define RESPONSE_EJECT              "eject: %d\n"

#define RESPONSE_INCANTATION        "Elevation underway\n"
#define RESPONSE_ELEVATION          "Current level: %d\n"

///////////////////
// GUI Responses //
///////////////////

////////////////////////////////////////////////////////////////////////////////
// RESPONSE FROM SERVER ///////////////////// REQUEST /// DESCRIPTION //////////
////////////////////////////////////////////////////////////////////////////////

// msz X Y\n                                - msz\n     - map size
#define RESPONSE_MSZ "msz %d %d\n"

// bct X Y q0 q1 q2 q3 q4 q5 q6\n           - bct X Y\n - content of a tile
#define RESPONSE_BCT "bct %d %d %d %d %d %d %d %d %d\n"

// bct X Y q0 q1 q2 q3 q4 q5 q6\n * nbr_tiles mct\n     - content of the map
//                                                        (all the tiles)
#define RESPONSE_MCT RESPONSE_BCT

// tna N\n * nbr_teams                      - tna\n     - name of all the teams
#define RESPONSE_TNA "tna %s\n"

// ppo n X Y O\n                            - ppo #n\n  - player’s position
#define RESPONSE_PPO "ppo %d %d %d %d\n"

// pst n L q0 q1 q2 q3 q4 q5 q6\n           - pst #n\n  - player’s stats
#define RESPONSE_PST "pst %d %d %d %d %d %d %d %d\n"

// pnw #n X Y O L N\n                                   - connection of
//                                                        a new player
#define RESPONSE_PNW "pnw %d %d %d %d %d %s\n"

// pex n\n                                              - expulsion
#define RESPONSE_PEX "pex %d\n"

// pbc n M\n                                            - broadcast
#define RESPONSE_PBC "pbc %d %s\n"

// pic X Y L n q1 q2 q3 q4 q5 q6\n                      - start of
//                                                        an incantation
#define RESPONSE_PIC "pic %d %d %d %d %d %d %d %d %d %d\n"

// pie X Y R\n                                          - end of an incantation
#define RESPONSE_PIE "pie %d %d %d\n"

// pfk n\n                                              - egg laying
//                                                        by the player
#define RESPONSE_PFK "pfk %d\n"

// enw e n X Y\n                                        - an egg was laid
//                                                        by a player
#define RESPONSE_ENW "enw %d %d %d %d\n"

// eht e\n                                              - egg hatching
#define RESPONSE_EHT "eht %d\n"

// ebo e\n                                              - player connection
//                                                        for an egg
#define RESPONSE_EBO "ebo %e\n"

// edi e\n                                              - death of
//                                                        an hatched egg
#define RESPONSE_EDI "edi %e\n"

// pdr n i\n                                            - resource dropping
#define RESPONSE_PDR "pdr %d %d\n"

// pgt n i\n                                            - resource collecting
#define RESPONSE_PGT "pgt %n %i\n"

// pdi n\n                                              - death of a player
#define RESPONSE_PDI "pdi %d\n"

// sgt T\n                                  - sgt\n     - time unit request
#define RESPONSE_SGT "sgt %d\n"

// seg N\n                                              - end of game
#define RESPONSE_SEG "seg %d\n"

////////////////////////////////////////////////////////////////////////////////


/**
* @brief Instantiates a response and its data.
*
* @param format The string format to use in the data.
* @param ... The arguments to format into the format string.
* @return response_t* A pointer to the newly allocated response.
*/
response_t *response_create(const char *format, ...);

/**
* @brief Deep copy a given response.
*
* @param other The response to deep copy.
* @return response_t* A pointer to the newly allocated response.
*/
response_t *response_clone(response_t *other);

/**
* @brief Releases memory previously allocated to a response.
*
* @param response The response to release memory from.
*/
void response_destroy(response_t *response);

#endif /* !ZAPPY_RESPONSE_H_ */
