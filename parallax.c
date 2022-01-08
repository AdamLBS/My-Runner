/*
** EPITECH PROJECT, 2022
** test_parallax
** File description:
** parallax
*/

#include "my.h"

struct parallax *create_bg (char *path)
{
    struct parallax *bg = malloc(sizeof(t_bg));
    bg->texture = sfTexture_createFromFile(path, NULL);
    sfTexture_setRepeated(bg->texture, sfTrue);
    sfVector2f scale = {1920.0, 1080.0};
    sfIntRect rect;
    rect.top = 0;
    rect.height = 272;
    rect.width = 592;
    rect.left = 0;
    bg->rect = rect;
    bg->sprite = create_sprite(bg);
    sfVector2f scale2 = {scale.x / sfSprite_getLocalBounds(bg->sprite).width,
    scale.y / sfSprite_getLocalBounds(bg->sprite).height};
    sfSprite_setScale(bg->sprite, scale2);
    bg->scale = scale2;
    bg->speed = 1;
    bg->clock = sfClock_create();
    return bg;
}

sfSprite *create_sprite(t_bg *obj)
{
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    return (obj->sprite);
}

void create_clock(t_par *par)
{
    par->clock2 = sfClock_create();
    par->clock3 = sfClock_create();
    par->clock4 = sfClock_create();
    par->clock5 = sfClock_create();
    par->clock6 = sfClock_create();
    par->clock7 = sfClock_create();
    par->clock1 = sfClock_create();
}

t_par *create_all_bg(sfRenderWindow *window)
{
    t_par *par = malloc(sizeof(t_par));
    t_bg *bg1 = create_bg("bg.png");
    t_bg *bg2 = create_bg("close.png");
    t_bg *bg3 = create_bg("far.png");
    t_bg *bg4 = create_bg("mid.png");
    par->bg1 = bg1;
    par->bg2 = bg2;
    par->bg3 = bg3;
    par->bg4 = bg4;
    par->score = 0;
    par->game = 0;
    par->music = create_music("music.ogg", 1);
    return par;
}

void draw_all_bg(sfRenderWindow *window, t_par *par)
{
    sfRenderWindow_drawSprite(window, par->bg1->sprite, NULL);
    sfRenderWindow_drawSprite(window, par->bg3->sprite, NULL);
    sfRenderWindow_drawSprite(window, par->bg4->sprite, NULL);
    sfRenderWindow_drawSprite(window, par->bg2->sprite, NULL);
}

void move_all_bg(sfRenderWindow *window, t_par *par)
{
    move_parallax(par->bg3, 1, par->clock3);
    move_parallax(par->bg4, 2, par->clock4);
    move_parallax(par->bg2, 3, par->clock2);
}

void move_all_bg_f(sfRenderWindow *window, t_par *par)
{
    move_parallax_f(par->bg3, 1, par->clock3);
    move_parallax_f(par->bg4, 2, par->clock4);
    move_parallax_f(par->bg2, 3, par->clock2);
}

void move_parallax(t_bg *bg, int speed, sfClock *clock)
{
    sfTime time;
    float seconds;
    float my_speed = bg->speed * speed;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        bg->rect.left += my_speed;
        bg->speed += 0.00001;
        sfSprite_setTextureRect(bg->sprite, bg->rect);
    sfClock_restart(clock);
    }
}

void move_parallax_f(t_bg *bg, int speed, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        bg->rect.left += speed;
        sfSprite_setTextureRect(bg->sprite, bg->rect);
    sfClock_restart(clock);
    }
}
