/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** ziak.c
*/

#include "my.h"

void modify_text(sfText *text, sfVector2f pos, char *content)
{
    sfText_setString(text, content);
    sfText_setPosition(text, pos);
}

void set_circle(global_t *G, button_t *button)
{
    G->drawing_type = Circleshape;
}

void set_square(global_t *G, button_t *button)
{
    G->drawing_type = Squareshape;
}

void set_draw(global_t *G, button_t *button)
{
    G->active_action = Draw;
}

void set_erase(global_t *G, button_t *button)
{
    G->active_action = Erase;
}
