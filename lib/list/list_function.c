/*
** EPITECH PROJECT, 2023
** my apply on nodes
** File description:
** apply a function on each node
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <stdio.h>

int list_function(llist *begin, void (*f)(void *))
{
    for (; begin != NULL; begin = begin->next)
        f(begin->data);
}
