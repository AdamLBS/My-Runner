/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** score
*/

#include "my.h"

void update_score(t_par *par, t_text *txt)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(par->clock6);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        par->score += 1;
        update_text(par, txt);
    sfClock_restart(par->clock6);
    }
}

void update_text(t_par *par, t_text *txt)
{
    char *nb = malloc(sizeof(char) * 1000000);
    my_itoa(par->score, nb);
    char test[100000] = "Score is ";
    my_strcat(test, nb);
    sfText_setString(txt->text, test);
}