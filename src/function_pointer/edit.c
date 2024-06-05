/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** menu_bar_function.c
*/

#include "my.h"

void edit_pencil(global_t *G, button_t *button)
{
    G->active_action = Draw;
}

void edit_eraser(global_t *G, button_t *button)
{
    G->active_action = Erase;
}

void edit_rectangle(global_t *G, button_t *button)
{
    G->active_action = Shapes;
}

void edit_undo(global_t *G, button_t *button)
{
    undo(G, button);
}

void edit_redo(global_t *G, button_t *button)
{
    redo(G, button);
}
