/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** struct of my list
*/

#ifndef MY_LIST_
    #define MY_LIST_

    #include <stddef.h>

typedef struct linked_list {
    void *data;
    struct linked_list *next;
    struct linked_list *prev;
} llist;

void list_add_prev(llist **list, void *data);

void list_add_next(llist **list, void *data);

void list_rev(llist **begin);

int list_len(llist *begin);

int list_del_node(llist **begin, void const *data_ref);

int list_del_nodes(llist **begin, void const *data_ref);

int list_function(llist *begin, void (*f)(void *));

void list_sort(llist *data, llist *end, int (*cmp)(llist *, llist *));

#endif /* MY_LIST_ */
