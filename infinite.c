/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** infinite
*/

#include "my.h"

char *generate_infinitemap(void)
{
    int size = 0;
    srand(time(NULL));
    char *map = malloc(sizeof(char) * 3004);
    for (int i = 0 ; size != 3000; size++) {
        int obstacle = rand() % 3;
        if (obstacle == 0)
            obstacle++;
        map[i] = obstacle + '0';
        i++;
    }
    map[size] = '3';
    size++;
    map[size] = '\0';
    my_putstr(map);
    return map;
}
