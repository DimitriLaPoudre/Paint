##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

NAME = libglobal.a

SRC = my/my_putchar.c \
      my/my_putstr.c \
      my/my_puterror.c \
      my/my_mini_printf.c \
      my/my_strlen.c \
      my/my_getnbr.c \
      my/my_nbr_to_str.c \
      my/my_power.c \
      my/my_power_float.c \
      my/my_putnbr.c \
      my/my_putnbr_base.c \
      my/my_stradd.c \
      my/my_strdup.c \
      my/my_strdup_na.c \
      my/my_strcat.c \
      my/my_strcat2.c \
      my/my_strcpy.c \
      my/my_strcmp.c \
      my/my_strncmp.c \
      my/my_str_isnum.c \
      my/my_str_to_word_array.c \
	list/list_add_prev.c \
      list/list_add_next.c \
      list/list_rev.c \
      list/list_len.c \
      list/list_del_node.c \
      list/list_del_nodes.c \
      list/list_function.c \
      list/list_sort_base.c \
      list/list_sort_cmp.c \
	garbage/alloc.c \
	garbage/alloc_sound.c \
      garbage/alloc_sprite.c \
	garbage/alloc_clock.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all
