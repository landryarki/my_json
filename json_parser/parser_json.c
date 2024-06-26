/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser_back.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

json_props_t *json_create_props(char *key, int type, void *data)
{
    json_props_t *json = malloc(sizeof(json_props_t));

    if (json == NULL)
        return NULL;
    json->key = key;
    json->data = data;
    json->type = type;
    return json;
}

char *json_set_key(json_file_t *fd)
{
    char *key = NULL;
    int i = 0;
    int j = 0;

    if (json_fd_reach_next_char(fd, "\"", " \n\t") < 0)
        return NULL;
    json_fd_advance_index(fd, 1);
    i = fd->index;
    j = json_fd_reach_next_char(fd, "\"\n", NULL);
    if (fd->str[i + j] == '\n') {
        json_error_syntax(fd, "\\n", "char");
        return NULL;
    }
    if (j < 0)
        return NULL;
    key = my_strdup_ij(fd->str, i, i + j);
    if (key == NULL)
        return NULL;
    json_fd_advance_index(fd, 1);
    return key;
}

static int json_fd_set_type_switch(char type)
{
    switch (type) {
        case '{':
            return JSON_OBJECT;
        case '[':
            return JSON_ARRAY;
        case '"':
            return JSON_STRING;
        case 't':
            return JSON_BOOL;
        case 'f':
            return JSON_BOOL;
        case 'n':
            return JSON_NULL;
        default:
            if ((type >= '0' && type <= '9') || type == '-')
                return JSON_INT;
            else
                return JSON_ERROR;
    }
}

int json_set_type(json_file_t *fd)
{
    json_fd_advance_index(fd, 1);
    json_fd_reach_next_char(fd, NULL, " \n\t");
    return json_fd_set_type_switch(fd->str[fd->index]);
}

json_props_t *json_set_props(json_file_t *fd)
{
    json_props_t *json = json_create_props(NULL, -1, NULL);

    json->key = json_set_key(fd);
    if (json->key == NULL) {
        free(json);
        return NULL;
    }
    if (json_fd_reach_next_char(fd, ":", " \n\t") < 0) {
        free(json->key);
        free(json);
        return NULL;
    }
    json->type = json_set_type(fd);
    json->data = json_set_data(fd, json->type);
    if (json->data == NULL) {
        free(json->key);
        free(json);
        return NULL;
    }
    return json;
}

json_props_t *json_create_from_file(char *path)
{
    json_props_t *json = json_create_props
            (my_strdup(path), JSON_ERROR, NULL);
    json_file_t *fd = json_open_file(my_strdup(path));

    if (fd == NULL || fd->size == 0 ||
    json_fd_reach_next_char(fd, "{[", " \n\t") < 0) {
        json_close_file(fd);
        free(json);
        return NULL;
    }
    if (fd->str[fd->index] == '{' || fd->str[fd->index] == '[') {
        json->type = json_fd_set_type_switch(fd->str[fd->index]);
        json->data = json_set_data(fd, json->type);
    } else
        return NULL;
    if (json->data == NULL)
        return NULL;
    json_close_file(fd);
    return json;
}
