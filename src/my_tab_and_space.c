/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_tab_and_space.c
*/

#include "../include/my.h"

char *clean_line(char *line)
{
    char *tmp = my_strdup(line);
    tmp[my_strlen(tmp) - 1] = '\0';
    return (tmp);
}

char *tab_to_space(char *str)
{
    int i = 0, j = 0;
    char *cpy = malloc(sizeof(char) * my_strlen(str) + 1);
    for (; str[i] != '\0'; i += 1) {
        if (str[i] == '\t')
            cpy[i] = ' ';
        else
            cpy[i] = str[i];
    }
    cpy[i] = '\0';
    return (cpy);
}

char *rm_extra_spaces(char *str)
{
    int i = 0, j = 0;
    char *cpy = malloc(sizeof(char) * my_strlen(str) + 1);
    for (; str[i] == ' '; i += 1);
    for (; str[i] != '\0'; i += 1) {
        if (str[i] == ' ' && str[i - 1] == ' ')
            continue;
        cpy[j] = str[i];
        j += 1;
    }
    if (cpy[j - 1] == ' ')
        cpy[j - 1] = '\0';
    else
        cpy[j] = '\0';
    return (cpy);
}