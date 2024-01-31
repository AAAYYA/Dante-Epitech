##
## EPITECH PROJECT, 2022
## B-PSU-100-PAR-1-1-sokoban-damian.gil
## File description:
## Makefile
##

SRC_PATH = src/

LIB_PATH = lib/my/

SRC =	main.c									\
		$(SRC_PATH)maze_solving.c				\
		$(LIB_PATH)my_strlen.c					\
		$(LIB_PATH)my_neurolaser.c				\
		$(LIB_PATH)my_str_to_array_main.c		\
		$(LIB_PATH)my_str_to_array_secondary.c


OBJ	=	$(SRC:.c=.o)

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
