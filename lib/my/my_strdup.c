/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** strdup man ca vit hein
*/

#include "../../include/my.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int len;
    char *str;

    if (src == NULL)
        return NULL;
    for (len = 0; src[len] != '\0'; len++);
    str = ALLOC(sizeof(char) * (len + 1));
    for (int i = 0; i <= len; i++)
        str[i] = src[i];
    return str;
}
