/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#ifndef MY_JSON_MY_JSON_H
    #define MY_JSON_MY_JSON_H

/* here are the .h of both json_writer and json_reader */

/* Un props json a un type qui définit la valeur
 * qu'il va contenir, il a aussi une clé dans la plus part des cas qui va
 * servir a l'identifier.
 * un props json s'écrit "json_props_t" et sera tout le temps un pointeur
 * */

typedef struct json_props_s {
    char *key;
    void *data;
    int type;
} json_props_t;

/* Il y a 6 types de valeur dans ce parser pris en compte (voir example_1.json)
 * et sont les suivants:
 *      INT une valeur numérique
 *      STRING une chaine de caractère
 *      BOOL un booléen
 *      NULL rien... (note: il faut ecrire "null" et non pas laisser un vide)
 *      ARRAY un tableau de valeur (note que ce sont des valeurs et non pas
 *          des props, elles n'ont pas de clé, aussi une valeur peut tres bien
 *          etre un autre tableau, ou un objet)
 *      OBJECT un objet qui contient d'autres props json (note qu'il faut
 *          différencier un props qui a un type, et le type
 *          object qui a pour valeur d'autres props json)
 *
 *   ERROR un type d'erreur, il est utilisé pour les fonctions qui retournent
 *       un props json, si il y a une erreur.
 * */

typedef enum json_type {
    JSON_ERROR = -1,
    JSON_NULL,
    JSON_STRING,
    JSON_INT,
    JSON_BOOL,
    JSON_ARRAY,
    JSON_OBJECT,
} json_type_t;

/*-----------------------------*/

/* Si vous voulez vous pouvez utiliser les types suivants
 * qui sont des alias pour les types de base
 * */

typedef json_props_t json_object_t;
typedef json_props_t json_array_t;

/*-----------------------------*/

/* Pour commencer il faut créer un objet json a partir d'un fichier
 * pour cela il faut utiliser la fonction json_create_from_file
 * qui prend en paramètre le chemin vers le fichier et retourne un objet ou
 * array json qui contient tout le fichier
 * */

////////////////////////////////////////////////////////////
/// \brief create a json object from a file.json
///
/// \param path of the file.json
/// \return an object json
///
////////////////////////////////////////////////////////////

json_props_t *json_create_from_file(char *path);

/*-----------------------------*/

/* Pour récupérer la valeur d'un props "simple" il y a ces fonctions
 * qui prennent en paramètre un objet json, une clé et retourne la valeur
 * correspondante
 * (note: INT: les valeurs negative ne sont pas prisent en compte et seront des
 * erreurs)
 * */

////////////////////////////////////////////////////////////
/// \brief get the key of a json object
///
/// \param json
/// \return return the key of the json object,
///        if the json object has no key, return NULL
///
////////////////////////////////////////////////////////////

char *json_get_key(json_props_t *json);

////////////////////////////////////////////////////////////
/// \brief get the bool value of a json object or of one of his child
///
/// \param json the json object
/// \param key the key of the bool you want to get
/// (NULL if you to get the bool of the json object)
/// \return return the bool value of the json object,
///        if the json object is not a bool, return -1
///
////////////////////////////////////////////////////////////

int json_get_bool(json_props_t *json, char *key);

////////////////////////////////////////////////////////////
/// \brief get the string value of a json object or of one of his child
///
/// \param json the json object
/// \param key the key of the string you want to get
/// (NULL if you to get the string of the json object)
/// \return the string value of the json object,
///        if the json object is not a string, return NULL
///
////////////////////////////////////////////////////////////

char *json_get_string(json_props_t *json, char *key);

////////////////////////////////////////////////////////////
/// \brief get the int value of a json object or of one of his child
///
/// \param json the json object
/// \param key the key of the int you want to get
/// (NULL if you to get the int of the json object)
///
/// \return the int value of the json object,
///        if the json object is not a int, return -1
///
////////////////////////////////////////////////////////////

int json_get_int(json_props_t *json, char *key);

/* (note qu'il est à vous de savoir le type que vous avez mis dans votre
 * objet json, mais en cas d'erreur la fonction retourne NULL ou -1)
 * donc si vous avez un doute la fonction json_get_type peut vous aider
 * */

