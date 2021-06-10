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

void container_clear(container_list_t *list);

void container_delete_first_node(container_list_t *list);

void container_delete_last_node(container_list_t *list);

void container_delete_node(container_list_t *list, long index);

node_t *container_get_node(const container_list_t *list, long index);

void container_merge(container_list_t *list1, container_list_t *list2);

node_t *container_remove_first_node(container_list_t *list);

node_t *container_remove_last_node(container_list_t *list);

node_t *container_remove(container_list_t *list, long index);

void container_reverse(container_list_t *list);

void container_rotate_begin(container_list_t *list);

void container_rotate_end(container_list_t *list);

node_t *create_empty_node(size_t size);

node_t *create_node(const void *data, size_t size);

node_t *create_ptr_node(void *ptr);

node_t *create_string_node(const char *str);

void destroy_node(node_t *node, node_dtor_t destructor);
/////////////////////////////////////////////////////////////////////////////

#endif /* !MY_LIST_CONTAINER_H_ */
