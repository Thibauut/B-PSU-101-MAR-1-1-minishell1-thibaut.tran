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

char **not_alpha(char **tab, int *l, int *j, int *k)
{
    if (*l == 0) {
        *j += 1;
        *k = 0;
        tab[*j] = malloc(sizeof(char) * 4096);
        *l += 1;
    }
    return (tab);
}

char **word_to_tab(char *str)
{
    int i = 0, j = 0, k = 0, l = 1;
    char **tab = malloc(sizeof(char *) * 4096);
    tab[0] = malloc(sizeof(char) * 4096);
    if (str[0] == '\n') {
        tab[0][0] = '\n';
        return (tab);
    }
    while (str[i] != '\0') {
        if (str[i] != ' ')
            tab[j][k] = str[i], k += 1,l = 0;
        else {
            tab = not_alpha(tab, &l, &j, &k);
        }
        i += 1;
    }
    check_spaces(tab);
    return (tab);
}

char *my_strcat(char *dest, char const *src)
{
    char a = 0;
    char i = 0;
    while (dest[a] != '\0')
        a = a + 1;
    while (src[i] != '\0') {
        dest[a + i] = src [i];
        i = i + 1;
    }
    dest[a + i] = '\0';
    return (dest);
}

int tab_len(char **tab)
{
    int i = 0;
    while (tab[i] != 0)
        i += 1;
    return (i);
}