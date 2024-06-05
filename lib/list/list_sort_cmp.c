/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** list_sort_cmp.c
*/

#include "../../include/my.h"

int cmp_alpha(llist *pivot, llist *opp)
{
    return my_strcmp(pivot->data, opp->data);
}
