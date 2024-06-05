/*
** EPITECH PROJECT, 2023
** Standard File
** File description:
** my_str_to_word_array.c
*/

#include "../../include/my.h"

int is_ban(char c, char *ban)
{
    for (int i = 0; ban[i] != '\0'; i++) {
        if (ban[i] == c)
            return 1;
    }
    return 0;
}

char *switch_tmp_to_real(char **tmp, int state)
{
    int len;
    char *str;

    if (state != 0)
        return (*tmp);
    for (len = 0; (*tmp)[len] != '\0'; len++);
    str = ALLOC(sizeof(char) * (len + 1));
    for (int i = 0; i < len + 1; i++)
        str[i] = (*tmp)[i];
    free((*tmp));
    return str;
}

int count_word(char *str, char *ban)
{
    int state = -1;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_ban(str[i], ban))
            state = (state == -1 || i == 0) ? -1 : 1;
        else {
            count += (state != 0 || i == 0) ? 1 : 0;
            state = 0;
        }
    }
    return count;
}

char **my_str_to_word_array(char *str, char *ban)
{
    int state = -1;
    char **array = NULL;
    int array_index = 0;
    int size = count_word(str, ban);

    array = CALLOC(sizeof(char *) * (size + 1));
    for (int i = 0; str[i] != '\0' && size != 0; i++) {
        if (is_ban(str[i], ban)) {
            array[array_index]
            = switch_tmp_to_real(&(array[array_index]), state);
            array_index += (state == 0) ? 1 : 0;
            state = (state == -1 || i == 0) ? -1 : 1;
        } else {
            state = 0;
            array[array_index] = my_stradd(&(array[array_index]), str[i]);
        }
    }
    if (size - 1 == array_index && size != 0)
        array[array_index] = switch_tmp_to_real(&(array[array_index]), 0);
    return array;
}
