/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_setenv_2.c
*/

#include "../include/my.h"

char *charge_setenv(char **tab, int arg)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(tab[1]) + 20));
    if (arg == 1) {
        tab[1][my_strlen(tab[1]) - 1] = '\0';
        tmp = my_strcpy(tmp, tab[1]), tmp = my_strcat(tmp, "=\n");
        return (tmp);
    }
    if (arg == 2) {
        tab[1][my_strlen(tab[1])] = '\0';
        my_strcpy(tmp, tab[1]), tmp = my_strcat(tmp, "=");
        tmp = my_strcat(tmp, tab[2]);
        return (tmp);
    }
    return (0);
}

char **my_new_env(char **env, char *str, char **env2)
{
    int i = 0, j = 25;
    char **tmp_env = malloc(sizeof(char *) * (tab_len(env) + 10));
    while (env[i] != 0) {
        tmp_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        tmp_env[i] = my_strcpy(tmp_env[i], env[i]);
        i += 1;
    }
    str[my_strlen(str) - 1] = '\0';
    tmp_env[j] = malloc(sizeof(char) * my_strlen(str) + 1);
    tmp_env[j] = my_strcpy(tmp_env[j], str);
    tmp_env[j + 1] = 0;
    return (tmp_env);
}

char **my_new_env2(char **env, char *str)
{
    int i = 0;
    char **tmp_env = malloc(sizeof(char *) * (tab_len(env) + 1));
    char *tmp = my_strdup(str), *stock = strtok(tmp, "=");
    while (env[i] != 0) {
        tmp_env[i] = my_strdup(env[i]);
        if (my_strcmp(env[i], tmp) == 0)
            tmp_env[i] = my_strdup(str);
        i += 1;
    }
    return (tmp_env);
}