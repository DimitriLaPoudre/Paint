/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** update.c
*/

#include "my.h"

static void saved_set_pixel(sfImage *saved, int i, int j, action_t *to_get)
{
    sfColor pixel = sfImage_getPixel(to_get->action, i, j);

    if (to_get->name == 0)
        sfImage_setPixel(saved, i, j, pixel);
    if (pixel.a == 0)
        return;
    sfImage_setPixel(saved, i, j, (to_get->name == 2)
    ? (sfColor){0, 0, 0, 0} : pixel);
}

void set_updated_image(sfImage *saved, action_t *to_get)
{
    sfVector2u img_size = sfImage_getSize(saved);

    for (int i = 0; i < img_size.x; i++) {
        for (int j = 0; j < img_size.y; j++) {
            saved_set_pixel(saved, i, j, to_get);
        }
    }
}

void update_image(global_t *G)
{
    for (layer_t *tmp2 = *(G->layer); tmp2 != NULL; tmp2 = tmp2->next) {
        for (action_t *tmp = *(tmp2->history); G->layer_act == tmp2->id
        && tmp != NULL && tmp->id <= tmp2->action_act; tmp = tmp->next) {
            set_updated_image(tmp2->res, tmp);
        }
        if (G->layer_act == tmp2->id)
            break;
    }
}

void update(global_t *G)
{
}
