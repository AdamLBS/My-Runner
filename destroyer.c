/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** destroyer
*/

#include "my.h"

void destroy_sounds(t_par *par, t_obj *obj)
{
    sfMusic_stop(par->music->music);
    sfMusic_destroy(par->music->music);
    sfSound_destroy(obj->jump_sound->sound);
    sfSoundBuffer_destroy(obj->jump_sound->soundbuffer);
}

void destroy_obstacles(t_obstacle **list)
{
    while ((*list) != NULL) {
        sfSprite_destroy((*list)->sprite);
        (*list) = (*list)->next;
    }
}
