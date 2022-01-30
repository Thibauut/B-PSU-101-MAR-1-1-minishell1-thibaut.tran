/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_func_3.c
*/

#include "../include/my.h"

int is_alpha(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)
        || (str[i] >= 48 && str[i] <= 57))
            i += 1;
        else
            return (0);
    }
    return (1);
}

int create_tab(char *str, char c)
{
    int i = 0, j = 0;
    for (; str[i] != 0; i += 1) {
        if (str[i] == c)
            j += 1;
    }
    return (j + 1);
}

char **word_to_tab(char *str, char c, int i)
{
    int j = 0, k = 0, size = create_tab(str, c);
    char **tab = malloc(sizeof(char *) * (size + 1));
    tab[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    str = tab_to_space(str);
    str = rm_extra_spaces(str);
    while (str[i] != '\0') {
        if (str[i] == c) {
            i += 1;
            tab[j][k] = '\0';
            j += 1, k = 0;
            tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
        }
        tab[j][k] = str[i];
        i += 1, k += 1;
    }
    j += 1, tab[j] = 0;
    return (tab);
}

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int i = 0;
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
