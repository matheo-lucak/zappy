/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** arg_checker
*/

#ifndef ZAPPY_ARG_CHECKER_H_
#define ZAPPY_ARG_CHECKER_H_

typedef int (*arg_checker_t)(char *);

/**
* @brief Checks if a given string contains a positive integer.
*
* @param arg The string to check onto.
* @return int 0 if the given string contains one, 1 if not
*             and -1 if the string pointer is NULL;
*/
int arg_checker_positive_int(char *arg);

#endif /* !ZAPPY_ARG_CHECKER_H_ */
