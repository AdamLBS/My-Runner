/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** loop
*/

#include "my.h"

void manage_end(t_par *par, sfRenderWindow *window, t_utils *val,
t_obstacle *list)
{
    if (par->win == 1) {
        destroy_obstacles(&list);
        won_menu(val, window, par);
    }
    if (par->loose == 1) {
        write_score(par->score);
        destroy_obstacles(&list);
        free(list);
        game_over(val, window, par);
    }
}
