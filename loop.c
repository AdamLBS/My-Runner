/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** loop
*/

#include "my.h"

void manage_end(t_par *par, sfRenderWindow *window, t_utils *val,
t_obstacle *list)
{
    if (val->pause)
        return;
    if (par->win == 1) {
        write_score(par->score);
        destroy_obstacles(&list);
        won_menu(val, window, par);
    }
    if (par->loose == 1) {
        write_score(par->score);
        destroy_obstacles(&list);
        game_over(val, window, par);
    }
}

void manage_pause(t_utils *val, sfWindow *window, t_obstacle *list,
t_obstacle *tail)
{
    if (val->pause == 1) {
        pause_menu(val, window, list, tail);
    }
}

t_win_txt *pause_all_txt(t_par *par)
{
    par->hs = get_highscore();
    t_win_txt *all_txt = malloc(sizeof(t_win_txt));
    t_text *txt_test = create_text("Your score is ", 40);
    t_text *hs_text = create_text("Your highscore is ", 40);
    t_text *replay_text = create_text("Press R to resume the game", 40);
    t_text *exit_text = create_text("Press ESC to leave the game", 40);
    all_txt->txt_test = txt_test;
    all_txt->hs_text = hs_text;
    all_txt->replay_text = replay_text;
    all_txt->exit_text = exit_text;
    sfVector2f test2 = {1920/2.0f, 1080/2.0f};
    sfVector2f test4 = get_bounds_txt(2.0f, 0.8f, all_txt->txt_test);
    sfVector2f test5 = get_bounds_txt(2.0f, -2.9f, all_txt->hs_text);
    sfVector2f test6 = get_bounds_txt(2.0f, -0.4f, all_txt->replay_text);
    sfVector2f test7 = get_bounds_txt(2.0f, -0.2f, all_txt->replay_text);
    all_txt->test2 = test2;
    all_txt->test4 = test4;
    all_txt->test5 = test5;
    all_txt->test6 = test6;
    all_txt->test7 = test7;
    return all_txt;
}
