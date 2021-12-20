/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** main
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio.h>
#include "structure.h"
#include "my.h"

struct game_object *create_object(const char *path, sfVector2f pos, sfIntRect rect)
{
    struct game_object *obj = malloc(sizeof(t_object));
    if (!sfTexture_createFromFile(path, NULL))
{
    exit(84);
} else
obj->texture = sfTexture_createFromFile(path, NULL);
    obj->pos = pos;
    obj->rect = rect;
    obj->sprite = create_sprite(obj);
    return (obj);
}

speed_t create_speed(float x, float y)
{
    //speed_t speed;

    //speed.x = x;
   // speed.y = y;
    return; //(speed);
}

sfSprite *create_sprite(t_object *obj)
{
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return (obj->sprite);
}