/*
** EPITECH PROJECT, 2022
** test_parallax
** File description:
** obstacle
*/

#include "my.h"

void draw_all_obstacle(sfRenderWindow *window, t_obstacle *list, t_all_par *par)
{
    while (list != NULL) {
       sfRenderWindow_drawSprite(window, list->sprite, NULL);
       list = list->next;
    }
}

void move_all_obstacle(sfRenderWindow *window, t_obstacle *list, t_all_par *par)
{
    sfVector2f pos;
    t_obstacle *tmp = list;
    while (list != NULL) {
       pos = move_obstacle(list, 3, par->clock1);
       list->pos = pos;
       sfSprite_setPosition(list->sprite, pos);
       list = list->next;
    }
    if (list == NULL)
        list = tmp;
}

void append_obstacle(char *path, t_obstacle **list, int pos)
{
    t_obstacle *new_node = malloc(sizeof(t_obstacle));
    new_node = create_obstacle("tree.png", pos);
    new_node->next = NULL;
    if (*list == NULL)
        *list = new_node;
    else {
        t_obstacle *last = *list;
        while (last->next != NULL){
            last = last->next;
        }
        last->next = new_node;
    }
    
}

t_obstacle *create_obstacle(char *path, int x)
{
    t_obstacle *obj = malloc(sizeof(t_obstacle));
    obj->texture = sfTexture_createFromFile(path, NULL);
    sfVector2f pos = {x, 874};
    obj->rect.width = 190;
    obj->rect.height = 206;
    obj->rect.left = 0;
    obj->rect.top = 0;
    obj->sprite = sfSprite_create();
    obj->pos = pos;
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, pos);
    return obj;
}

sfVector2f move_obstacle(t_obstacle *bg, int speed, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        bg->pos.x = bg->pos.x - 10;
            return bg->pos;
    }
}

