/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** game_over
*/

#include "my.h"

void game_over(t_utils *info, sfRenderWindow *window, t_par *par2)
{
    t_par *par = create_all_bg(window);
    par->hs = get_highscore();
    t_obj *test = create_title("game_over.png");
    t_win_txt *all_txt = create_all_txt();
    sfEvent event;
    sfVector2f test2 = {1920/2.0f, 1080/2.0f};
    sfVector2f test3 = get_bounds_sprite(2.0f, 0.5f, test);
    score_text_end(par2->score, all_txt->txt_test);
    hs_text_end(par->hs, all_txt->hs_text);
    sfSprite_setPosition(test->sprite, test2);
    sfSprite_setOrigin(test->sprite, test3);
    while (sfRenderWindow_isOpen(window)) {
        manage_event_win(window, event, info);
        draw_all_bg(window, par);
        set_position(all_txt);
        draw_txt(window, all_txt);
        sfRenderWindow_drawSprite(window, test->sprite, NULL);
        sfRenderWindow_display(window);
    }
}
