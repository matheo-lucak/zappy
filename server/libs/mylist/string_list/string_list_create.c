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

const node_t *intern_string_list_get(
    const string_list_t *this,
    long index
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
    .clear = &intern_string_list_clear,
    .duplicate = &intern_string_list_duplicate,
    .merge = &intern_string_list_merge,
    .reverse = &intern_string_list_reverse,
    .rotate_begin = &intern_string_list_rotate_begin,
    .rotate_end = &intern_string_list_rotate_end,
    .get = &intern_string_list_get,
    .str_find = &intern_string_list_find,
    .str_find_cmp = &intern_string_list_find_cmp,
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