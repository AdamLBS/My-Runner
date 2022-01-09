/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** utils
*/

#include "my.h"

void draw_everything(sfWindow *window, t_obstacle *list, t_par *par,
t_obj *obj)
{
    draw_all_bg(window, par);
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
    draw_all_obstacle(window, list, par);
}

void utils(sfWindow *window, t_obstacle *list, t_par *par, t_obj *obj)
{
    move_all_obstacle(window, list, par);
    end(list, obj, par);
    collision(list, obj, par);
    move_all_bg(window, par);
    update(obj, sfClock_restart(par->clock7).microseconds/ 1000000.f);
}

void handle_input(t_utils *par)
{
    if (par->map)
        return;
    if (par->av[1][0] == '-' && par->av[1][1] == 'i') {
        par->map = generate_infinitemap();
    } else if (par->av[1][0] != '-') {
        par->map = openfile(par->av[1]);
    }
}

char *generate_random(void)
{
    srand(time(NULL));
    int size = rand() % 300;
    int tmp = 0;
    char *map = malloc(sizeof(char) * size + 1);
    for (int i = 0 ; tmp != size; tmp++) {
        int obstacle = rand() % 3;
        if (obstacle == 0)
            obstacle++;
        map[i] = obstacle + '0';
        i++;
    }
    map[tmp] = '3';
    tmp++;
    map[tmp] = '\0';
    write_map(map);
    return map;
}
