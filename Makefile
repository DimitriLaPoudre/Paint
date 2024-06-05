##
## EPITECH PROJECT, 2023
## Standard File
## File description:
## Makefile
##

NAME = Paint

SRC = src/main.c \
	  src/init.c \
	  src/analize_event.c \
	  src/update.c \
	  src/display.c \
	  src/menu_bar.c \
	  src/menu.c \
	  src/buttons.c \
	  src/pop_up.c \
	  src/cursor.c \
	  src/placeholder.c \
	  src/houdi.c \
	  src/ziak.c \
	  src/winnterzuko.c \
	  src/luther.c \
	  src/baby_hayabusa.c \
	  src/layer.c \
	  src/saving.c \
	  src/drawing.c \
	  src/undoredo.c \
	  src/function_pointer/file.c \
	  src/function_pointer/edit.c \
	  src/function_pointer/help.c \
	  src/function_pointer/pop_up.c \
	  src/hover_handling.c \
	  src/shapes.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include -l csfml-graphics -l csfml-system -l csfml-audio -l m

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L./lib/ -lglobal

clean:
	make -C lib/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C lib/ fclean
	rm -rf $(NAME)

re: fclean all
