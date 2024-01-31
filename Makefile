##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Root's Makefile to run the others Makefiles
##

SOL_PATH	=	solver/

GEN_PATH	=	generator/

all:
	make -C $(SOL_PATH)
	make -C $(GEN_PATH)

clean:
	make clean -C $(SOL_PATH)
	make clean -C $(GEN_PATH)

fclean:	clean
	make fclean -C $(SOL_PATH)
	make fclean -C $(GEN_PATH)

re:	fclean all

.PHONY: all clean fclean re
