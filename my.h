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
#include <unistd.h>
#ifndef MY_H_
    #define MY_H_

struct utils {
    char *path;
} typedef t_utils;

struct sound {
    sfSound *sound;
    sfSoundBuffer *soundbuffer;
} typedef t_sound;

struct music {
    sfMusic *music;
} typedef t_music;

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
    sfClock *clock6;
    sfClock *clock7;
    int game;
    int win;
    int loose;
    int score;
    int hs;
    t_music *music;
}typedef t_par;

struct object {
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    float weight;
    sfVector2f pos;
    sfVector2f velocity;
    t_sound *jump_sound;
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

struct win_txt {
    t_text *txt_test;
    t_text *hs_text;
    t_text *replay_text;
    t_text *exit_text;
    sfVector2f test2;
    sfVector2f test3;
    sfVector2f test4;
    sfVector2f test5;
    sfVector2f test6;
    sfVector2f test7;
} typedef t_win_txt;

struct parallax *create_bg (char *path);
sfSprite *create_sprite(t_bg *obj);
t_par *create_all_bg(sfWindow *window);
t_obj *create_player(char *path);
t_obstacle *create_obstacle(char *path, int x);
void append_obstacle(char *path, t_obstacle **list, int pos);
void draw_all_obstacle(sfRenderWindow *window, t_obstacle *list, t_par *par);
sfVector2f move_obstacle(t_obstacle *bg, int speed, sfClock *clock);
void collision(t_obstacle *list, t_obj *player, t_par *par);
char *openfile(char *filepath);
void generate_obstacle(char *map, t_obstacle **list);
t_obstacle *create_portal(char *path, int x);
void append_portal(char *path, t_obstacle **list, int pos);
void end(t_obstacle *list, t_obj *player, t_par *par);
t_text *create_text(char *text, int size);
int get_intlen(int val);
char *my_itoa(int val, char *buffer);
t_obj *create_title(char *path);
void won_menu(t_utils *info, sfRenderWindow *window, t_par *par2);
void get_score(int nb, t_text *txt);
char *my_strcat (char *dest, char const *src);
sfVector2f get_bounds_sprite(float x, float y, t_obj *obj);
sfVector2f get_bounds_txt(float x, float y, t_text *txt);
int get_highscore(void);
char write_score(int score);
int my_get_nbr(char *str);
t_sound *create_sound(char *path);
t_music *create_music(char *path, int loop);
t_win_txt *create_all_txt(void);
void game(t_utils *val, sfRenderWindow *window);
void start_menu(t_utils *val, sfRenderWindow *window);
t_utils *get_par(int ac, char **av);
#endif /* !MY_H_ */
