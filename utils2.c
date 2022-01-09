/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** utils2
*/

#include "my.h"

void write_map(char *map)
{
    FILE *fd;
    fd = fopen("random.txt", "w+");
    fwrite(map, 1, my_strlen(map), fd);
    fclose(fd);
    my_putstr("The random map has been written in random.txt\n");
}

void handle_options(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        print_help();
        return 0;
    }
    if (av[1][0] == '-' && av[1][1] == 'r') {
        reset_score();
        return 0;
    }
    if (av[1][0] == '-' && av[1][1] == 'R') {
        generate_random();
        return 0;
    }
    if (av[1][0] == '-' && av[1][1] != 'i') {
        my_putstr("Invalid option\n");
        return 84;
    }
    return handle_game(ac, av);
}

int handle_game(int ac, char **av)
{
    FILE *file;
    int exists;
    if ((file = fopen(av[1], "r")) && av[1][1] != 'i') {
        fclose(file);
        exists = 1;
    } else
        exists = 0;
    if (exists != 1 && av[1][1] != 'i') {
        my_putstr("File doesn't exist\n");
        return 84;
    }
    t_utils *par = get_par(ac, av);
    if (av[1][1] == 'i')
    par->map = generate_infinitemap();
    sfRenderWindow *window = create_window();
    start_menu(par, window);
    return 0;
}

void print_help(void)
{
    my_putstr("Welcome on My Runner !\n\n");
    my_putstr("The rules are simple : JUMP ABOVE THE TREES\n");
    my_putstr("Be careful ! The speed might increase and");
    my_putstr(" you only have one life !\n\n");
    my_putstr("User inputs are : \n");
    my_putstr("Press ESC to leave the game. \n");
    my_putstr("Press P to pause the game.\n");
    my_putstr("Press S to start the game. \n");
    my_putstr("Press R to resume the game. \n");
    my_putstr("Press Escape to jump.\n");
    my_putstr("Press Arrow-Down to quickly go back on the ground.\n\n");
    my_putstr("Available commands are : \n");
    my_putstr("./my_runner [map] to launch the game with a map.\n");
    my_putstr("./my_runner -h to view this message.\n");
    my_putstr("./my_runner -r to set the highscore to 0.\n");
    my_putstr("./my_runner -i to start infinite mode with a random");
    my_putstr(" generated level.\n");
    my_putstr("./my_runner -R to generate a random map in random.txt.\n\n");
    my_putstr("Good game and good luck fellow runner !\n");
}
