/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list
*/

#ifndef PTR_LIST_H_
#define PTR_LIST_H_

#include "constants.h"
#include "container.h"
#include "base_list.h"
#include "free_2d_array.h"

typedef struct pointer_linked_list ptr_list_t;

struct pointer_linked_list
{
    int (*const ptr_insert)(ptr_list_t *this, long index, void *ptr);
    int (*const ptr_push_front)(ptr_list_t *this, void *ptr);
    int (*const ptr_push_back)(ptr_list_t *this, void *ptr);

    void (*const pop)(ptr_list_t *this, long index);
    void (*const pop_front)(ptr_list_t *this);
    void (*const pop_back)(ptr_list_t *this);

    void (*const clear)(ptr_list_t *this);
    ptr_list_t *(*const duplicate)(const ptr_list_t *this);
    void (*const merge)(ptr_list_t *this, ptr_list_t *other);
    void (*const reverse)(ptr_list_t *this);
    void (*const rotate_begin)(ptr_list_t *this);
    void (*const rotate_end)(ptr_list_t *this);

    const node_t *(*const get)(const ptr_list_t *this, long index);
    const node_t *(*const ptr_find)(const ptr_list_t *this, const void *ptr);
    const node_t *(*const ptr_find_cmp)(const ptr_list_t *this,
                                        const void *ptr, node_cmp_t comparator);

    const container_list_t __c;
};

/////////// Init a linked list ///////////
// (destructor is a pointer to the function to use to free the node data)
//

// Creates an initializes a new pointer linked list
// (Will not destroy the pointer if NULL is given)
ptr_list_t *ptr_list_create(node_dtor_t destructor);
//////////////////////////////////////////

/////////// Destroy a linked list ///////////

// Free the whole linked list (nodes + structure)
// allocated by ptr_list_create() and sets list variable to NULL
void ptr_list_destroy(ptr_list_t *list);
///////////////////////////////////////////////////////////////

///////////// Useful functions /////////////

// Create a NULL-terminated array of pointer from a pointer list
// If length is not NULL, the array length is stored
// Each pointer is the one stored in the list, so don't free them
void *ptr_list_to_array(const ptr_list_t *list, size_t *length);

// Create a pointer list from a NULL-terminated array of pointers
ptr_list_t *array_to_ptr_list(const void *array, node_dtor_t destructor);

// Create a pointer list with default values
#define make_ptr_list(destructor, value1, values...)    \
    array_to_ptr_list(_FMT_ARRAY(void *, value1, values, NULL), destructor)
///////////////////////////////////////////////////////////////

///////////// Add data to linked lists ///////////

// Insert a pointer at a certain index
// (If 'index' is negative the search will begin at the end)
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define ptr_list_insert(list, index, ptr) \
    (list)->ptr_insert((list), (index), (ptr))

// Insert a pointer at the begin of the list
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define ptr_list_push_front(list, ptr)   \
    (list)->ptr_push_front((list), (ptr))

// Insert a pointer at the end of the list
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define ptr_list_push_back(list, ptr) \
    (list)->ptr_push_back((list), (ptr))
///////////////////////////////////////////////////////////////

///////////// Find node in list /////////////

// Find a pointer in a pointer list
// Returns the node, or NULL if the pointer was not found
#define ptr_list_find(list, ptr)    \
    (list)->ptr_find((list), (ptr))

// Find a data in a pointer list using a comparator by passing these pointers
// as parameter
// The comparator function must returns 0 if the data match,
// non-zero value otherwise
// Returns the node, or NULL if the data was not found
// Returns NULL for NULL comparator
#define ptr_list_find_cmp(list, ptr, comparator)    \
    (list)->ptr_find_cmp((list), (ptr), (node_cmp_t)(comparator))

// Check if a pointer is in a pointer list
// Return 1 if it's 1, 0 otherwise
#define ptr_list_contains(list, ptr)    \
    ((list)->ptr_find((list), (ptr)) != NULL)
/////////////////////////////////////////////////

#endif /* !PTR_LIST_H_ */
