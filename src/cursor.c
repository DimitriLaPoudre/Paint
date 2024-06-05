/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** cursor.c
*/

#include "my.h"

void circle_cursor(global_t *G, sfVector2i pos)
{
    float scale_factor;
    sfFloatRect to_scale;

    sfRenderWindow_setMouseCursorVisible(G->window, sfFalse);
    sfSprite_setPosition(G->cursor,
    (sfVector2f){RATIO_X(pos.x), RATIO_Y(pos.y)});
    to_scale = sfSprite_getLocalBounds(G->cursor);
    scale_factor = (2.0f * G->thickness);
    if (G->thickness < 3)
        scale_factor = 6;
    sfSprite_setScale(G->cursor,
    (sfVector2f){RATIO_X(scale_factor / to_scale.width),
    RATIO_Y(scale_factor / to_scale.height)});
    sfRenderWindow_drawSprite(G->window, G->cursor, NULL);
}

void square_cursor(global_t *G, sfVector2i pos)
{
    sfRenderWindow_setMouseCursorVisible(G->window, sfFalse);
    sfRectangleShape_setPosition(G->shape_r, (sfVector2f){RATIO_X(pos.x),
    RATIO_Y(pos.y)});
    sfRectangleShape_setFillColor(G->shape_r, sfTransparent);
    sfRectangleShape_setOutlineColor(G->shape_r, sfBlack);
    sfRectangleShape_setOutlineThickness(G->shape_r, 2);
    sfRectangleShape_setOrigin(G->shape_r, (sfVector2f){RATIO_X(G->thickness),
    RATIO_Y(G->thickness)});
    if (G->thickness == 0) {
        sfRectangleShape_setSize(G->shape_r,
        (sfVector2f){RATIO_X(1), RATIO_Y(1)});
    } else {
        sfRectangleShape_setSize(G->shape_r,
        (sfVector2f){RATIO_X(G->thickness * 2), RATIO_Y(G->thickness * 2)});
    }
    sfRenderWindow_drawRectangleShape(G->window, G->shape_r, NULL);
    sfRectangleShape_setOrigin(G->shape_r, (sfVector2f){0, 0});
    sfRectangleShape_setOutlineThickness(G->shape_r, 0);
}

void display_cursor(global_t *G)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(G->window);

    sfRenderWindow_setView(G->window, G->main_view);
    if (pos.y > 165 && !G->pop_up->active) {
        switch (G->drawing_type) {
            case Circleshape:
                circle_cursor(G, pos);
                return;
            case Squareshape:
                square_cursor(G, pos);
                return;
        }
    }
    sfRenderWindow_setMouseCursorVisible(G->window, sfTrue);
}
