/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** main
*/
#include "my.h"

int test(t_obstacle *list)
{
    int i = 4;
    int pos = 3000;
    while (i != 0) {
        pos += 1000;
        i--;
    }
}

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    window = sfRenderWindow_create(mode, "My Runner", sfResize|sfClose, NULL);
    sfWindow_setFramerateLimit(window, 60);
    return window;
}

int main(int ac, char **av)
{
    if (ac != 1) {
        sfRenderWindow *window = create_window();
        start_menu(ac, av, window);
    }
    if (ac == 1) {
    my_putstr("./my_runner: bad arguments: 0 given but 1 is required\n");
    my_putstr("retry with -h\n");
    return 84;
    }
}
