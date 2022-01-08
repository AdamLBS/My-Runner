/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** map
*/

#include "my.h"

char *openfile(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int bytes = 5000;
    char *file = malloc(sizeof(char) * bytes + 1);
    read(fd, file, bytes);
    close(fd);
    int i = 0;
    return (file);
}
