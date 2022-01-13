/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_func_3.c
*/

#include "../include/my.h"

char **check_spaces(char **tab)
{
    int i = 0, j = 0;
    while (tab[i] != NULL) {
        if (tab[i][0] != 0 && tab[i][0] <= ' ')
            tab[i][0] = '\0';
        i += 1;
    }
    return (tab);
}

char **word_to_tab(char *str)
{
    int i = 0, j = 0, k = 0, l = 1;
    char **tab = malloc(sizeof(char *) * 10000);
    tab[0] = malloc(sizeof(char) * 10000);
    while (str[i] != '\0') {
        if (str[i] != ' ')
            tab[j][k] = str[i], k += 1,l = 0;
        else {
            if (l == 0)
                j += 1, k = 0, tab[j] = malloc(sizeof(char) * 10000); l += 1;
        }
        i += 1;
    }
    check_spaces(tab);
    return (tab);
}