/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** highscore
*/

#include "my.h"

char write_score(int score)
{
    char buffer[100];
    char buffer2[100];
    int fd = open("score.txt", O_RDONLY);
    read(fd, buffer, 100);
    int high_score = my_get_nbr(buffer);
    if (score > high_score){
    my_itoa(score, buffer2);
    int fd2 = open("score.txt", O_WRONLY | O_CREAT | O_TRUNC);
    write(fd2, buffer2, my_strlen(buffer2));
    return buffer2;
    }
}

int get_highscore(void)
{
    char buffer[100];
    char buffer2[100];
    int fd = open("score.txt", O_RDONLY);
    read(fd, buffer, 100);
    int high_score = my_get_nbr(buffer);
    return high_score;
}