/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** my_nbr_to_str.c
*/

#include "../../include/my.h"

char *my_nbr_to_str(int nb)
{
    int i = 0;
    int j = 0;
    char *res = NULL;
    int sign = 0;

    if (nb <= 0) {
        sign = 1;
        nb = -nb;
    }
    for (; nb / my_power(10, i) != 0; i++);
    res = malloc(sizeof(char) * (i + sign + 1));
    res[0] = (nb == 0) ? '0' : '-';
    res[i + sign] = '\0';
    j += sign;
    for (; i > 0; j++) {
        i--;
        res[j] = nb / my_power(10, i) + '0';
        nb = nb % my_power(10, i);
    }
    return res;
}
