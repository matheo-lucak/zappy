/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list
*/

#ifndef GENERIC_LIST_H_
#define GENERIC_LIST_H_

#include "constants.h"
#include "container.h"
#include "base_list.h"
#include "free_2d_array.h"

typedef struct generic_linked_list list_t;

struct generic_linked_list
{
    int (*const insert)(list_t *this, long idx, const void *data, size_t size);
    int (*const push_front)(list_t *this, const void *data, size_t size);
    int (*const push_back)(list_t *this, const void *data, size_t size);

    void *(*const emplace)(list_t *this, long idx, size_t size);
    void *(*const emplace_front)(list_t *this, size_t size);
    void *(*const emplace_back)(list_t *this, size_t size);

    void (*const pop)(list_t *this, long index);
    void (*const pop_front)(list_t *this);
    void (*const pop_back)(list_t *this);

    void (*const clear)(list_t *this);
    list_t *(*const duplicate)(const list_t *this);
    void (*const merge)(list_t *this, list_t *other);
    void (*const reverse)(list_t *this);
    void (*const rotate_begin)(list_t *this);
    void (*const rotate_end)(list_t *this);

    const node_t *(*const get)(const list_t *this, long index);
    const node_t *(*const find)(const list_t *this,
                                const void *data, size_t size);
    const node_t *(*const find_cmp)(const list_t *this,
                                    const void *data, node_cmp_t comparator);

    const container_list_t __c;
};

/////////// Init a linked list ///////////
// (destructor is a pointer to the function to use to free the node data)
//

// Creates an initializes a new generic linked list
// (Will use default free() if NULL is given for destructor)
list_t *generic_list_create(node_dtor_t destructor);
//////////////////////////////////////////

/////////// Destroy a linked list ///////////

// Free the whole linked list (nodes + structure)
// allocated by generic_list_create() and sets list variable to NULL
void generic_list_destroy(list_t *list);
///////////////////////////////////////////////////////////////

///////////// Useful functions /////////////

// Create an array from a generic list
// If length is not NULL, the array length is stored
// If the list is empty, this functions returns NULL and sets size to 0
void *generic_list_to_array(const list_t *list, size_t *length);

// Create a generic list of nmemb elements from an array of nmemb elements
// each size bytes long
list_t *array_to_generic_list(
    const void *array,
    size_t size,
    size_t nmemb,
    node_dtor_t destructor
);

// Create a generic list with default values
#define make_generic_list(destructor, type, value1, values...)    \
    array_to_generic_list(_FMT_ARRAY(type, value1, values), sizeof(type),   \
                        _FMT_ARRAY_SIZE(type, value1, values), destructor)
///////////////////////////////////////////////////////////////

///////////// Add data to linked lists ///////////

// Insert a data at a certain index
// (If 'index' is negative the search will begin at the end)
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define generic_list_insert(list, index, data, type) \
    (list)->insert((list), (index), _FMT_DATA(data, type), sizeof(type))

// Insert a data at the begin of the list
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define generic_list_push_front(list, data, type)    \
    (list)->push_front((list), _FMT_DATA(data, type), sizeof(type))

// Insert a data at the end of the list
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define generic_list_push_back(list, data, type) \
    (list)->push_back((list), _FMT_DATA(data, type), sizeof(type))

// Emplace a storage data at a certain index
// (If 'index' is negative the search will begin at the end)
// Returns a pointer to the allocated storage, or NULL in case of failure
#define generic_list_emplace(list, index, type) \
    ((type *)((list)->emplace((list), (index), sizeof(type))))

// Emplace a storage data at the begin of the list
// Returns a pointer to the allocated storage, or NULL in case of failure
#define generic_list_emplace_front(list, type) \
    ((type *)((list)->emplace_front((list), sizeof(type))))

// Emplace a storage data at the end of the list
// Returns a pointer to the allocated storage, or NULL in case of failure
#define generic_list_emplace_back(list, type) \
    ((type *)((list)->emplace_back((list), sizeof(type))))
//////////////////////////////////////////////////

///////////// Find node in list /////////////

// Find a data in a generic list
// Returns the node, or NULL if the data was not found
#define generic_list_find(list, data, type)    \
    (list)->find((list), _FMT_DATA(data, type), sizeof(type))

// Find a data in a generic list using a comparator
// The comparator function must returns 0 if the data match,
// non-zero value otherwise
// Returns the node, or NULL if the data was not found
// Returns NULL for NULL comparator
#define generic_list_find_cmp(list, data, type, comparator)    \
    (list)->find_cmp((list), _FMT_DATA(data, type), (node_cmp_t)(comparator))

// Check if a data is in a generic list
// Return 1 if it's 1, 0 otherwise
#define generic_list_contains(list, data, type)    \
    ((list)->find((list), _FMT_DATA(data, type), sizeof(type)) != NULL)
//////////////////////////////////////////////////

#endif /* !GENERIC_LIST_H_ */
