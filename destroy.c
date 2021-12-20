/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** destroy
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio.h>
#include "structure.h"
#include "my.h"

void destroy_object (struct game_object *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
}
