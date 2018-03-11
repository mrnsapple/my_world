##
## EPITECH PROJECT, 2018
## jfjf
## File description:
## by oriol
##

SRC 	=	main.c			\
		my_puts.c		\
		my_puts2.c		\
		put_in_array.c		\
		water.c			\
		map_creation.c		\
		rectangle.c		\
		building.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	my_world

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)	
	gcc -g -Wall -Werror -o $(NAME) $(SRC) -lm -l "c_graph_prog"
clean:
	$(RM) $(NAME)

fclean: clean
	rm -f $(OBJ) $(NAME) *~ *#

re:	fclean all
