/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container_merge
*/

#include "mylist/container.h"

void container_merge(container_list_t *list1, container_list_t *list2)
{
    if (list1->size == 0) {
        list1->start = list2->start;
        list1->end = list2->end;
        list1->size = list2->size;
    } else if (list2->size > 0) {
        list1->end->next = list2->start;
        list2->start->previous = list1->end;
        list1->end = list2->end;
        list1->size += list2->size;
    }
    list2->size = 0;
    list2->start = NULL;
    list2->end = NULL;
}