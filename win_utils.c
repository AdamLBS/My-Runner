/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** win_utils
*/

#include "my.h"

void manage_event_win(sfRenderWindow *window, sfEvent event,
t_utils *val)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.key.code == (sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.key.code == (sfKeyR)) {
            val = get_par(val->ac, val->av);
            game(val, window);
        }
    }
}

t_win_txt *create_all_txt(void)
{
    t_win_txt *all_txt = malloc(sizeof(t_win_txt));
    t_text *txt_test = create_text("Your score is ", 40);
    t_text *hs_text = create_text("Your highscore is ", 40);
    t_text *replay_text = create_text("Press R to restart the game", 40);
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

void set_position(t_win_txt *infos)
{
    sfText_setPosition(infos->txt_test->text, infos->test2 );
    sfText_setOrigin(infos->txt_test->text, infos->test4);
    sfText_setPosition(infos->hs_text->text, infos->test2 );
    sfText_setOrigin(infos->hs_text->text, infos->test5);
    sfText_setPosition(infos->replay_text->text, infos->test2);
    sfText_setOrigin(infos->replay_text->text, infos->test6);
    sfText_setPosition(infos->exit_text->text, infos->test2);
    sfText_setOrigin(infos->exit_text->text, infos->test7);
}

void draw_txt(sfRenderWindow *window, t_win_txt *all_txt)
{
    sfRenderWindow_drawText(window, all_txt->txt_test->text, NULL);
    sfRenderWindow_drawText(window, all_txt->hs_text->text, NULL);
    sfRenderWindow_drawText(window, all_txt->replay_text->text, NULL);
    sfRenderWindow_drawText(window, all_txt->exit_text->text, NULL);
}
