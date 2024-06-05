/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** list_sort.c
*/

#include "../../include/my.h"

void swap(llist *ll1, llist *ll2)
{
    void *tmp;

    tmp = ll1->data;
    ll1->data = ll2->data;
    ll2->data = tmp;
}

static short findll2(llist *ll1, llist **ll2, llist *pivot,
    int (*cmp)(llist *, llist *))
{
    for (; ll1 != *ll2; *ll2 = (*ll2)->prev) {
        if (cmp(pivot, *ll2) >= 0) {
            swap(ll1, *ll2);
            return 1;
        }
    }
    return 0;
}

static void help_sort_node(llist *ll1, llist *pivot, llist *end,
    int (*cmp)(llist *, llist *))
{
    if (cmp(pivot, ll1) < 0) {
        if (ll1 != pivot) {
            swap(ll1->prev, pivot);
            list_sort(pivot, ll1->prev, cmp);
        }
        list_sort(ll1, end, cmp);
    } else {
        swap(ll1, pivot);
        list_sort(pivot, ll1, cmp);
        list_sort(ll1->next, end, cmp);
    }
}

void list_sort(llist *data, llist *end, int (*cmp)(llist *, llist *))
{
    llist *ll1 = data;
    llist *ll2 = data;
    llist *pivot = data;

    if (pivot == end || pivot->next == end || pivot == NULL)
        return;
    for (; ll2->next != end; ll2 = ll2->next);
    for (ll1 = ll1->next; ll1 != ll2; ll1 = ll1->next) {
        if (cmp(pivot, ll1) < 0)
            findll2(ll1, &ll2, pivot, cmp);
        if (ll1 == ll2)
            break;
    }
    help_sort_node(ll1, pivot, end, cmp);
}
