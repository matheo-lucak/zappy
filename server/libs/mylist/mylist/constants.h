/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** constants
*/

#ifndef MY_LIST_CONSTANTS_H_
#define MY_LIST_CONSTANTS_H_

enum LIST_RESULT
{
    LIST_ERROR = 0,
    LIST_SUCCESS = 1
};

/////////// Internal functions/Macros used for linked lists ///////////

#define _FMT_DATA(data, type) ((const type [1]){(data)})
#define _FMT_ARRAY(type, values...) ((const type []){values})
#define _FMT_ARRAY_SIZE(type, values...)    \
    (sizeof(_FMT_ARRAY(type, values)) / sizeof(type))

//////////////////////////////////////////////////////////////////////

#endif /* !MY_LIST_CONSTANTS_H_ */
