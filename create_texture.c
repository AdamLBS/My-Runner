/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** create_texture
*/

#include "my.h"

void create_textures(t_utils *par)
{
    par->player = sfTexture_createFromFile("sprite.png", NULL);
    par->portal = sfTexture_createFromFile("portal.png", NULL);
    par->tree_s = sfTexture_createFromFile("tree.png", NULL);
}
