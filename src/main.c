/*
** EPITECH PROJECT, 2023
** Standard File
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    global_t *G = init_global();

    while (sfRenderWindow_isOpen(G->window)) {
        while (sfRenderWindow_pollEvent(G->window, &(G->event)))
            what_analize(G);
        update(G);
        display(G);
    }
    sfRenderWindow_destroy(G->window);
    DALLOC;
    sfCircleShape_destroy(G->shape_c);
    sfRectangleShape_destroy(G->shape_r);
    return 0;
}
