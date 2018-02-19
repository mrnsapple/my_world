
##
## EPITECH PROJECT, 2017
## 
## File description:
## 
##

SRC 	=	main.c			\
		my_puts.c		\
		my_puts2.c		\
		put_in_array.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	matchstick

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)	
	gcc -g -Wall -Werror -o $(NAME) $(SRC) -lm -l "c_graph_prog"
clean:
	$(RM) $(NAME)

fclean: clean
	rm -f $(OBJ) $(NAME) *~ *#

re:	fclean all
