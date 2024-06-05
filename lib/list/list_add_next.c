/*
** EPITECH PROJECT, 2023
** my_put_in_list.c
** File description:
** my_put_in_list.c
*/

#include "../../include/linked_list.h"
#include <stdlib.h>

void list_add_next(llist **list, void *data)
{
    llist *param = malloc(sizeof(*param));
    llist *tmp = *list;

    param->data = data;
    param->next = NULL;
    if (tmp == NULL) {
        param->prev = NULL;
        *list = param;
    } else {
        for (; tmp->next != NULL; tmp = tmp->next);
        param->prev = tmp;
        tmp->next = param;
    }
}
