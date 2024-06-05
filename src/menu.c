/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** menu.c
*/

#include "my.h"

void set_text(global_t *G, char *str, sfVector2f pos, ...)
{
    va_list list;

    va_start(list, pos);
    sfText_setString(G->text, str);
    sfText_setCharacterSize(G->text, va_arg(list, int));
    sfText_setScale(G->text, (sfVector2f){1, 1});
    sfText_setPosition(G->text,
    (sfVector2f){RATIO_X(pos.x) \
    - RATIO_X(sfText_getGlobalBounds(G->text).width / 2),
    RATIO_Y(pos.y) - RATIO_Y(sfText_getGlobalBounds(G->text).height / 2)});
    sfText_setScale(G->text, (sfVector2f){RATIO_X(1), RATIO_Y(1)});
    sfText_setColor(G->text, va_arg(list, sfColor));
    sfRenderWindow_drawText(G->window, G->text, NULL);
    va_end(list);
}

static void layer_info(global_t *G)
{
    int i = 0;

    for (layer_t *temp = *(G->layer); temp->next != NULL; temp = temp->next)
        i++;
    set_text(G, "Layers:", (sfVector2f){310, 65}, 15, sfBlack);
    set_text(G, "Current:", (sfVector2f){315, 100}, 15, sfBlack);
    set_text(G, my_nbr_to_str(i), (sfVector2f){308, 80}, 15, sfBlack);
    set_text(G, my_nbr_to_str(G->layer_act),
    (sfVector2f){308, 115}, 15, sfBlack);
}

static void displayed_color(global_t *G)
{
    sfRectangleShape_setPosition(G->shape_r,
    (sfVector2f){RATIO_X(730), RATIO_Y(80)});
    sfRectangleShape_setFillColor(G->shape_r, G->color_use);
    sfRectangleShape_setOutlineThickness(G->shape_r, 2);
    sfRectangleShape_setOutlineColor(G->shape_r, sfBlack);
    sfRectangleShape_setSize(G->shape_r,
    (sfVector2f){RATIO_X(30), RATIO_Y(30)});
    set_text(G, "Color:", (sfVector2f){745, 55}, 15, sfBlack);
    layer_info(G);
    sfRenderWindow_drawRectangleShape(G->window, G->shape_r, NULL);
    sfRectangleShape_setOutlineThickness(G->shape_r, 0);
}

void display_menu(global_t *G)
{
    char *tmp_thickness = my_nbr_to_str(G->thickness * 2 + 1);
    int show = 0;

    sfRectangleShape_setPosition(G->shape_r, (sfVector2f){0,
    (25 * 600 / G->size_window.y)});
    sfRectangleShape_setFillColor(G->shape_r, (sfColor){200, 200, 200, 255});
    sfRectangleShape_setSize(G->shape_r, (sfVector2f){800,
    (140 * 600 / G->size_window.y)});
    sfRenderWindow_drawRectangleShape(G->window, G->shape_r, NULL);
    display_buttons(G);
    displayed_color(G);
    set_text(G, " thickness:", (sfVector2f){150, 32}, 15, sfBlack);
    set_text(G, tmp_thickness, (sfVector2f){150, 48}, 14, sfBlack);
    for (layer_t *tmp2 = *(G->layer); tmp2 != NULL; tmp2 = tmp2->next)
        if (tmp2->id == G->layer_act) {
            show = tmp2->active;
            break;
        }
    set_text(G, (show) ? "show" : "hide", (sfVector2f){262, 140}, 15, sfBlack);
}
