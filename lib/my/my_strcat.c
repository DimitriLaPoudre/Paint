/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** yes bebew
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int test = 0;
    char *result = malloc(sizeof(char) \
    * (my_strlen(dest) + my_strlen(src) + 1));

    for (; dest[i] != '\0'; i++)
        result[i] = dest[i];
    for (; src[test] != '\0'; test++)
        result[i + test] = src[test];
    result[i + test] = '\0';
    return result;
}
