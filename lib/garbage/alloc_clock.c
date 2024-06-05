/*
** EPITECH PROJECT, 2023
** Standard File
** File description:
** my_malloc.c
*/

#include "../../include/garbage.h"

void *aclock(void *path, size_t z)
{
    return (void *)sfClock_create();
}

void dclock(void *base)
{
    sfClock_destroy((sfClock *)base);
}
