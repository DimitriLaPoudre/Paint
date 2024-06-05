/*
** EPITECH PROJECT, 2023
** Standard File
** File description:
** my_malloc.c
*/

#include "../../include/garbage.h"

static void add_garbage(garbage_t **list, void *data)
{
    garbage_t *param = malloc(sizeof(*param));
    garbage_t *tmp = *list;

    param->data = data;
    param->next = NULL;
    if (tmp == NULL) {
        *list = param;
    } else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = param;
    }
}

void *allocat(void *(*create)(void *, size_t), void *size1, size_t size2,
    void (*destroy)(void *))
{
    static garbage_t *garbage = NULL;
    allocat_t *dstruct = NULL;

    if (size1 != 0 || size2 != 0) {
        dstruct = malloc(sizeof(allocat_t));
        dstruct->data_alloc = create(size1, size2);
        dstruct->f = destroy;
        add_garbage(&garbage, dstruct);
        return dstruct->data_alloc;
    }
    for (garbage_t *tmp = garbage; garbage != NULL; tmp = garbage) {
        tmp->data->f(tmp->data->data_alloc);
        free(tmp->data);
        garbage = garbage->next;
        free(tmp);
    }
    return NULL;
}

void *alloc_malloc(void *z, size_t size)
{
    return malloc(size);
}

void *alloc_calloc(void *z, size_t size)
{
    void *ptr = malloc(size);
    char *ptr_memset = ptr;

    for (int i = 0; i < size; i++)
        ptr_memset[i] = 0;
    return ptr;
}
