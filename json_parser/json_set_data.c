/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser_back.h"
#include "utilities.h"
#include <stdlib.h>

int json_set_bool(json_file_t *fd, int *good)
{
    int ret = 0;
    char *str = NULL;
    int i = fd->index;
    int j = json_fd_reach_next_char(fd, " \n\t,}", NULL);

    if (j < 0)
        return -1;
    str = my_strdup_ij(fd->str, i, i + j);
    if (str == NULL)
        return -1;
    if (my_strcmp(str, "true") == 0 || my_strcmp(str, "false") == 0) {
        ret = my_strcmp(str, "true") == 0 ? 1 : 0;
        free(str);
        good[0] = 1;
        return ret;
    }
    json_error_syntax(fd, str, "true or false");
    free(str);
    return -1;
}

int json_set_null(json_file_t *fd, int *good)
{
    char *str = NULL;
    int i = fd->index;
    int j = json_fd_reach_next_char(fd, " \n\t,}", NULL);

    if (j < 0)
        return -1;
    str = my_strdup_ij(fd->str, i, i + j);
    if (str == NULL)
        return -1;
    if (my_strcmp(str, "null") != 0) {
        json_error_syntax(fd, str, "null");
        free(str);
        return -1;
    }
    good[0] = 1;
    free(str);
    return 0;
}

int json_set_int(json_file_t *fd, int *good)
{
    char *str = NULL;
    int i = fd->index;
    int j = json_fd_reach_next_char(fd, " ,\n}", "-0123456789");
    int n = 0;

    if (j < 0)
        return -1;
    str = my_strdup_ij(fd->str, i, i + j);
    if (str == NULL)
        return -1;
    if (my_str_isnum(str) == 0) {
        json_error_syntax(fd, str, "number");
        free(str);
        return -1;
    }
    good[0] = 1;
    n = my_getnbr(str);
    free(str);
    return n;
}

char *json_set_string(json_file_t *fd)
{
    char *str = NULL;
    int i = fd->index + 1;
    int j = 0;

    json_fd_advance_index(fd, 1);
    j = json_fd_reach_next_char(fd, "\"\n", NULL);
    if (fd->str[i + j] == '\n')
        return NULL;
    if (j < 0)
        return NULL;
    str = my_strdup_ij(fd->str, i, i + j);
    if (str == NULL)
        return NULL;
    json_fd_advance_index(fd, 1);
    return str;
}

char *json_set_error(json_file_t *fd)
{
    char *str = NULL;
    int i = fd->index;
    int j = json_fd_reach_next_char(fd, " \n\t,}", NULL);

    if (j < 0)
        return NULL;
    str = my_strdup_ij(fd->str, i, i + j);
    if (str == NULL)
        return "Error";
    return str;
}
