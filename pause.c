/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** pause
*/

#include "my.h"

void manage_val(t_utils *val, int pause, t_par *par, t_obj *obj)
{
    val->pause = pause;
    val->score = par->score;
    destroy_sounds(par, obj);
}

void restart_pause(t_utils *val, sfWindow *window, t_obstacle *list,
t_obstacle *tail)
{
    t_obj *obj = create_player("sprite.png", val->player);
    t_par *par = create_all_bg(window);
    par->score = val->score;
    par->music = create_music("music.ogg", 1);
    sfEvent event;
    t_text *test = create_text("Score is", 50);
    create_clock(par);
    int pause = 0;
    while (sfRenderWindow_isOpen(window) && par->game != 1 && pause == 0) {
        draw_everything(window, list, par, obj);
        utils(window, list, par, obj);
        move_player(obj, par->clock5);
        update_score(par, test, window);
        pause =  gestion_event(obj, event, window, par);
        sfRenderWindow_display(window);
    }
    manage_val(val, pause, par, obj);
    manage_end(par, window, val, list);
    free(par);
    manage_pause(val, window, list, tail);
}

void pause_menu(t_utils *val, sfWindow *window, t_obstacle *list,
t_obstacle *tail)
{
    int pause = 0;
    t_par *par = create_all_bg(window);
    t_obj *test = create_title("pause.png");
    t_win_txt *all_txt = pause_all_txt(par);
    sfEvent event;
    sfVector2f test2 = {1920/2.0f, 1080/2.0f};
    sfVector2f test3 = get_bounds_sprite(2.0f, 0.5f, test);
    score_text_end(val->score, all_txt->txt_test);
    sfSprite_setPosition(test->sprite, test2);
    sfSprite_setOrigin(test->sprite, test3);
    while (sfRenderWindow_isOpen(window) && pause == 0) {
        draw_all_bg(window, par);
        set_position(all_txt);
        draw_txt(window, all_txt, par);
        pause = gestion_event_pause(event, window);
        sfRenderWindow_drawSprite(window, test->sprite, NULL);
        sfRenderWindow_display(window);
    }
    manage_end(par, window, val, list);
    free(par);
    restart_pause(val, window, list, tail);
}

int gestion_event_pause(sfEvent event, sfRenderWindow *window)
{
    sfWindow_setKeyRepeatEnabled(window, sfFalse);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.key.code == (sfKeyR))
            return 1;
        if (event.key.code == (sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
