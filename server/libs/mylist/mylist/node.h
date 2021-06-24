/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** node
*/

#ifndef MY_LIST_NODE_H_
#define MY_LIST_NODE_H_

#include <stddef.h>

typedef struct data_node
{
    void *ptr;
    size_t size;
} data_node_t;

typedef void (*node_dtor_t)(void *);

typedef int (*node_cmp_t)(const void *, const void *);

typedef struct node_list
{
    data_node_t data;
    size_t index;
    struct node_list *previous;
    struct node_list *next;
} node_t;

///////////// Macros to get a data from a node_t struct pointer /////////////

// Get the pointer to the data inside the node
// In case of node from ptr_list_t, returns the pointer within the node
#define NODE_PTR(node, type) ((type *)((node)->data.ptr))

// Get the value of the data inside the node
// In case of node from ptr_list_t, dereferences the pointer within the node
#define NODE_DATA(node, type) (*((type *)((node)->data.ptr)))
/////////////////////////////////////////////////////////////////////////////

#endif /* !NODE_H_ */
