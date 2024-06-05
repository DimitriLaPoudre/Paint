/*
** EPITECH PROJECT, 2023
** my_stradd
** File description:
** my_stradd
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_stradd(char **src, char c)
{
    int len;
    char *str;

    if (src == NULL || (*src) == NULL) {
        str = malloc(sizeof(char) * 2);
        str[0] = c;
        str[1] = '\0';
        return str;
    }
    if (c == 0)
        (*src)[0] = '\0';
    for (len = 0; (*src)[len] != '\0'; len++);
    str = malloc(sizeof(char) * (len + 2));
    for (int i = 0; i < len; i++)
        str[i] = (*src)[i];
    str[len] = c;
    str[len + 1] = '\0';
    free((*src));
    return str;
}
