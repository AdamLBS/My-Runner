/*
** EPITECH PROJECT, 2022
** test_parallax
** File description:
** obstacle
*/

#include "my.h"

void generate_obstacle(t_obstacle **tail, char *map, t_obstacle **list,
t_utils *val)
{
    int x = 1200;
    int tmp;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '1') {
            append_obstacle(tail, list, x, val->tree_s);
            x += 1000;
        }
        if (map[i] == '3') {
            append_portal("portal.png", list, x, val->portal);
        }
        if (map[i] == '2') {
            tmp = x + 200;
            append_obstacle(tail, list, x, val->tree_s);
            append_obstacle(tail, list, tmp, val->tree_s);
            x += 1000;
        }
    }
    val->done = 1;
    return;
}

void append_portal(char *path, t_obstacle **list, int pos, sfTexture *text)
{
    t_obstacle *new_node = malloc(sizeof(t_obstacle));
    new_node = create_portal("portal.png", pos, text);
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

int draw_all_obstacle(sfRenderWindow *window, t_obstacle *list, t_par *par)
{
    while (list != NULL) {
        sfVector2f pos = sfSprite_getPosition(list->sprite);
        if (pos.x >= -400 && pos.x <= 1920)
            sfRenderWindow_drawSprite(window, list->sprite, NULL);
        list = list->next;
    }
    return 1;
}

void move_all_obstacle(sfRenderWindow *window, t_obstacle *list, t_par *par)
{
    sfVector2f pos;
    t_obstacle *tmp = list;
    while (list != NULL) {
        move_obstacle(list, 3, par->clock1, par);
        list = list->next;
    }
    if (list == NULL)
        list = tmp;
    return;
}

void append_obstacle(t_obstacle **tail, t_obstacle **list, int pos,
sfTexture *text)
{
    t_obstacle *new_node = malloc(sizeof(t_obstacle));
    new_node = create_obstacle("tree.png", pos, text);
    new_node->type = 1;
    new_node->next = NULL;
    if (*list == NULL) {
        *list = new_node;
        *tail = new_node;
    } else {
        t_obstacle *last = *tail;
        last->next = new_node;
        *tail = last->next;
    }
    return;
}

void put_obstacle_end(t_obstacle **list)
{
    sfVector2f my_pos = sfSprite_getPosition((*list)->sprite);
    if (my_pos.x < -300) {
        sfSprite_destroy((*list)->sprite);
        *(list) = (*list)->next;
    }
}

void delete_obstacle(char *path, t_obstacle **list)
{
    sfVector2f my_pos = sfSprite_getPosition((*list)->sprite);
    if (my_pos.x < -300) {
        sfSprite_destroy((*list)->sprite);
        *(list) = (*list)->next;
    }
    return;
}

t_obstacle *create_obstacle(char *path, int x, sfTexture *text)
{
    t_obstacle *obj = malloc(sizeof(t_obstacle));
    obj->texture = text;
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

sfVector2f move_obstacle(t_obstacle *bg, int speed, sfClock *clock, t_par *par)
{
    sfTime time;
    float temp = 10 + par->speed;
    float multiply = 0.000001;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        bg->pos.x = bg->pos.x - temp;
        par->speed = par->speed + multiply;
        sfSprite_setPosition(bg->sprite, bg->pos);
    }
    return;
}