////////////////////////////////////////////////////////////
/// \brief get the type of a json object
///
/// \param json the json object
/// \param key the key of the object you want to get
/// (NULL if you to get the type of the json object)
///
/// \return the type of the json object
///
////////////////////////////////////////////////////////////

int json_get_type(json_props_t *json, char *key);

/*-----------------------------*/

/* Pour récupérer la valeur d'un objet "complexe" il y a ces fonctions
 * qui prennent en paramètre un objet json et retourne un autre objet json.
 * */
/* json_get_object prend en paramètre un objet json et une clé et retourne
 * l'objet json qui a cette clé.
 * */

////////////////////////////////////////////////////////////
/// \brief get an object with his key from a json object
///
/// \param json parent object
/// \param key the key of the object you want to get
///
/// \return the object with the key you gave
///
////////////////////////////////////////////////////////////

json_props_t *json_get_object(json_props_t *json, char *key);

/* json_get_from_array prend en paramètre un props json et un index et
 * retourne l'objet json qui est à cet index
 * */

////////////////////////////////////////////////////////////
/// \brief get an array from a json object
///
/// \param json parent object
/// \param key the key of the array you want to get
///
/// \return the array with the key you gave
///
////////////////////////////////////////////////////////////

json_props_t *json_get_array(json_props_t *json, char *key);

/*-----------------------------*/

////////////////////////////////////////////////////////////
/// \brief get the size of an array
///
/// \param array
/// \param index
/// \return the type of the object at the index you gave
///
////////////////////////////////////////////////////////////

int json_get_type_from_array(json_props_t *array, int index);

////////////////////////////////////////////////////////////
/// \brief get an object from an array
///
/// \param array
/// \param index
/// \return the object at the index you gave
///
////////////////////////////////////////////////////////////

json_props_t *json_get_object_from_array(json_props_t *array, int index);

////////////////////////////////////////////////////////////
/// \brief get an array from an array
///
/// \param json
/// \param index
/// \return the array at the index you gave
///
////////////////////////////////////////////////////////////

json_props_t *json_get_array_from_array(json_props_t *json, int index);

////////////////////////////////////////////////////////////
/// \brief get a int from an array
///
/// \param array
/// \param index
/// \return the int at the index you gave
///
////////////////////////////////////////////////////////////

int json_get_int_from_array(json_props_t *array, int index);

////////////////////////////////////////////////////////////
/// \brief get a string from an array
///
/// \param array
/// \param index
/// \return the string at the index you gave
///
////////////////////////////////////////////////////////////

char *json_get_string_from_array(json_props_t *array, int index);

////////////////////////////////////////////////////////////
/// \brief get a bool from an array
///
/// \param array
/// \param index
/// \return the bool at the index you gave
///
////////////////////////////////////////////////////////////

int json_get_bool_from_array(json_props_t *array, int index);

////////////////////////////////////////////////////////////
/// \brief get the size of an array
///
/// \param array
/// \return the size of the array
///
////////////////////////////////////////////////////////////

int json_get_array_size(json_array_t *array);

/*-----------------------------*/

/* Pour récupérer un objets indenté dans plusieurs objets
 * il y a la fonction json_find_object:
 * elle prend en paramètre un objet json et un tableau de clé qui servira
 * de chemin pour trouver l'objet
 * USAGE:    json_find_object(obj, (char*[]){"window", "size", "width", NULL});
 * */

////////////////////////////////////////////////////////////
/// \brief get an object from a json object with a path of keys
///
/// \param json the parent object
/// \param keys the path you want to follow
/// \return the object or array at the path you gave
///
////////////////////////////////////////////////////////////

json_props_t *json_find_object(json_props_t *json, char **keys);

/*-----------------------------*/

/* Maintenant il y a les guides qui permettent de parcourir un objet json
 * d'une manière plus simple mais différentes des fonctions précédentes.
 * */

/* Un guide ne s'ouvre que sur des objets "complexe" (ARRAY ou OBJECT)
 * il a en paramètre l'objet json qu'il va parcourir et un index, et la taille
 * de l'objet json qui lui est passé.
 * */

