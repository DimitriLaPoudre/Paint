/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCE-2-1-mypaint-raphael.launay
** File description:
** saving.c
*/

#include "my.h"

static void pixel_transparency(sfImage *img, int i, int j)
{
    if (sfImage_getPixel(img, i, j).a == 0)
        sfImage_setPixel(img, i, j, sfWhite);
}

static void fill_transparency(sfImage *img)
{
    sfVector2u img_size = sfImage_getSize(img);

    for (int i = 0; i < img_size.x; i++)
        for (int j = 0; j < img_size.y; j++)
            pixel_transparency(img, i, j);
}

sfColor get_new_color(sfColor first, sfColor second)
{
    sfColor res = (sfColor){0, 0, 0, 255};
    float alpha_wann = first.a / 255.0f;
    float alpha_second = second.a / 255.0f;

    res.r = (second.r * alpha_second) + (first.r * (1 - alpha_wann));
    res.g = (second.g * alpha_second) + (first.g * (1 - alpha_wann));
    res.b = (second.b * alpha_second) + (first.b * (1 - alpha_wann));
    return res;
}

static void saved_set_pixel(global_t *G, sfImage *saved,
    sfVector2i pos, sfColor pixel)
{
    sfColor new = (sfColor){0, 0, 0, 0};

    switch (pixel.a) {
        case 0:
            break;
        case 255:
            sfImage_setPixel(saved, pos.x, pos.y, pixel);
            break;
        default:
            new = get_new_color(sfImage_getPixel(saved, pos.x, pos.y), pixel);
            sfImage_setPixel(saved, pos.x, pos.y, new);
    }
    return;
}

static void set_image_saved(global_t *G, sfImage *saved, sfImage *to_get)
{
    sfVector2u img_size = sfImage_getSize(to_get);

    for (int i = 0; i < img_size.x; i++)
        for (int j = 0; j < img_size.y; j++)
            saved_set_pixel(G, saved, (sfVector2i){i, j},
            sfImage_getPixel(to_get, i, j));
}

void switch_save(global_t *G, char **tmp)
{
    switch (G->saving_type) {
        case (Jpg):
            *tmp = my_strcat(G->pop_up->input, ".jpg");
            break;
        case (Png):
            *tmp = my_strcat(G->pop_up->input, ".png");
            break;
        case (Bmp):
            *tmp = my_strcat(G->pop_up->input, ".bmp");
            break;
    }
}

void save_img(global_t *G)
{
    layer_t *temp = *(G->layer);
    sfColor background = G->saving_type == Png ? sfTransparent : G->color_bg;
    sfImage *final = sfImage_createFromColor(G->size_project.x,
    G->size_project.y, background);
    char *tmp = NULL;

    switch_save(G, &tmp);
    for (; temp != NULL; temp = temp->next) {
        if (!temp->active)
            continue;
        set_image_saved(G, final, temp->res);
    }
    if (G->saving_type != Png)
        fill_transparency(final);
    sfImage_saveToFile(final, tmp);
    sfImage_destroy(final);
    free(tmp);
}
