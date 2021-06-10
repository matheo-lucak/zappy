/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** base_list
*/

#ifndef BASE_LIST_H_
#define BASE_LIST_H_

///////////// Delete data from linked lists ///////////

// Delete a node at a certain index and returns the next node
#define list_pop(list, index)   \
    (list)->pop((list), (index))

// Delete the first node
#define list_pop_front(list)    \
    (list)->pop_front((list))

// Delete the last node
#define list_pop_back(list)    \
    (list)->pop_back((list))

// Delete all the nodes, making list empty
#define list_clear(list)    \
    (list)->clear((list))
//////////////////////////////////////////////////

///////////// Modify linked lists ///////////

// Duplicates the linked list
// This function will create a new list with each node data copied
#define list_dup(list)      \
    (list)->duplicate((list))

// Merge two lists, making the list2 empty
#define list_merge(list1, list2)    \
    (list1)->merge((list1), (list2))

// Reverse a list
#define list_reverse(list)  \
    (list)->reverse((list))

// Put the first node of the list at the end
#define list_rotate_begin(list) \
    (list)->rotate_begin((list))

// Put the last node of the list at the start
#define list_rotate_end(list) \
    (list)->rotate_end((list))
//////////////////////////////////////////////////

///////////// List informations /////////////

// Get the list's length (the number of nodes)
#define list_len(list) ((list)->__c.size)

// Check if the list is empty
// Returns 1 if the list is empty else 0
#define list_empty(list) ((list)->__c.size == 0)

// Get the list's node data destructor function pointer
#define list_destructor(list) ((list)->__c.__dtor__)
//////////////////////////////////////////////////

///////////// Get/Find node in list /////////////

// Get the first node pointer
#define list_begin(list)    \
    ((list)->__c.start)

// Get the last node pointer
#define list_end(list)    \
    ((list)->__c.end)

// Get the node pointer at index, returning NULL if none was found
// (If 'index' is negative the search will begin at the end)
#define list_get(list, index)   \
    (list)->get((list), (index))

// macro for range loop
#define list_foreach(node, list) \
    for (const node_t *node = list_begin(list); node; node = (node)->next)

// macro for range loop reversed
#define list_foreach_reversed(node, list) \
    for (const node_t *node = list_end(list); node; node = (node)->previous)
/////////////////////////////////////////////////////////////////////////////

#endif /* !BASE_LIST_H_ */
