/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** my
*/

#include "structure.h"
#ifndef MY_H_
#define MY_H_
struct game_object *create_object(const char *path, sfVector2f pos, sfIntRect rect);
sfSprite *create_sprite(t_object *obj);

#endif /* !MY_H_ */
