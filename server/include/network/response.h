/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** response
*/

#ifndef RESPONSE_H_
#define RESPONSE_H_

typedef enum response_type_e
{
    REP_OK,                 // No body
    REP_KO,                 // No body
    REP_LOOK,               //
    REP_INVENTORY,          //
    REP_CONNECT_NBR,        //
    REP_DEAD,               // No body
    REP_INCANTATION_START,  // No body
    REP_INCANTATION_END,    //
} response_type_t;

#endif /* !RESPONSE_H_ */
