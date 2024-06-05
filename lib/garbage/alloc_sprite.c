/*
** EPITECH PROJECT, 2023
** Standard File
** File description:
** my_malloc.c
*/

#include "../../include/garbage.h"

void *asprite(void *path, size_t z)
{
    sprite_t *base = malloc(sizeof(sprite_t));

    base->texture = sfTexture_createFromFile((char *)path, NULL);
    base->sprite = sfSprite_create();
    sfSprite_setTexture(base->sprite, base->texture, sfTrue);
    return (void *)base;
}

void dsprite(void *base)
{
    sfTexture_destroy(((sprite_t *)base)->texture);
    sfSprite_destroy(((sprite_t *)base)->sprite);
    free(base);
}
