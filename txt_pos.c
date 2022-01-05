/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** txt_pos
*/

#include "my.h"

sfVector2f get_bounds_txt(float x, float y, t_text *txt)
{
    sfVector2f test4 = {sfText_getLocalBounds(txt->text).width / x,
    sfText_getLocalBounds(txt->text).height / y};
    return test4;
}

sfVector2f get_bounds_sprite(float x, float y, t_obj *obj)
{
    sfVector2f test4 = {sfSprite_getLocalBounds(obj->sprite).width / x,
    sfSprite_getLocalBounds(obj->sprite).height / y};
    return test4;
}
