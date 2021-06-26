/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_create
*/

#include <string.h>
#include <stdlib.h>
#include "mylist/generic_list.h"

int intern_generic_list_insert(
    list_t *this,
    long index,
    const void *data,
    size_t size
);

int intern_generic_list_push_front(
    list_t *this,
    const void *data,
    size_t size
);

int intern_generic_list_push_back(
    list_t *this,
    const void *data,
    size_t size
);

void intern_generic_list_pop(
    list_t *this,
    long index
);

void intern_generic_list_pop_front(
    list_t *this
);

void intern_generic_list_pop_back(
    list_t *this
);

void *intern_generic_list_emplace(
    list_t *this,
    long index,
    size_t size
);

int intern_generic_list_remove(
    list_t *this,
    const void *data,
    size_t size
);

int intern_generic_list_remove_cmp(
    list_t *this,
    const void *data,
    size_t size,
    node_cmp_t comparator
);

void *intern_generic_list_emplace_front(
    list_t *this,
    size_t size
);

void *intern_generic_list_emplace_back(
    list_t *this,
    size_t size
);

void intern_generic_list_clear(
    list_t *this
);

list_t *intern_generic_list_duplicate(
    const list_t *this
);

void intern_generic_list_merge(
    list_t *this,
    list_t *other
);

void intern_generic_list_reverse(
    list_t *this
);

void intern_generic_list_rotate_begin(
    list_t *this
);

void intern_generic_list_rotate_end(
    list_t *this
);

int intern_generic_list_empty(
    const list_t *this
);

const node_t *intern_generic_list_get(
    const list_t *this,
    long index
);

size_t intern_generic_list_length(
    const list_t *this
);

const node_t *intern_generic_list_begin(
    const list_t *this
);

const node_t *intern_generic_list_end(
    const list_t *this
);

node_dtor_t intern_generic_list_get_dtor(
    const list_t *this
);

const node_t *intern_generic_list_find(
    const list_t *this,
    const void *data,
    size_t size
);

const node_t *intern_generic_list_find_cmp(
    const list_t *this,
    const void *data,
    size_t size,
    node_cmp_t comparator
);

int intern_generic_list_contains(
    const list_t *this,
    const void *data,
    size_t size
);

static const list_t GENERIC_LIST_MODEL =
{
    .insert = &intern_generic_list_insert,
    .push_front = &intern_generic_list_push_front,
    .push_back = &intern_generic_list_push_back,
    .emplace = &intern_generic_list_emplace,
    .emplace_front = &intern_generic_list_emplace_front,
    .emplace_back = &intern_generic_list_emplace_back,
    .pop = &intern_generic_list_pop,
    .pop_front = &intern_generic_list_pop_front,
    .pop_back = &intern_generic_list_pop_back,
    .remove = &intern_generic_list_remove,
    .remove_cmp = &intern_generic_list_remove_cmp,
    .clear = &intern_generic_list_clear,
    .duplicate = &intern_generic_list_duplicate,
    .merge = &intern_generic_list_merge,
    .reverse = &intern_generic_list_reverse,
    .rotate_begin = &intern_generic_list_rotate_begin,
    .rotate_end = &intern_generic_list_rotate_end,
    .empty = &intern_generic_list_empty,
    .get = &intern_generic_list_get,
    .__len__ = &intern_generic_list_length,
    .__begin__ = &intern_generic_list_begin,
    .__end__ = &intern_generic_list_end,
    .__get_dtor__ = &intern_generic_list_get_dtor,
    .find = &intern_generic_list_find,
    .find_cmp = &intern_generic_list_find_cmp,
    .contains = &intern_generic_list_contains
};

static void generic_list_init(list_t *list, node_dtor_t destructor)
{
    container_list_t *container = NULL;

    if (list) {
        memcpy(list, &GENERIC_LIST_MODEL, sizeof(*list));
        container = ((container_list_t *)(&list->__c));
        memset(container, 0, sizeof(*container));
        container->__dtor__ = destructor;
    }
}

list_t *generic_list_create(node_dtor_t destructor)
{
    list_t *list = malloc(sizeof(*list));

    generic_list_init(list, destructor);
    return list;
}