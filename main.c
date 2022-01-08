/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** main
*/
#include "my.h"

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    window = sfRenderWindow_create(mode, "My Runner", sfResize|sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

t_utils *get_par(int ac, char **av)
{
    if (ac == 2) {
        t_utils *par = malloc(sizeof(t_utils));
        create_textures(par);
        par->ac = ac;
        par->av = av;
        handle_input(par);
        return par;
    } else {
        char *test = generate_infinitemap();
        my_putstr(test);
    }
}

int main(int ac, char **av)
{
    if (ac != 1) {
        handle_options(ac, av);
    }
    if (ac == 1) {
    my_putstr("./my_runner: bad arguments: 0 given but 1 is required\n");
    my_putstr("retry with -h\n");
    return 84;
    }
}
