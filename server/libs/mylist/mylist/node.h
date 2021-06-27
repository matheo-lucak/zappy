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

///////////// Functions to create/destroy a node /////////////
// Allocate a node with a zero-initialized memory of size bytes
node_t *create_empty_node(size_t size);

// Create a node with a copy of data which is size bytes long
node_t *create_node(const void *data, size_t size);

// Create a node and store the pointer as data
node_t *create_ptr_node(void *ptr);

// Create a node and copy the string
node_t *create_string_node(const char *str);

// Destroy a node, freeing the data inside using dtor
// if dtor is NULL, the libC's free() will be used
void destroy_node(node_t *node, node_dtor_t dtor);

// Destroy a node, freeing the data inside using dtor
// The pointer will not be free if dtor is NULL
void destroy_ptr_node(node_t *node, node_dtor_t dtor);
/////////////////////////////////////////////////////////////////////////////

#endif /* !NODE_H_ */
