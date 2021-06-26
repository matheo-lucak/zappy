/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** create_node
*/

#include <stdlib.h>
#include <string.h>
#include "mylist/node.h"

static node_t *allocate_node(void)
{
    node_t *node = malloc(sizeof(*node));

    return (node) ? memset(node, 0, sizeof(*node)) : NULL;
}

node_t *create_empty_node(size_t size)
{
    node_t *element = (size > 0) ? allocate_node() : NULL;

    if (element) {
        element->data.ptr = malloc(size);
        if (!element->data.ptr) {
            free(element);
            return NULL;
        }
        memset(element->data.ptr, 0, size);
        element->data.size = size;
    }
    return element;
}

node_t *create_node(const void *data, size_t size)
{
    node_t *element = (data && size) ? allocate_node() : NULL;

    if (element) {
        element->data.ptr = malloc(size);
        if (!element->data.ptr) {
            free(element);
            return NULL;
        }
        memcpy(element->data.ptr, data, size);
        element->data.size = size;
    }
    return (element);
}

node_t *create_ptr_node(void *ptr)
{
    node_t *element = (ptr) ? allocate_node() : NULL;

    if (element) {
        element->data.ptr = ptr;
        element->data.size = 0;
    }
    return element;
}

node_t *create_string_node(const char *str)
{
    node_t *element = (str) ? allocate_node() : NULL;

    if (element) {
        element->data.ptr = strdup(str);
        if (!element->data.ptr) {
            free(element);
            return NULL;
        }
        element->data.size = strlen(str);
    }
    return element;
}