/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** pop_up.c
*/

#include "my.h"

void pop_up_jpg(global_t *G)
{
    G->saving_type = Jpg;
    save_img(G);
    G->pop_up->active = 0;
    G->menu_bar_wall_active = -1;
}

void pop_up_png(global_t *G)
{
    G->saving_type = Png;
    save_img(G);
    G->pop_up->active = 0;
    G->menu_bar_wall_active = -1;
}

void pop_up_bmp(global_t *G)
{
    G->saving_type = Bmp;
    save_img(G);
    G->pop_up->active = 0;
    G->menu_bar_wall_active = -1;
}

void pop_up_cancel(global_t *G)
{
    G->pop_up->active = 0;
    G->menu_bar_wall_active = -1;
}
