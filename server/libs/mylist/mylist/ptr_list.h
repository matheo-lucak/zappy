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
    int (*const ptr_remove)(ptr_list_t *this, const void *ptr);
    int (*const ptr_remove_cmp)(ptr_list_t *this,
                                const void *ptr, node_cmp_t comparator);

    void (*const clear)(ptr_list_t *this);
    ptr_list_t *(*const duplicate)(const ptr_list_t *this);
    void (*const merge)(ptr_list_t *this, ptr_list_t *other);
    void (*const reverse)(ptr_list_t *this);
    void (*const rotate_begin)(ptr_list_t *this);
    void (*const rotate_end)(ptr_list_t *this);

    int (*const empty)(const ptr_list_t *this);
    const node_t *(*const get)(const ptr_list_t *this, long index);

    size_t (*const __len__)(const ptr_list_t *this);
    const node_t *(*const __begin__)(const ptr_list_t *this);
    const node_t *(*const __end__)(const ptr_list_t *this);
    node_dtor_t (*const __get_dtor__)(const ptr_list_t *this);

    const node_t *(*const ptr_find)(const ptr_list_t *this, const void *ptr);
    const node_t *(*const ptr_find_cmp)(const ptr_list_t *this,
                                        const void *ptr, node_cmp_t comparator);
    int (*const ptr_contains)(const ptr_list_t *this, const void *ptr);

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
// Each pointer is the one stored in the list, so use free() to free the array
// if the list has a destructor instead of free_2d_array()
void *ptr_list_to_array(const ptr_list_t *list, size_t *length);

// Create a pointer list from a NULL-terminated array of pointers
// If destructor is not NULL, the ptr_list grabs the ownership of the pointers
ptr_list_t *array_to_ptr_list(const void *array, node_dtor_t destructor);

// Create a pointer list with default values
// If destructor is not NULL, the ptr_list grabs the ownership of the pointers
#define make_ptr_list(destructor, values...)    \
    array_to_ptr_list(_FMT_ARRAY(const void *, values, NULL), destructor)
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

///////////// Remove data in list /////////////

// Remove the first occurence of a pointer from the list
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define ptr_list_remove(list, ptr) \
    (list)->ptr_remove((list), (ptr))

// Remove the first occurence of a pointer from the list using a comparator
// The comparator function must returns 0 if the data match,
// non-zero value otherwise
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
// Returns LIST_ERROR for NULL comparator
#define ptr_list_remove_cmp(list, ptr, comparator) \
    (list)->ptr_remove_cmp((list), (ptr), (node_cmp_t)(comparator))
//////////////////////////////////////////////////

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
    (list)->ptr_contains((list), (ptr))
/////////////////////////////////////////////////

#endif /* !PTR_LIST_H_ */
