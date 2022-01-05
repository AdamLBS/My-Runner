/*
** EPITECH PROJECT, 2022
** test_parallax
** File description:
** create_object
*/
#include "my.h"

t_obj *create_title(char *path)
{
    t_obj *obj = malloc(sizeof(t_obj));
    obj->texture = sfTexture_createFromFile(path, NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    return obj;
}

t_obj *create_player(char *path)
{
    sfIntRect rect;
    sfVector2f pos = {0, 847};
    rect.width = 210;
    rect.height = 233;
    rect.left = 0;
    rect.top = 0;
    t_obj *obj = malloc(sizeof(t_obj));
    obj->texture = sfTexture_createFromFile(path, NULL);
    obj->rect = rect;
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, pos);
    obj->clock = sfClock_create();
    obj->pos = pos;
    obj->weight = 200;
    return obj;
}

void move_player(t_obj *obj, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.11) {
        move_helper(obj);
    sfClock_restart(clock);
    }
    sfSprite_setTextureRect(obj->sprite, obj->rect);

}

void move_helper(t_obj *obj)
{
    if (obj->pos.y == 847)
    obj->rect.left += 233;
    else
        obj->rect.left = 0;
    if (obj->rect.left >= 1398)
        obj->rect.left = 0;
}
