/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** game
*/

#include "my.h"

void game(t_utils *val, sfRenderWindow *window)
{
    int pause = 0;
    t_obj *obj = create_player("sprite.png", val->player);
    t_obstacle *list = NULL, *tail = NULL;
    t_par *par = create_all_bg(window);
    par->music = create_music("music.ogg", 1);
    sfEvent event;
    t_text *test = create_text("Score is", 50);
    create_clock(par);
    generate_obstacle(&tail, val->map, &list, val);
    while (sfRenderWindow_isOpen(window) && par->game != 1 && pause == 0) {
        draw_everything(window, list, par, obj);
        utils(window, list, par, obj);
        move_player(obj, par->clock5);
        update_score(par, test, window);
        pause = gestion_event(obj, event, window, par);
        sfRenderWindow_display(window);
    }
    manage_val(val, pause, par, obj);
    manage_end(par, window, val, list);
    free(par);
    manage_pause(val, window, list, tail);
}

void start_menu(t_utils *val, sfRenderWindow *window)
{
    sfRenderWindow_setFramerateLimit(window, 60);
    t_par *par = create_all_bg(window);
    t_obj *test = create_title("title_menu.png");
    sfEvent event;
    sfVector2f test2 = {1920/2.0f, 1080/2.0f};
    sfVector2f test3 = {sfSprite_getLocalBounds(test->sprite).width / 2.0f,
    sfSprite_getLocalBounds(test->sprite).height / 2.0f};
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            manage_event_start(event, window, val);
        }
        draw_all_bg(window, par);
        sfSprite_setPosition(test->sprite, test2);
        sfSprite_setOrigin(test->sprite, test3);
        sfRenderWindow_drawSprite(window, test->sprite, NULL);
        sfRenderWindow_display(window);
    }
    return;
}

void won_menu(t_utils *info, sfRenderWindow *window, t_par *par2)
{
    t_par *par = create_all_bg(window);
    par->hs = get_highscore();
    t_obj *test = create_title("won_title.png");
    t_win_txt *all_txt = create_all_txt();
    sfEvent event;
    sfVector2f test2 = {1920/2.0f, 1080/2.0f};
    sfVector2f test3 = get_bounds_sprite(2.0f, 0.5f, test);
    score_text_end(par2->score, all_txt->txt_test);
    sfSprite_setPosition(test->sprite, test2);
    sfSprite_setOrigin(test->sprite, test3);
    while (sfRenderWindow_isOpen(window)) {
        manage_event_win(window, event, info);
        draw_all_bg(window, par);
        set_position(all_txt);
        draw_txt(window, all_txt, par);
        sfRenderWindow_drawSprite(window, test->sprite, NULL);
        sfRenderWindow_display(window);
    }
    return;
}
