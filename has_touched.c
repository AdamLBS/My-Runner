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
        bounding_box.height += -100;
        if (sfFloatRect_intersects(&bounding_box, &bounding_box2, NULL) && list->type == 1)
            write(1, "Touched", 8);
        list = list->next;
    }
    list = tmp;
}

void end(t_obstacle *list, t_obj *player, sfRenderWindow *window)
{
    t_obstacle *tmp = list;
    while(list != NULL) {
        sfFloatRect bounding_box = sfSprite_getGlobalBounds(player->sprite);
        sfFloatRect bounding_box2 = sfSprite_getGlobalBounds(list->sprite);
        bounding_box.width += -100;
        if (sfFloatRect_intersects(&bounding_box, &bounding_box2, NULL) && list->type == 2)
            sfRenderWindow_close(window);
        list = list->next;    
    }
    list = tmp;
}