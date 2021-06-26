/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container
*/

#ifndef MY_LIST_CONTAINER_H_
#define MY_LIST_CONTAINER_H_

#include "node.h"

typedef struct linked_list_container
{
    node_t *start;
    node_t *end;
    size_t size;
    node_dtor_t __dtor__;
} container_list_t;

///////////// Functions to implement a container /////////////
int container_add_node_at_start(container_list_t *list, node_t *element);

int container_add_node_at_end(container_list_t *list, node_t *element);

int container_add_node(container_list_t *list, node_t *node, long index);

node_t *container_get_node(const container_list_t *list, long index);

void container_merge(container_list_t *list1, container_list_t *list2);

node_t *container_remove_first_node(container_list_t *list);

node_t *container_remove_last_node(container_list_t *list);

node_t *container_remove_node(container_list_t *list, long index);

void container_reverse(container_list_t *list);

void container_rotate_begin(container_list_t *list);

void container_rotate_end(container_list_t *list);
/////////////////////////////////////////////////////////////////////////////

#endif /* !MY_LIST_CONTAINER_H_ */
