/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** main
*/
#include "my.h"

int test(t_obstacle *list)
{
    int i = 4;
    int pos = 3000;
    while (i != 0) {
        pos += 1000;
        i--;
    }
}

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    window = sfRenderWindow_create(mode, "My Runner", sfResize|sfClose, NULL);
    sfWindow_setFramerateLimit(window, 60);
    return window;
}

int main(int ac, char **av)
{
    char *file = openfile(ac, av[1]);
    t_obstacle *list = NULL;
    sfClock *clock = sfClock_create();
    sfRenderWindow *window = create_window();
    t_par *par = create_all_bg(window);
    t_obj *obj = create_player("sprite.png");
    sfEvent event;
    t_text *test = create_text("Score is 0", 50);
    generate_obstacle(file, &list);
    while (sfRenderWindow_isOpen(window)) {
        collision(list, obj);
        draw_all_bg(window, par);
        move_player(obj, par->clock5);
        gestion_event(obj, event, window);
        update(obj, sfClock_restart(clock).microseconds/ 1000000.f);
        sfRenderWindow_drawSprite(window, obj->sprite, NULL);
        draw_all_obstacle(window, list, par);
        move_all_obstacle(window, list, par);
        end(list, obj, window);
        update_score(par, test);
        sfRenderWindow_drawText(window, test->text, NULL);
        sfRenderWindow_display(window);
    }
}
