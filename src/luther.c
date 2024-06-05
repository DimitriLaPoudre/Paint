/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** luther.c
*/

#include "my.h"

void hide_show_layer(global_t *G, button_t *button)
{
    for (layer_t *tmp2 = *(G->layer); tmp2 != NULL; tmp2 = tmp2->next)
        if (tmp2->id == G->layer_act) {
            tmp2->active = (tmp2->active + 1) % 2;
            break;
        }
}

void set_shape(global_t *G, button_t *button)
{
    G->active_action = Shapes;
}

void help_resize(global_t *G)
{
    G->size_window = sfRenderWindow_getSize(G->window);
    sfView_setViewport(G->draw_view, (sfFloatRect){0,
    165.0 / G->size_window.y,
    1, (G->size_window.y - 165.0) / G->size_window.y});
    sfView_reset(G->draw_view,
    (sfFloatRect){-(float)(G->size_window.x), 0,
    (float)G->size_window.x, ((float)G->size_window.y - 165.0)});
    G->pos_image = (sfVector2f){\
    ((float)G->size_window.x - G->size_project.x) / 2,
    (((float)G->size_window.y - 165) - G->size_project.y) / 2 + 165};
}

sfVector2f i_to_2f(sfVector2i change)
{
    sfVector2f changed;

    changed.x = (float)change.x;
    changed.y = (float)change.y;
    return changed;
}

sfVector2f u_to_2f(sfVector2u change)
{
    sfVector2f changed;

    changed.x = (float)change.x;
    changed.y = (float)change.y;
    return changed;
}
