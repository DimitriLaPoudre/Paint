/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** for my files
*/

#ifndef MY_H_
    #define MY_H_

    #include "linked_list.h"
    #include "garbage.h"
    #include "my_paint.h"
    #include <stdarg.h>
    #include <math.h>
    #include <sys/stat.h>

void my_putchar(char c);

void my_putstr(char const *str);

void my_puterror(char const *str);

int my_miniprintf(char const *format, ...);

int my_strlen(char const *str);

long long my_getnbr(char *str);

char *my_nbr_to_str(int nb);

long long my_power(long long nb, long long p);

long double my_power_float(long double nb, int p);

void my_putnbr(long long nb);

void my_putnbr_base(unsigned long long nb, char const *base);

char *my_stradd(char **src, char c);

char *my_strdup(char const *src);

char *my_strdup_na(char const *src);

char *my_strcat(char *dest, char const *src);

char *my_strcat2(char *dest, char const *src);

char *my_strcpy(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char **my_str_to_word_array(char *str, char *ban);

#endif /* MY_H_ */
