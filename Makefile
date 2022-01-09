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
		has_touched.c \
		map.c \
		my_putstr.c \
		my_putchar.c \
		portal.c \
		text.c \
		my_itoa.c \
		my_revstr.c \
		score.c \
		my_strcat.c \
		game.c \
		highscore.c \
		my_strlen.c \
		my_get_nbr.c \
		txt_pos.c \
		sound.c \
		destroyer.c \
		win_utils.c \
		game_over.c \
		infinite.c \
		create_texture.c \
		loop.c \
		utils.c \
		utils2.c \
		events.c \
		pause.c \
		jump_utils.c \

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

all : 	$(NAME)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY : all clean fclean re