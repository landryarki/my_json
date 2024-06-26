/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_writer_back.h"
#include <stdlib.h>

void json_destroy(json_props_t *json)
{
    json_props_t **child = NULL;

    if (json == NULL)
        return;
    if (json->key != NULL)
        free(json->key);
    if (json->type == JSON_STRING && json->data != NULL)
        free(json->data);
    if ((json->type == JSON_OBJECT || json->type == JSON_ARRAY) &&
        json->data != NULL) {
        child = (json_props_t **)(json->data);
        for (int i = 0; child[i] != NULL; i++)
            json_destroy(child[i]);
        free(child);
    }
    free(json);
}

void append_json_object(json_props_t ***jsons, json_props_t *json)
{
    int i = 0;
    json_props_t **tmp = NULL;

    for (; (*jsons)[i] != NULL; i++);
    tmp = malloc(sizeof(json_props_t *) * (i + 2));
    if (tmp == NULL)
        return;
    for (int j = 0; j < i; j++)
        tmp[j] = (*jsons)[j];
    tmp[i] = json;
    tmp[i + 1] = NULL;
    free(*jsons);
    *jsons = tmp;
}

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
