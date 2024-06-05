/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** display.c
*/

#include "my.h"

static void display_all_hover(global_t *G)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(G->window);
    button_t *temp = *(G->buttons);

    if (G->menu_bar_wall_active != -1)
        return;
    for (; temp != NULL && temp->id != G->to_hover; temp = temp->next);
    if (G->to_hover == -1 || temp == NULL)
        return;
    set_text(G, temp->hover, (sfVector2f){pos.x, pos.y - 20}, 15, sfBlack);
}

void display(global_t *G)
{
    sfRenderWindow_setView(G->window, G->main_view);
    sfRenderWindow_clear(G->window, (sfColor){150, 150, 150, 255});
    display_menu(G);
    display_menu_bar(G);
    if (G->draw_hover)
        sfRenderWindow_drawSprite(G->window, G->hover_color, NULL);
    display_all_hover(G);
    if (G->size_window.y > 165) {
        sfRenderWindow_setView(G->window, G->draw_view);
        display_layer(G);
        sfRenderWindow_setMouseCursorVisible(G->window, sfTrue);
        if (G->active_action == Shapes)
            placeholder_square(G);
        else
            display_cursor(G);
    }
    if (G->pop_up->active)
        display_pop_up(G);
    sfRenderWindow_display(G->window);
}
