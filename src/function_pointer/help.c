/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** menu_bar_function.c
*/

#include "my.h"

void help_about(global_t *G, button_t *button)
{
    char str[152] = {0};

    my_strcat2(str, "\n\n\n\n\n\n\n\n\n         My Paint is a project\n  ");
    my_strcat2(str, "                with\n           the goal of remake \n ");
    my_strcat2(str, "    the original paint from window.     ");
    pop_up(G, str, 0, 1, "Ok", &pop_up_cancel);
}
