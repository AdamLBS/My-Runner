/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** structure
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio.h>

#ifndef STRUCTURE_H_
#define STRUCTURE_H_
struct speed
{
    float x;
    float y;
} typedef speed_t;
struct game_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    speed_t speed;
} typedef t_object;

#endif /* !STRUCTURE_H_ */
