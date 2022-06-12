##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## TASK01 : copy the library, copy the my.h, clean rule
##

SRC     =	src/main.c					\
			src/check_error.c			\
			src/input_event_manager.c	\
			src/create_objects.c		\
			src/player_movement.c		\
			src/animations_manager.c	\
			src/menu.c					\
			src/buttons.c				\
			src/map_update.c			\
			src/create_map.c			\
			src/collisions.c			\
			src/manage_enemies.c		\
			src/malloc_enemies.c		\
			src/setup_enemies.c			\
			src/sound.c					\
			src/menu_gamepad.c			\
			src/utils.c					\

CPPFLAGS=		-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system\
				-I./include -L./lib -lmy

CFLAGS  =       -Wall -Wextra -g3

OBJ     =       $(SRC:.c=.o)

NAME    =       my_rpg

all:    $(NAME)

$(NAME):        $(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS)
	make clean

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re