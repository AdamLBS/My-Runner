/*
** EPITECH PROJECT, 2021
** revstr
** File description:
** revstr
*/

int strlen2(char const *str)
{
    int run;
    run = 0;
    while (str[run] != '\0') {
        run = run +1;
    }
    return (run);
}

void my_swap2(char *j, char *i)
{
    char temporaire;
    temporaire = *j;
    *j = *i;
    *i = temporaire;
}

char *my_revstr(char *str)
{
    int i = strlen2(str);
    i = i - 1;
    int j = 0;
    while (j < i) {
        my_swap2(&str[j], &str[i]);
        i = i - 1;
        j = j + 1;
    }
    return (str);
}