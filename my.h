/*
** EPITECH PROJECT, 2022
** test_parallax
** File description:
** my
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdlib.h"
#ifndef MY_H_
    #define MY_H_

struct parallax {
    sfClock *clock;
    sfTime *time;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f scale;
} typedef t_bg;

struct all_parallax {
    t_bg *bg1;
    t_bg *bg2;
    t_bg *bg3;
    t_bg *bg4;
    sfClock *clock1;
    sfClock *clock2;
    sfClock *clock3;
    sfClock *clock4;
    sfClock *clock5;
}typedef t_all_par;

struct object {
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    float weight;
    sfVector2f pos;
    sfVector2f velocity;
} typedef t_obj;

struct obstacle {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    struct obstacle *next;
    int type;
} typedef t_obstacle;

struct text {
    sfFont *font;
    sfText *text;
} typedef t_text;

struct parallax *create_bg (char *path);
sfSprite *create_sprite(t_bg *obj);
t_all_par *create_all_bg(sfWindow *window);
t_obj *create_player(char *path);
t_obstacle *create_obstacle(char *path, int x);
void append_obstacle(char *path, t_obstacle **list, int pos);
void draw_all_obstacle(sfRenderWindow *window, t_obstacle *list, t_all_par *par);
sfVector2f move_obstacle(t_obstacle *bg, int speed, sfClock *clock);
void collision(t_obstacle *list, t_obj *player);
char *openfile(char *filepath);
void generate_obstacle(char *map, t_obstacle **list);
t_obstacle *create_portal(char *path, int x);
void append_portal(char *path, t_obstacle **list, int pos);
void end(t_obstacle *list, t_obj *player, sfRenderWindow *window);
t_text *create_text(char *text, int size);
#endif /* !MY_H_ */
