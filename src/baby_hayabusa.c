/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** baby_hayabusa.c
*/

#include "my.h"

sfVector2f ratio_from_u(sfVector2u change, global_t *G)
{
    sfVector2f changed;

    changed.x = RATIO_X(change.x);
    changed.y = RATIO_Y(change.y);
    return changed;
}

sfVector2f ratio_from_i(sfVector2i change, global_t *G)
{
    sfVector2f changed;

    changed.x = RATIO_X(change.x);
    changed.y = RATIO_Y(change.y);
    return changed;
}

sfVector2f ratio_from_f(sfVector2f change, global_t *G)
{
    sfVector2f changed;

    changed.x = RATIO_X(change.x);
    changed.y = RATIO_Y(change.y);
    return changed;
}
