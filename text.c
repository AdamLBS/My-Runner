/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myrunner-adam.elaoumari
** File description:
** text
*/

#include "my.h"

t_text *create_text(char *text, int size)
{
    t_text *txt = malloc(sizeof(t_text));
    txt->text = sfText_create();
    txt->font = sfFont_createFromFile("font.ttf");
    sfText_setFont(txt->text, txt->font);
    sfText_setCharacterSize(txt->text, size);
 
    sfText_setString(txt->text, text);
    return txt;
}