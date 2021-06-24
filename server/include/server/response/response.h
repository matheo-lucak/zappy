/*
** EPITECH PROJECT, 2021
** server
** File description:
** response
*/

#ifndef RESPONSE_H_
#define RESPONSE_H_

typedef struct response_s
{
    char *data;
} response_t;

response_t *response_create(const char *format, ...);
void response_destroy(response_t *response);

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

#define RESPONSE_INCANTATION_START  "Elevation underway\n"
#define RESPONSE_INCANTATION_ENDS   "Current level: %d\n"

// msz X Y\n
#define RESPONSE_MSZ                "msz %d %d\n"
// bct X Y q0 q1 q2 q3 q4 q5 q6\n
#define RESPONSE_BCT                "bct %d %d %d %d %d %d %d %d %d\n"
// bct X Y q0 q1 q2 q3 q4 q5 q6\n * nbr_tiles
#define RESPONSE_MCT                RESPONSE_BCT
// tna N\n * nbr_teams
#define RESPONSE_TNA                "tna %s\n"
// pnw #n X Y O L N\n
#define RESPONSE_PNW                "pnw %d %d %d %d %d %s\n"
// ppo n X Y O\n
#define RESPONSE_PPO                "ppo %d %d %d %d\n"
// plv n L\n
#define RESPONSE_PLV                "plv %d %d\n"
// pin n X Y q0 q1 q2 q3 q4 q5 q6\n
#define RESPONSE_PIN                "pin %d %d %d %d %d %d %d %d %d %d\n"
// pex n\n
#define RESPONSE_PEX                "pex %d\n"
// pbc n M\n
#define RESPONSE_PBC                "pbc %d %s\n"
// pic X Y L n n ...\n
#define RESPONSE_PIC                "pic %d %d %d ???\n"
// pie X Y R\n
#define RESPONSE_PIE                "pie %d %d %d\n"
// pfk n\n
#define RESPONSE_PFK                "pfk %d\n"
// pdr n i\n
#define RESPONSE_PDR                "pdr %d %d\n"
// pgt n i\n
#define RESPONSE_PGT                "pgt %n %i\n"
// pdi n\n
#define RESPONSE_PDI                "pdi %d\n"
// enw e n X Y\n
#define RESPONSE_ENW                "enw %d %d %d %d\n"
// eht e\n
#define RESPONSE_EHT                "eht %d\n"
// ebo e\n
#define RESPONSE_EBO                "ebo %e\n"
// edi e\n
#define RESPONSE_EDI                "edi %e\n"
// sgt T\n
#define RESPONSE_SGT                "sgt %d\n"
// sst T\n
#define RESPONSE_SST                "sst %d\n"
// seg N\n
#define RESPONSE_SEG                "seg %d\n"
// smg M\n
#define RESPONSE_SMG                "smg %d\n"
// suc\n
#define RESPONSE_SUC                "suc\n"
// sbp\n
#define RESPONSE_SBP                "sbp\n"


#endif /* !RESPONSE_H_ */
