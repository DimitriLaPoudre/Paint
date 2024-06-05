##
## EPITECH PROJECT, 2023
## Makefile_my
## File description:
## Makefiile for mylib
##

NAME = libmy.a

SRC = my_putchar.c \
      my_putstr.c \
      my_puterror.c \
      my_mini_printf.c \
      my_strlen.c \
      my_getnbr.c \
      my_nbr_to_str.c \
      my_power.c \
      my_power_float.c \
      my_putnbr.c \
      my_putnbr_base.c \
      my_stradd.c \
      my_strdup.c \
      my_strdup_na.c \
      my_strcat.c \
      my_strcat2.c \
      my_strcpy.c \
      my_strcmp.c \
      my_strncmp.c \
      my_str_to_word_array.c \

OBJ = $(SRC:.c=.o)

all: libmy.a

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
