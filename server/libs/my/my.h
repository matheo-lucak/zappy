/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdbool.h>
#include <unistd.h>

/**
 * @brief Gets the length of a null-terminated string.
 * 
 * @param str The null-terminated string to get the length of.
 * @return ssize_t The number of characters in the string.
 *                 If the string pointer is NULL, return -1.
 */
ssize_t my_str_len(const char *str);

/**
* @brief Checks whether a character is a digit or not.
* 
* @param c The character to check.
* @return true If it is.
* @return false If it's not.
*/
bool my_is_digit(const char c);

/**
* @brief Tries to retrieve an whole number from a given string.
* 
* @param str The string to retrieve the whole number from.
* @return int The stored result.
*/
int my_get_nbr(const char *str);

/**
 * @brief Concatenates a string to another one.
 * 
 * @param first Left part of the string.
 * @param second Right part of the string.
 * @param free_first A boolean to automatically release the first pointer
 *                   if set to 'true'.
 * @param free_second A boolean to automatically release the second pointer
 *                   if set to 'true'.
 * @return char* A newly allocated pointer, the resultant of the concatenation.
 */
char *my_str_cat(char *first, char *second, bool free_first, bool free_second);

#endif /* MY_H_ */
