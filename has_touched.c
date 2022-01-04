/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** has_touched
*/

#include "my.h"


void collision(t_obstacle *list, t_obj *player)
{
    t_obstacle *tmp = list;
    while (list != NULL) {
   sfFloatRect bounding_box = sfSprite_getGlobalBounds(player->sprite);
   sfFloatRect bounding_box2 = sfSprite_getGlobalBounds(list->sprite);
        if (sfFloatRect_intersects(&bounding_box, &bounding_box2, NULL))
            write(1, "Touched", 8);
        list = list->next;
    }
    list = tmp;
}