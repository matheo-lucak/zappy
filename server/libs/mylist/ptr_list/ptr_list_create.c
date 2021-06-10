/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_create
*/

#include <stdlib.h>
#include <string.h>
#include "mylist/ptr_list.h"

int intern_ptr_list_insert(
    ptr_list_t *this,
    long index,
    void *ptr
);

int intern_ptr_list_push_front(
    ptr_list_t *this,
    void *ptr
);

int intern_ptr_list_push_back(
    ptr_list_t *this,
    void *ptr
);

void intern_ptr_list_pop(
    ptr_list_t *this,
    long index
);

void intern_ptr_list_pop_front(
    ptr_list_t *this
);

void intern_ptr_list_pop_back(
    ptr_list_t *this
);

void intern_ptr_list_clear(
    ptr_list_t *this
);

ptr_list_t *intern_ptr_list_duplicate(
    const ptr_list_t *this
);

void intern_ptr_list_merge(
    ptr_list_t *this,
    ptr_list_t *other
);

void intern_ptr_list_reverse(
    ptr_list_t *this
);

void intern_ptr_list_rotate_begin(
    ptr_list_t *this
);

void intern_ptr_list_rotate_end(
    ptr_list_t *this
);

int intern_ptr_list_empty(
    const ptr_list_t *this
);

const node_t *intern_ptr_list_get(
    const ptr_list_t *this,
    long index
);

size_t intern_ptr_list_length(
    const ptr_list_t *this
);

const node_t *intern_ptr_list_begin(
    const ptr_list_t *this
);

const node_t *intern_ptr_list_end(
    const ptr_list_t *this
);

node_dtor_t intern_ptr_list_get_dtor(
    const ptr_list_t *this
);

const node_t *intern_ptr_list_find(
    const ptr_list_t *this,
    const void *ptr
);

const node_t *intern_ptr_list_find_cmp(
    const ptr_list_t *this,
    const void *ptr,
    node_cmp_t comparator
);

int intern_ptr_list_contains(
    const ptr_list_t *this,
    const void *ptr
);

static const ptr_list_t PTR_LIST_MODEL =
{
    .ptr_insert = &intern_ptr_list_insert,
    .ptr_push_front = &intern_ptr_list_push_front,
    .ptr_push_back = &intern_ptr_list_push_back,
    .pop = &intern_ptr_list_pop,
    .pop_front = &intern_ptr_list_pop_front,
    .pop_back = &intern_ptr_list_pop_back,
    .clear = &intern_ptr_list_clear,
    .duplicate = &intern_ptr_list_duplicate,
    .merge = &intern_ptr_list_merge,
    .reverse = &intern_ptr_list_reverse,
    .rotate_begin = &intern_ptr_list_rotate_begin,
    .rotate_end = &intern_ptr_list_rotate_end,
    .empty = &intern_ptr_list_empty,
    .get = &intern_ptr_list_get,
    .__len__ = &intern_ptr_list_length,
    .__begin__ = &intern_ptr_list_begin,
    .__end__ = &intern_ptr_list_end,
    .__get_dtor__ = &intern_ptr_list_get_dtor,
    .ptr_find = &intern_ptr_list_find,
    .ptr_find_cmp = &intern_ptr_list_find_cmp,
    .ptr_contains = &intern_ptr_list_contains
};

static void ptr_list_init(ptr_list_t *list, node_dtor_t destructor)
{
    container_list_t *container = NULL;

    if (list) {
        memcpy(list, &PTR_LIST_MODEL, sizeof(*list));
        container = ((container_list_t *)(&list->__c));
        memset(container, 0, sizeof(*container));
        container->__dtor__ = destructor;
    }
}

ptr_list_t *ptr_list_create(node_dtor_t destructor)
{
    ptr_list_t *list = malloc(sizeof(*list));

    ptr_list_init(list, destructor);
    return list;
}