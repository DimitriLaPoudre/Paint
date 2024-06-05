/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCE-2-1-mypaint-raphael.launay
** File description:
** placeholder.c
*/

#include "my.h"

static void placeholder_rect(global_t *G, sfVector2i data, action_t *temp_act,
    sfVector2f main_pos)
{
    int x = data.x;
    int y = data.y;

    if (!(main_pos.x + x - G->pos_image.x
    >= (float)sfImage_getSize(temp_act->action).x
    || main_pos.x + x - G->pos_image.x < 0.0
    || main_pos.y + y - G->pos_image.y
    >= (float)sfImage_getSize(temp_act->action).y
    || main_pos.y + y - G->pos_image.y < 0.0)) {
        sfImage_setPixel(temp_act->action,
        main_pos.x + x - G->pos_image.x,
        main_pos.y + y - G->pos_image.y, G->color_use);
    }
}

static void swap_current(sfVector2f *main_pos, sfVector2f *current)
{
    int temp_int;

    if (current->x < main_pos->x) {
        temp_int = current->x;
        current->x = main_pos->x;
        main_pos->x = temp_int;
    }
    if (current->y < main_pos->y) {
        temp_int = current->y;
        current->y = main_pos->y;
        main_pos->y = temp_int;
    }
}

void release_rectangle(global_t *G)
{
    sfVector2f main_pos = (sfVector2f){G->pos_shape.x, G->pos_shape.y};
    sfVector2f current = i_to_2f(sfMouse_getPositionRenderWindow(G->window));
    sfVector2f size;
    int temp_int;
    layer_t *temp = *(G->layer);
    action_t *temp_act;

    if (G->active_action != Shapes)
        return;
    swap_current(&main_pos, &current);
    size = (sfVector2f){current.x - main_pos.x, current.y - main_pos.y};
    for (; temp != NULL && temp->id != G->layer_act; temp = temp->next);
    temp_act = *(temp->history);
    for (; temp_act != NULL && temp_act->id != temp->action_act;
    temp_act = temp_act->next);
    for (int x = 0; x <= size.x; x++) {
        for (int y = 0; y <= size.y; y++) {
            placeholder_rect(G, (sfVector2i){x, y}, temp_act, main_pos);
        }
    }
}

void placeholder_square(global_t *G)
{
    sfVector2f main_pos = (sfVector2f){RATIO_X(G->pos_shape.x),
    RATIO_Y(G->pos_shape.y)};
    sfVector2f current
    = ratio_from_i(sfMouse_getPositionRenderWindow(G->window), G);
    sfVector2f size = (sfVector2f){current.x - main_pos.x,
    current.y - main_pos.y};

    if (!G->is_action || main_pos.y < RATIO_Y(165) || current.y < RATIO_Y(165))
        return;
    sfRenderWindow_setView(G->window, G->main_view);
    sfRectangleShape_setOrigin(G->shape_r, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(G->shape_r, sfTransparent);
    sfRectangleShape_setPosition(G->shape_r, main_pos);
    sfRectangleShape_setSize(G->shape_r, size);
    sfRectangleShape_setOutlineColor(G->shape_r, G->color_use);
    sfRectangleShape_setOutlineThickness(G->shape_r, 2);
    sfRenderWindow_drawRectangleShape(G->window, G->shape_r, NULL);
    sfRectangleShape_setOutlineThickness(G->shape_r, 0);
}
