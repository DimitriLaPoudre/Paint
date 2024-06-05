/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCE-2-1-mypaint-raphael.launay
** File description:
** shapes.c
*/

#include "my.h"

static void put_circle(global_t *G, sfVector2i value,
    sfImage *img, sfVector2f pixel)
{
    sfColor to_draw = G->active_action == Erase ? G->color_bg : G->color_use;
    int x = value.x;
    int y = value.y;

    if (x * x + y * y <= G->thickness * G->thickness
    && !(pixel.x + x >= (float)sfImage_getSize(img).x
    || pixel.x + x < 0.0
    || pixel.y + y >= (float)sfImage_getSize(img).y
    || pixel.y + y < 0.0)) {
        sfImage_setPixel(img, pixel.x + x, pixel.y + y, to_draw);
    }
}

void circle_on_pixel(global_t *G, sfImage *img, sfVector2f pixel)
{
    for (int x = -G->thickness; x <= G->thickness; x++) {
        for (int y = -G->thickness; y <= G->thickness; y++) {
            put_circle(G, (sfVector2i){x, y}, img, pixel);
        }
    }
}

static void put_square(global_t *G, sfVector2i value,
    sfImage *img, sfVector2f pixel)
{
    sfColor to_draw = G->active_action == Erase ? G->color_bg : G->color_use;
    int x = value.x;
    int y = value.y;

    if (!(pixel.x + x >= (float)sfImage_getSize(img).x
    || pixel.x + x < 0.0
    || pixel.y + y >= (float)sfImage_getSize(img).y
    || pixel.y + y < 0.0)) {
        sfImage_setPixel(img, pixel.x + x, pixel.y + y, to_draw);
    }
}

void square_on_pixel(global_t *G, sfImage *img, sfVector2f pixel)
{
    for (int x = -G->thickness; x <= G->thickness; x++) {
        for (int y = -G->thickness; y <= G->thickness; y++) {
            put_square(G, (sfVector2i){x, y}, img, pixel);
        }
    }
}
