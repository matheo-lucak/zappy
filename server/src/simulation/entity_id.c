/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** entity_id
*/

int get_next_entity_id(void)
{
    static unsigned id = 0;

    id++;
    return id;
}