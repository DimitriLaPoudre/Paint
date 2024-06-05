/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** yes bebew
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strcat2(char *dest, char const *src)
{
    int i = 0;
    int test = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[test] != '\0'; test++)
        dest[i + test] = src[test];
    dest[i + test] = '\0';
    return dest;
}