typedef struct json_guide_s {
    json_props_t *json;
    int index;
    int size;
} json_guide_t;

/* Pour ouvrir un guide il faut utiliser la fonction json_open_guide
 * qui prend en paramètre un objet json et retourne un guide.
 * */

json_guide_t *json_open_guide(json_props_t *json);

/* Pour parcourir un guide il faut utiliser la fonction json_read_guide
 * qui prend en paramètre un guide et retourne un objet json
 * pour récupérer tout les objets d'un guide il faut faire une boucle
 * jusqu'a ce que la fonction retourne NULL...
 * en d'autre terme, la fonction guide est a utiliser plusieurs fois tant qu'il
 * y a des objets a parcourir, et renverra toujours un nouvel sous objet json
 * appartenant a l'objet json du guide.
 * */

json_props_t *json_read_guide(json_guide_t *guide);

/* Pour fermer un guide il faut utiliser la fonction json_close_guide
 * qui prend en paramètre le guide a fermer
 * */

void json_close_guide(json_guide_t *guide);

/*-----------------------------*/

/* Cette fonction permet de transformer un objet ou tableau json en un fichier
 * json, elle prend en paramètre le nom du fichier et le props json
 * */

////////////////////////////////////////
///  \brief Write a json file
///
///  \param name The name of the file
///  \param json The json object or array to transform
///
////////////////////////////////////////

void json_write_file(char *name, json_props_t *json);

/*-----------------------------*/

/* Pour pouvoir créer un objet ou un tableau json, il faut utiliser les
 * fonctions suivantes
 * */

////////////////////////////////////////
///  \brief Create a json object
///
///  \param key The key of the object
///
///  \return The json object
///
////////////////////////////////////////

json_props_t *json_init_object(char *key);

////////////////////////////////////////
///  \brief Create a json array
///
///  \param key The key of the array
///
///  \return The json array
///
////////////////////////////////////////

json_props_t *json_init_array(char *key);

/*-----------------------------*/

/* Pour pouvoir ajouter des valeurs a un objet ou un tableau json, il faut
 * utiliser les fonctions suivantes
 * (note: mettre une clé deja existante dans un objet remplacera
 * la valeur de celui ci)
 * */

////////////////////////////////////////
///  \brief Add a string to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the string
///  \param value The value of the string
///
////////////////////////////////////////

void json_add_string(json_props_t *json, char *key, char *value);

////////////////////////////////////////
///  \brief Add a int to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the int
///  \param value The value of the int
///
////////////////////////////////////////

void json_add_int(json_props_t *json, char *key, int value);

////////////////////////////////////////
///  \brief Add a bool to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the bool
///  \param value The value of the bool
///
////////////////////////////////////////

void json_add_bool(json_props_t *json, char *key, int value);

////////////////////////////////////////
///  \brief Add a null to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the null
///
////////////////////////////////////////

void json_add_null(json_props_t *json, char *key);

////////////////////////////////////////
///  \brief Add a json object to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the object
///  \param value The value of the object
///
////////////////////////////////////////

void json_add_object(json_props_t *json, char *key, json_props_t *value);

////////////////////////////////////////
///  \brief Add a json array to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the array
///  \param value The value of the array
///
////////////////////////////////////////

void json_add_array(json_props_t *json, char *key, json_props_t *value);

/* (note: pour ajouter un tableau ou un objet a un tableau ou un objet,
 * il faut les initialiser avec la fonction correspondante, puis les ajouter)
 * */

/*-----------------------------*/

/* Pour pouvoir retirer des props d'un objet ou un tableau json, il faut
 * utiliser la fonction suivante.
 * */

////////////////////////////////////////
///  \brief Remove a json props from a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the props
///
////////////////////////////////////////

void json_remove_props(json_props_t *json, char *key);

/*-----------------------------*/

/* Pour libérer la mémoire allouée par la structure json, et la détruire
 * il faut utiliser la fonction suivante.
 * */

////////////////////////////////////////////////////////////
/// \brief destroy a json object and all the objects it contains
///
/// \param json object to destroy
////////////////////////////////////////////////////////////

void json_destroy(json_props_t *json);

#endif //MY_JSON_MY_JSON_H
