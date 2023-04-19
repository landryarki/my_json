/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#ifndef MY_JSON_MY_JSON_WRITER_BACK_H
#define MY_JSON_MY_JSON_WRITER_BACK_H

    #include <stdio.h>

typedef struct json_file_s {
    char *path;
    char *str;
    int size;
    int index;
    int line;
    int column;
    int depth;
} json_file_t;

typedef enum json_type {
    JSON_ERROR = -1,
    JSON_NULL,
    JSON_STRING,
    JSON_INT,
    JSON_BOOL,
    JSON_ARRAY,
    JSON_OBJECT,
} json_type_t;

typedef struct json_props_s {
    char *key;
    void *data;
    int type;
} json_props_t;

json_props_t *json_create_props(char *key, int type, void *data);
void append_json_object(json_props_t ***jsons, json_props_t *json);

void json_write_content(FILE *file, json_props_t *json, int depth);
void json_write_key(FILE *file, json_props_t *json, int depth);
void json_spacing(FILE *file, int depth);
void json_write_string(FILE *file, json_props_t *json, int depth);
void json_write_int(FILE *file, json_props_t *json, int depth);
void json_write_bool(FILE *file, json_props_t *json, int depth);
void json_write_null(FILE *file, json_props_t *json, int depth);
void json_write_array(FILE *file, json_props_t *json, int depth);
void json_write_object(FILE *file, json_props_t *json, int depth);

#endif //MY_JSON_MY_JSON_WRITER_BACK_H
