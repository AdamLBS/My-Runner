/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** portal
*/

#include "my.h"

t_obstacle *create_portal(char *path, int x, sfTexture *text)
{
    sfIntRect rect;
    sfVector2f pos = {x, 750};
    rect.width = -299;
    rect.height = 330;
    rect.left = 299;
    rect.top = 0;
    t_obstacle *obj = malloc(sizeof(t_obstacle));
    obj->texture = text;
    obj->rect = rect;
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, pos);
    obj->pos = pos;
    return obj;
}
