/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_create
*/

#include <string.h>
#include <stdlib.h>
#include "mylist/string_list.h"

int intern_string_list_insert(
    string_list_t *this,
    long index,
    const char *str
);

int intern_string_list_push_front(
    string_list_t *this,
    const char *str
);

int intern_string_list_push_back(
    string_list_t *this,
    const char *str
);

char *intern_string_list_emplace(
    string_list_t *this,
    long idx,
    size_t size
);

char *intern_string_list_emplace_front(
    string_list_t *this,
    size_t size
);

char *intern_string_list_emplace_back(
    string_list_t *this,
    size_t size
);

void intern_string_list_pop(
    string_list_t *this,
    long index
);

void intern_string_list_pop_front(
    string_list_t *this
);

void intern_string_list_pop_back(
    string_list_t *this
);

int intern_string_list_remove(
    string_list_t *this,
    const char *s
);

int intern_string_list_remove_cmp(
    string_list_t *this,
    const char *s,
    node_cmp_t comparator
);

void intern_string_list_clear(
    string_list_t *this
);

string_list_t *intern_string_list_duplicate(
    const string_list_t *this
);

void intern_string_list_merge(
    string_list_t *this,
    string_list_t *other
);

void intern_string_list_reverse(
    string_list_t *this
);

void intern_string_list_rotate_begin(
    string_list_t *this
);

void intern_string_list_rotate_end(
    string_list_t *this
);

int intern_string_list_empty(
    const string_list_t *this
);

const node_t *intern_string_list_get(
    const string_list_t *this,
    long index
);

size_t intern_string_list_length(
    const string_list_t *this
);

const node_t *intern_string_list_begin(
    const string_list_t *this
);

const node_t *intern_string_list_end(
    const string_list_t *this
);

node_dtor_t intern_string_list_get_dtor(
    const string_list_t *this
);

const node_t *intern_string_list_find(
    const string_list_t *this,
    const char *str
);

const node_t *intern_string_list_find_cmp(
    const string_list_t *this,
    const char *str,
    node_cmp_t comparator
);

int intern_string_list_contains(
    const string_list_t *this,
    const char *str
);

static const string_list_t STRING_LIST_MODEL =
{
    .str_insert = &intern_string_list_insert,
    .str_push_front = &intern_string_list_push_front,
    .str_push_back = &intern_string_list_push_back,
    .str_emplace = &intern_string_list_emplace,
    .str_emplace_front = &intern_string_list_emplace_front,
    .str_emplace_back = &intern_string_list_emplace_back,
    .pop = &intern_string_list_pop,
    .pop_front = &intern_string_list_pop_front,
    .pop_back = &intern_string_list_pop_back,
    .str_remove = &intern_string_list_remove,
    .str_remove_cmp = &intern_string_list_remove_cmp,
    .clear = &intern_string_list_clear,
    .duplicate = &intern_string_list_duplicate,
    .merge = &intern_string_list_merge,
    .reverse = &intern_string_list_reverse,
    .rotate_begin = &intern_string_list_rotate_begin,
    .rotate_end = &intern_string_list_rotate_end,
    .empty = &intern_string_list_empty,
    .get = &intern_string_list_get,
    .__len__ = &intern_string_list_length,
    .__begin__ = &intern_string_list_begin,
    .__end__ = &intern_string_list_end,
    .__get_dtor__ = &intern_string_list_get_dtor,
    .str_find = &intern_string_list_find,
    .str_find_cmp = &intern_string_list_find_cmp,
    .str_contains = &intern_string_list_contains
};

static void string_list_init(string_list_t *list)
{
    container_list_t *container = NULL;

    if (list) {
        memcpy(list, &STRING_LIST_MODEL, sizeof(*list));
        container = ((container_list_t *)(&list->__c));
        memset(container, 0, sizeof(*container));
        container->__dtor__ = &free;
    }
}

string_list_t *string_list_create(void)
{
    string_list_t *list = malloc(sizeof(*list));

    string_list_init(list);
    return list;
}