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
#include "framebuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "my.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *frame;
    frame = malloc(sizeof(framebuffer_t) + 1);
    frame -> width = width;
    frame -> height = height;
    frame -> pixels = malloc(width * height  * 4);
    return frame;
}

void main(void)
{
    sfRenderWindow *window;
    framebuffer_t *framebuffer;
    sfVideoMode mode = {1920, 1080, 32};
    framebuffer = framebuffer_create(1920, 1080);
    window = sfRenderWindow_create(mode, "My Runner", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
        struct game_object *my_obj, *my_obj3, *my_obj2, *my_obj4, *my_obj5;

            sfVector2f vec = {0, 0};
            sfVector2f vec2 = {0,0};
            sfIntRect rect;
            sfIntRect rect2;
            sfIntRect rect3;

        my_obj = create_object("back/1.png", vec2, rect2);
        my_obj4 = create_object("back/4.png", vec2, rect2);
        my_obj5 = create_object("back/5.png", vec2, rect2);
        my_obj2 = create_object("back/2.png", vec2, rect2);
                my_obj3 = create_object("back/3.png", vec2, rect2);
    while (sfRenderWindow_isOpen(window)) {

        sfRenderWindow_drawSprite(window, my_obj->sprite, NULL);

        sfRenderWindow_drawSprite(window, my_obj2->sprite, NULL);
                sfRenderWindow_drawSprite(window, my_obj3->sprite, NULL);
                sfRenderWindow_drawSprite(window, my_obj4->sprite, NULL);
                sfRenderWindow_drawSprite(window, my_obj5->sprite, NULL);
                sfRenderWindow_display(window);
    }
}