/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** game
*/

#include "my.h"

void game(int ac, char **av, sfRenderWindow *window)
{
    char *file = openfile(ac, av[1]);
    t_obstacle *list = NULL;
    t_par *par = create_all_bg(window);
    t_obj *obj = create_player("sprite.png");
    sfEvent event;
    t_text *test = create_text("Score i", 50);
    generate_obstacle(file, &list);
    while (sfRenderWindow_isOpen(window) && par->game != 1) {
        collision(list, obj, par);
        draw_all_bg(window, par);
        move_all_bg(window, par);
        move_player(obj, par->clock5);
        gestion_event(obj, event, window);
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
        write(1, "Win", 4);
        write_score(par->score);
        won_menu(window, par);
    }
    if (par->loose == 1)
        write(1, "Loose", 6);
}

void start_menu(int ac, char **av, sfRenderWindow *window)
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
                game(ac, av, window);
        }
        draw_all_bg(window, par);
        move_all_bg(window, par);
        sfSprite_setPosition(test->sprite, test2);
        sfSprite_setOrigin(test->sprite, test3);
        sfRenderWindow_drawSprite(window, test->sprite, NULL);
        sfRenderWindow_display(window);
    }
}

void won_menu(sfRenderWindow *window, t_par *par2)
{
    t_par *par = create_all_bg(window);
    par->hs = get_highscore();
    t_obj *test = create_title("won_title.png");
    t_text *txt_test = create_text("Your score is ", 40);
    t_text *hs_text = create_text("Your highscore is ", 40);
    sfEvent event;
    sfVector2f test2 = {1920/2.0f, 1080/2.0f};
    sfVector2f test3 = get_bounds_sprite(2.0f, 0.5f, test);
    sfVector2f test4 = get_bounds_txt(2.0f, 1.0f, txt_test);
    sfVector2f test5 = get_bounds_txt(2.0f, -2.5f, hs_text);
    score_text_end(par2->score, txt_test);
    hs_text_end(par->hs, hs_text);
        sfSprite_setPosition(test->sprite, test2);
        sfSprite_setOrigin(test->sprite, test3);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        draw_all_bg(window, par);
        sfText_setPosition(txt_test->text, test2 );
        sfText_setOrigin(txt_test->text, test4);
        sfText_setPosition(hs_text->text, test2 );
        sfText_setOrigin(hs_text->text, test5);
        sfRenderWindow_drawSprite(window, test->sprite, NULL);
        sfRenderWindow_drawText(window, txt_test->text, NULL);
        sfRenderWindow_drawText(window, hs_text->text, NULL);
        sfRenderWindow_display(window);
    }
}
