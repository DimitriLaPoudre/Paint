/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** undoredo.c
*/

#include "my.h"

void undo(global_t *G, button_t *button)
{
    layer_t *temp = *(G->layer);
    action_t *temp_act;

    for (; temp != NULL && temp->id != G->layer_act; temp = temp->next);
    temp_act = *(temp->history);
    for (; temp_act != NULL && temp_act->id != temp->action_act;
    temp_act = temp_act->next);
    if (temp->action_act >= 1)
        temp->action_act--;
    update_image(G);
}

void redo(global_t *G, button_t *button)
{
    layer_t *temp = *(G->layer);
    action_t *temp_act;

    for (; temp != NULL && temp->id != G->layer_act; temp = temp->next);
    temp_act = *(temp->history);
    for (; temp_act != NULL && temp_act->id != temp->action_act;
    temp_act = temp_act->next);
    if (temp_act->next != NULL)
        temp->action_act++;
    update_image(G);
}
