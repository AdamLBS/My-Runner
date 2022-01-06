/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** sound
*/

#include "my.h"

t_sound *create_sound(char *path)
{
    t_sound *sound = malloc(sizeof(t_sound));
    sound->soundbuffer = sfSoundBuffer_createFromFile(path);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->soundbuffer);
    return sound;
}

t_music *create_music(char *path, int loop)
{
    t_music *music = malloc(sizeof(t_music));
    music->music = sfMusic_createFromFile(path);
    return music;
}
