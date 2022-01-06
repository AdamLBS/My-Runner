/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** game
*/

#include "my.h"

void game(t_utils *val, sfRenderWindow *window)
{
    char *file = openfile(val->path);
    t_obj *obj = create_player("sprite.png");
    t_obstacle *list = NULL;
    t_par *par = create_all_bg(window);
    par->music = create_music("music.ogg", 1);
    sfMusic_play(par->music->music);
    sfEvent event;
    t_text *test = create_text("Score i", 50);
    generate_obstacle(file, &list);
    while (sfRenderWindow_isOpen(window) && par->game != 1) {
        collision(list, obj, par);
        draw_all_bg(window, par);
        move_all_bg(window, par);
        move_player(obj, par->clock5);
        gestion_event(obj, event, window, par);
        update(obj, sfClock_restart(par->clock7).microseconds/ 1000000.f);
        sfRenderWindow_drawSprite(window, obj->sprite, NULL);
        draw_all_obstacle(window, list, par);
        move_all_obstacle(window, list, par);
        end(list, obj, par);
        update_score(par, test);
        sfRenderWindow_drawText(window, test->text, NULL);
        sfRenderWindow_display(window);
    }
    if (par->win == 1) {
        destroy_sounds(par, obj);
        destroy_obstacles(list);
        won_menu(val, window, par);
    }
    if (par->loose == 1) {
        destroy_sounds(par, obj);
        destroy_obstacles(list);
        game_over(val, window, par);
    }
}

void start_menu(t_utils *val, sfRenderWindow *window)
{
    t_par *par = create_all_bg(window);
    t_obj *test = create_title("title_menu.png");
    sfEvent event;
    sfVector2f test2 = {1920/2.0f, 1080/2.0f};
    sfVector2f test3 = {sfSprite_getLocalBounds(test->sprite).width / 2.0f,
    sfSprite_getLocalBounds(test->sprite).height / 2.0f};
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.key.code == (sfKeyS))
                game(val, window);
        }
        draw_all_bg(window, par);
        move_all_bg(window, par);
        sfSprite_setPosition(test->sprite, test2);
        sfSprite_setOrigin(test->sprite, test3);
        sfRenderWindow_drawSprite(window, test->sprite, NULL);
        sfRenderWindow_display(window);
    }
}

void won_menu(t_utils *info, sfRenderWindow *window, t_par *par2)
{
    write_score(par2->score);
    t_par *par = create_all_bg(window);
    par->hs = get_highscore();
    t_obj *test = create_title("won_title.png");
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
