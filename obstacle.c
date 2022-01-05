/*
** EPITECH PROJECT, 2022
** test_parallax
** File description:
** obstacle
*/

#include "my.h"

void generate_obstacle(char *map, t_obstacle **list)
{
    int x = 1200;
    int tmp;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '1') {
            append_obstacle("tree.png", list, x);
            x += 1000;
        }
        if (map[i] == '2') {
            append_portal("portal.png", list, x);
        }
        if (map[i] == '3') {
            tmp = x + 200;
            append_obstacle("tree.png", list, x);
            append_obstacle("tree.png", list, tmp);
            x += 1000;
        }
    }
}

void append_portal(char *path, t_obstacle **list, int pos)
{
    t_obstacle *new_node = malloc(sizeof(t_obstacle));
    new_node = create_portal("portal.png", pos);
    new_node->type = 2;
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

void draw_all_obstacle(sfRenderWindow *window, t_obstacle *list, t_par *par)
{
    while (list != NULL) {
        sfRenderWindow_drawSprite(window, list->sprite, NULL);
        list = list->next;
    }
}

void move_all_obstacle(sfRenderWindow *window, t_obstacle *list, t_par *par)
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
    new_node->type = 1;
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
    sfVector2f pos = {x, 885};
    obj->rect.width = 180;
    obj->rect.height = 200;
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
