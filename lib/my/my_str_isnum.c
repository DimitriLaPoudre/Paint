/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** for know if a str is num
*/

#include "../../include/my.h"

int my_str_isnum(char const *str, int *i, float *value)
{
    char comma = 0;

    for (; str[*i] != '\0' && str[*i] != '\n' && str[*i] != ' '; (*i)++) {
        if ((str[*i] < 48 || str[*i] > 57) && (str[*i] != '.'
        || (str[*i] == '.' && comma > 0)))
            return 0;
        if (str[*i] == '.') {
            comma = 1;
            continue;
        }
        if (comma == 0) {
            *value = *value * 10 + (float)(str[*i] - 48);
        } else {
            *value = *value + my_power_float(0.1, comma) *\
            (float)(str[*i] - 48);
            comma++;
        }
    }
    return 1;
}
