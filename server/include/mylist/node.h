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
    int hold_ptr;
} data_node_t;

typedef void (*node_dtor_t)(void *);

typedef int (*node_cmp_t)(const void *, const void *);

typedef struct node_list
{
    data_node_t data;
    struct node_list *previous;
    struct node_list *next;
} node_t;

///////////// Macros to get a data from a node_t struct pointer /////////////

static inline void *wrapper_node_ptr_getter(const node_t *node)
{
    const data_node_t *data = &node->data;

    return (data->hold_ptr) ? (*((void **)(data->ptr))) : data->ptr;
}

// Get the pointer to the data inside the node
// In case of node from ptr_list_t, returns the pointer within the node
#define NODE_PTR(node, type) ((type *)wrapper_node_ptr_getter(node))

// Get the value of the data inside the node
// In case of node from ptr_list_t, dereferences the pointer within the node
#define NODE_DATA(node, type) (*((type *)wrapper_node_ptr_getter(node)))
/////////////////////////////////////////////////////////////////////////////

#endif /* !NODE_H_ */
