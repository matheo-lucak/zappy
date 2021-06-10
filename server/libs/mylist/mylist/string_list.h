/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list
*/

#ifndef STRING_LIST_H_
#define STRING_LIST_H_

#include "constants.h"
#include "container.h"
#include "base_list.h"
#include "free_2d_array.h"

typedef struct string_linked_list string_list_t;

struct string_linked_list
{
    int (*const str_insert)(string_list_t *this, long index, const char *str);
    int (*const str_push_front)(string_list_t *this, const char *str);
    int (*const str_push_back)(string_list_t *this, const char *str);

    char *(*const str_emplace)(string_list_t *this, long idx, size_t size);
    char *(*const str_emplace_front)(string_list_t *this, size_t size);
    char *(*const str_emplace_back)(string_list_t *this, size_t size);

    void (*const pop)(string_list_t *this, long index);
    void (*const pop_front)(string_list_t *this);
    void (*const pop_back)(string_list_t *this);

    void (*const clear)(string_list_t *this);
    string_list_t *(*const duplicate)(const string_list_t *this);
    void (*const merge)(string_list_t *this, string_list_t *other);
    void (*const reverse)(string_list_t *this);
    void (*const rotate_begin)(string_list_t *this);
    void (*const rotate_end)(string_list_t *this);

    const node_t *(*const get)(const string_list_t *this, long index);
    const node_t *(*const str_find)(const string_list_t *this, const char *str);
    const node_t *(*const str_find_cmp)(const string_list_t *this,
                                        const char *str, node_cmp_t comparator);

    const container_list_t __c;
};

/////////// Init a linked list ///////////
// (destructor is a pointer to the function to use to free the node data)
//

// Creates an initializes a new string linked list
string_list_t *string_list_create(void);
//////////////////////////////////////////

/////////// Destroy a linked list ///////////

// Free the whole linked list (nodes + structure)
// allocated by string_list_create() and sets list variable to NULL
void string_list_destroy(string_list_t *list);
///////////////////////////////////////////////////////////////

///////////// Useful functions /////////////

// Create a NULL-terminated array of strings from a string list
// If length is not NULL, the array length is stored
// Each string is copied
char **string_list_to_array(const string_list_t *list, size_t *length);

// Create a string list from a NULL-terminated array of strings
// Each string is copied
string_list_t *array_to_string_list(char *const *array);

// Create a string list with default values
#define make_string_list(value1, values...)    \
    array_to_string_list((char *const *)_FMT_ARRAY(char *, value1, values, 0L))

// Concatenate a list of string to an allocated str
char *string_list_concat(
    const string_list_t *list,
    const char *separator,
    size_t *length
);
///////////////////////////////////////////////////////////////

///////////// Add data to linked lists ///////////

// Insert a string at a certain index
// (If 'index' is negative the search will begin at the end)
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define string_list_insert(list, index, str) \
    (list)->str_insert((list), (index), (str))

// Insert a string at the begin of the list
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define string_list_push_front(list, str) \
    (list)->str_push_front((list), (str))

// Insert a string at the end of the list
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define string_list_push_back(list, str) \
    (list)->str_push_back((list), (str))

// Emplace a storage data at a certain index
// (If 'index' is negative the search will begin at the end)
// Returns a pointer to the allocated storage, or NULL in case of failure
#define string_list_emplace(list, index, size) \
    ((char *)((list)->str_emplace((list), (index), (size))))

// Emplace a storage data at the begin of the list
// Returns a pointer to the allocated storage, or NULL in case of failure
#define string_list_emplace_front(list, size) \
    ((char *)((list)->str_emplace_front((list), (size))))

// Emplace a storage data at the end of the list
// Returns a pointer to the allocated storage, or NULL in case of failure
#define string_list_emplace_back(list, size) \
    ((char *)((list)->str_emplace_back((list), (size))))
//////////////////////////////////////////////////

///////////// Find node in list /////////////

// Find a string in a generic list
// Returns the node, or NULL if the string was not found
#define string_list_find(list, str)    \
    (list)->str_find((list), (str))

// Find a string in a string list using a comparator by passing these strings
// as parameter
// The comparator function must returns 0 if the data match,
// non-zero value otherwise
// Returns the node, or NULL if the string was not found
// Returns NULL for NULL comparator
#define string_list_find_cmp(list, str, comparator)    \
    (list)->str_find_cmp((list), (str), (node_cmp_t)(comparator))

// Check if a string is in a generic list
// Return 1 if it's 1, 0 otherwise
#define string_list_contains(list, str)    \
    ((list)->str_find((list), (str)) != NULL)
/////////////////////////////////////////////////

// Get the string data inside the node (string_list_t)
#define NODE_STR(node) ((char *)((node)->data.ptr))

#endif /* !STRING_LIST_H_ */
