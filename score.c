/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** score
*/
#include "my.h"

void update_score(t_par *par, t_text *txt, sfRenderWindow *window)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(par->clock6);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        par->score += 1;
        update_text(par, txt);
    }
    sfRenderWindow_drawText(window, txt->text, NULL);
}

void update_text(t_par *par, t_text *txt)
{
    char *nb = malloc(sizeof(char) * 100);
    my_itoa(par->score, nb);
    char test[100] = "Score is ";
    my_strcat(test, nb);
    sfText_setString(txt->text, test);
    free(nb);
}

void score_text_end(int score, t_text *txt)
{
    char *nb = malloc(sizeof(char) * 100);
    my_itoa(score, nb);
    char test[100] = "Your score is ";
    my_strcat(test, nb);
    sfText_setString(txt->text, test);
}

void hs_text_end(int score, t_text *txt)
{
    char *nb = malloc(sizeof(char) * 100);
    my_itoa(score, nb);
    char test[100] = "Your highscore is ";
    my_strcat(test, nb);
    sfText_setString(txt->text, test);
    free(nb);
}
