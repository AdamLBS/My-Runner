/*
** EPITECH PROJECT, 2022
** test_parallax
** File description:
** jump
*/

#include "my.h"

void handle_hitbox(t_obj *obj) {
    if (obj->pos.y > 847) {
        obj->velocity.y = 0;
        obj->pos.y = 847;
    }
}

void update (t_obj *obj, double elapsed)
{
    obj->velocity.x = 0;
    obj->pos.x += obj->velocity.x * elapsed;
    obj->pos.y += obj->velocity.y * elapsed;
    obj->velocity.y += obj->weight * elapsed;
    obj->velocity.y = 13 + obj->velocity.y;
    handle_hitbox(obj);
    sfSprite_setPosition(obj->sprite, obj->pos);
}

void gestion_event(t_obj *obj, sfEvent event, sfRenderWindow *window)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.key.code == (sfKeySpace)){
            manage_space(obj);
        }
        if (event.type = sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void manage_space(t_obj *obj)
{
    if (obj->pos.y == 847)
        obj->velocity.y += -720;
}
