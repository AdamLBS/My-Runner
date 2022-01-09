/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** events
*/

#include "my.h"

void manage_event_start(sfEvent event, sfRenderWindow *window, t_utils *val)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.key.code == (sfKeyS)) {
        sfRenderWindow_clear(window, sfBlack);
        game(val, window);
    }
}