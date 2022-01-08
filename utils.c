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
    draw_all_obstacle(window, list, par);
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}

void utils(sfWindow *window, t_obstacle *list, t_par *par, t_obj *obj)
{
    move_all_obstacle(window, list, par);
    end(list, obj, par);
    collision(list, obj, par);
    move_all_bg(window, par);
    update(obj, sfClock_restart(par->clock7).microseconds/ 1000000.f);
}
