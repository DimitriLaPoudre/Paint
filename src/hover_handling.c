/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCE-2-1-mypaint-raphael.launay
** File description:
** hover_handling.c
*/

#include "my.h"

static void display_color_hovered2(global_t *G, sfColor clicked_color,
    sfMouseMoveEvent pos_move)
{
    sfSprite_setScale(G->hover_color, (sfVector2f){RATIO_X(1), RATIO_Y(1)});
    sfSprite_setPosition(G->hover_color,
    (sfVector2f){RATIO_X(pos_move.x), RATIO_Y(pos_move.y)});
    sfSprite_setColor(G->hover_color, clicked_color);
    G->draw_hover = 1;
}

void display_color_hovered(global_t *G, button_t *current,
    sfMouseMoveEvent pos_move)
{
    sfVector2f pixel = {pos_move.x - current->pos.left,
    pos_move.y - current->pos.top};
    sfColor clicked_color;

    if (pixel.x >= (float)sfImage_getSize(sfTexture_copyToImage( \
    sfSprite_getTexture(current->icon))).x
    || pixel.x < 0.0
    || pixel.y >= (float)sfImage_getSize(sfTexture_copyToImage( \
    sfSprite_getTexture(current->icon))).y
    || pixel.y < 0.0) {
        G->draw_hover = 0;
        return;
    }
    clicked_color = sfImage_getPixel(sfTexture_copyToImage( \
    sfSprite_getTexture(current->icon)), pixel.x, pixel.y);
    if (clicked_color.a != 255) {
        G->draw_hover = 0;
        return;
    }
    display_color_hovered2(G, clicked_color, pos_move);
}
