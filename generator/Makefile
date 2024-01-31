##
## EPITECH PROJECT, 2022
## B-PSU-100-PAR-1-1-sokoban-damian.gil
## File description:
## Makefile
##

SRC_PATH = src/

LIB_PATH = lib/my/

SRC =	main.c						\
		$(SRC_PATH)check_maze.c		\
		$(SRC_PATH)generation.c		\
		$(LIB_PATH)my_putchar.c		\
		$(LIB_PATH)my_putstr.c		\
		$(LIB_PATH)my_show_array.c	\
		$(LIB_PATH)my_strlen.c		\
		$(LIB_PATH)my_neurolaser.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(SRC) -o $(NAME) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
