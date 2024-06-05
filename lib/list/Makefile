##
## EPITECH PROJECT, 2023
## Makefile_my
## File description:
## Makefiile for mylib
##

NAME = liblist.a

SRC = list_add_prev.c \
      list_add_next.c \
      list_rev.c \
      list_len.c \
      list_del_node.c \
      list_del_nodes.c \
      list_function.c \
      list_sort_base.c \
      list_sort_cmp.c

OBJ = $(SRC:.c=.o)

all: liblist.a

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
