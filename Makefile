##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME = my_runner

SRC =	main.c \
		parallax.c \
		player.c \
		jump.c \
		obstacle.c \

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio -g3

all : 	$(NAME)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY : all clean fclean re