/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** winnterzuko.c
*/

#include "my.h"

void what_analize(global_t *G)
{
    if (G->pop_up->active)
        analize_pop_up(G);
    else
        analize_event(G);
}

void add_layer(global_t *G, button_t *button)
{
    create_layer(G);
}

void rm_layer(global_t *G, button_t *button)
{
    destroy_last(G);
}

void down_layer(global_t *G, button_t *button)
{
    if (G->layer_act > 0)
        G->layer_act--;
}

void up_layer(global_t *G, button_t *button)
{
    int i = 0;

    for (layer_t *temp = *(G->layer); temp->next != NULL; temp = temp->next)
        i++;
    if (G->layer_act >= i)
        return;
    G->layer_act++;
}
