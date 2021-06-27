/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_input
*/

#include <stdlib.h>
#include <unistd.h>
#include "server/client.h"
#include "server/request/request.h"

static const int READ_SIZE = 4096;

static int my_strlen_l(char const *str, char limit)
{
    int count = 0;

    while (str != NULL && str[count] != '\0' && str[count] != limit)
        count += 1;
    return (count);
}

static int my_realloc(char **str, int to_add)
{
    int str_size = my_strlen_l(*str, 0);
    char *new_str = malloc(sizeof(char) * (str_size + to_add + 1));
    int i = 0;
    int output = 1;

    if (new_str == NULL) {
        output = 0;
    } else {
        while (i < str_size + to_add + 1) {
            new_str[i] = (i < str_size) ? (*str)[i] : '\0';
            i += 1;
        }
    }
    free(*str);
    *str = new_str;
    return (output);
}

static int my_strcat_l(char **dest, char const *src, char limit)
{
    int i = 0;
    int first = my_strlen_l(*dest, 0);

    if (src == NULL || src[0] == '\0'
    || !my_realloc(dest, my_strlen_l(src, limit)))
        return (0);
    while (src[i] != '\0' && src[i] != limit) {
        (*dest)[first + i] = src[i];
        i += 1;
    }
    return ((src[i] == '\0') ? 1 : 2);
}

static int read_file(int fd, char *buffer, char **save)
{
    int i = 0;
    int size = -1;

    free(*save);
    *save = NULL;
    if (buffer != NULL)
        size = read(fd, buffer, READ_SIZE);
    if (size <= 0)
        return (0);
    buffer[size] = '\0';
    while (i < size) {
        if (buffer[i] == RQ_DELIMITER) {
            my_strcat_l(save, &buffer[i + 1], 0);
            return (2);
        }
        i += 1;
    }
    return (1);
}

char *request_get_input(client_t *c)
{
    char buffer[READ_SIZE + 1];
    char *line = NULL;
    char *new_save = NULL;
    int read_status = 1;

    if (!c || !c->socket || c->socket->socket < 0)
        return NULL;
    if (my_strcat_l(&line, c->input_stock, RQ_DELIMITER) == 2) {
        my_strcat_l(&new_save, &(c->input_stock)[my_strlen_l(line, 0) + 1], 0);
        free(c->input_stock);
        c->input_stock = new_save;
        return line;
    }
    while (c->socket->socket >= 0 && read_status == 1) {
        read_status = read_file(c->socket->socket, buffer, &c->input_stock);
        if (read_status != 0 && !my_strcat_l(&line, buffer, RQ_DELIMITER))
            break;
    }
    return line;
}
