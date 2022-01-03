/*
** EPITECH PROJECT, 2022
** test_parallax
** File description:
** obstacle
*/

#include "my.h"

t_obstacle *create_obstacle(char *path)
{
    t_obstacle *obj = malloc(sizeof(t_obstacle));
    obj->texture = sfTexture_createFromFile(path, NULL);
    sfVector2f pos = {1800, 874};
    obj->rect.width = 190;
    obj->rect.height = 206;
    obj->rect.left = 0;
    obj->rect.top = 0;
    obj->sprite = sfSprite_create();
    obj->pos = pos;
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, pos);
    return obj;
}

void move_obstacle(t_obstacle *bg, int speed, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        bg->pos.x = bg->pos.x - 10;
        if (bg->pos.x < -100)
            bg->pos.x = 1920;
        sfSprite_setPosition(bg->sprite, bg->pos);
    sfClock_restart(clock);
    }
}