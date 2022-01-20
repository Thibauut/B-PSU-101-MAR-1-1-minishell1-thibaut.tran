/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_cmd_2.c
*/

#include "../include/my.h"

int my_env(char **tab, char **env, my_struct *verif)
{
    if (my_strcmp(tab[0], "env") == 0) {
        verif->i = 1;
        my_show_word_array(env);
    }
    return (0);
}

int my_exit(char **tab)
{
    if (my_strcmp(tab[0], "exit") == 0) {
        if (tab[0][5] != '\0')
            return (0);
        exit(0);
    }
}

int my_setenv(char **tab, char **env, my_struct *verif)
{
    if (my_strcmp(tab[0], "setenv") == 0) {
        if (tab[1] == NULL && tab[2] == NULL)
            return (0);
        if (tab[0][7] != '\0')
            return (0);
        verif->i = 1;
    }
}