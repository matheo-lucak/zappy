/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdbool.h>

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

#endif /* MY_H_ */
