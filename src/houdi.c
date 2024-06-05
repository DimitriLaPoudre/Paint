/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** hoodie.c
*/

#include "my.h"

void color_palette_interaction(global_t *G, button_t *button)
{
    sfVector2f pos_click = i_to_2f(sfMouse_getPositionRenderWindow(G->window));
    sfColor clicked_color;

    pos_click = (sfVector2f){pos_click.x - button->pos.left,
    pos_click.y - button->pos.top};
    if (pos_click.x >= (float)sfImage_getSize(sfTexture_copyToImage( \
    sfSprite_getTexture(button->icon))).x
    || pos_click.x < 0.0
    || pos_click.y >= (float)sfImage_getSize(sfTexture_copyToImage( \
    sfSprite_getTexture(button->icon))).y
    || pos_click.y < 0.0) {
        return;
    }
    clicked_color = sfImage_getPixel(sfTexture_copyToImage( \
    sfSprite_getTexture(button->icon)), pos_click.x, pos_click.y);
    if (clicked_color.a != 255)
        return;
    G->color_use = clicked_color;
}

void color_buttons_hd(global_t *G, button_t *button)
{
    G->color_use = button->color;
}

void none(global_t *G, button_t *button)
{
    return;
}

void thick_minus(global_t *G, button_t *button)
{
    if (G->thickness > 0)
        G->thickness--;
}

void thick_plus(global_t *G, button_t *button)
{
    if (G->thickness < 50)
        G->thickness++;
}
