/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** main
*/

#include "framebuffer.h"
#include "my.h"
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *frame;
    frame = malloc(sizeof(framebuffer_t) + 1);
    frame -> width = width;
    frame -> height = height;
    frame -> pixels = malloc(width * height  * 4);
    return frame;
}

void create_window(framebuffer_t *framebuffer, sfRenderWindow *window)
{
    sfVideoMode mode = {1920, 1080, 32};
    framebuffer = framebuffer_create(1920, 1080);
    window = sfRenderWindow_create(mode, "Test", sfResize | sfClose, NULL);
    sfWindow_setFramerateLimit(window, 60);

}


int main(void)
{
    sfClock *clock = sfClock_create();
    framebuffer_t *framebuffer;
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    framebuffer = framebuffer_create(1920, 1080);
    window = sfRenderWindow_create(mode, "My Runner", sfResize | sfClose, NULL);
    sfWindow_setFramerateLimit(window, 60);
    t_all_par *par = create_all_bg(window);
    t_obj *obj = create_player("sprite.png");
    t_obstacle *obj2 = create_obstacle("tree.png");
    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {

        draw_all_bg(window, par);
       sfRenderWindow_drawSprite(window, obj->sprite, NULL);
       move_player(obj, par->clock5);
       gestion_event(obj, event, window);
       update(obj, sfClock_restart(clock).microseconds/ 1000000.f);
       sfRenderWindow_drawSprite(window, obj2->sprite, NULL);
       move_obstacle(obj2, 3, par->clock1);
        sfRenderWindow_display(window);
    }
    
}