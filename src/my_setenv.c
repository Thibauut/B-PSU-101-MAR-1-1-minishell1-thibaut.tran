/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_setenv.c
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
        my_strcpy(tmp, tab[1]), tmp = my_strcat(tmp, "="), tmp = my_strcat(tmp, tab[2]);
        return (tmp);
    }
}

char **my_new_env(char **env, char *str)
{
    int i = 0;
    char **tmp_env = malloc(sizeof(char *) * (tab_len(env) + 1));
    while (env[i] != 0) {
        tmp_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        tmp_env[i] = my_strcpy(tmp_env[i], env[i]);
        i += 1;
    }
    str[my_strlen(str) - 1] = '\0';
    tmp_env[i] = malloc(sizeof(char) * my_strlen(str) + 1);
    tmp_env[i] = my_strcpy(tmp_env[i], str);
    tmp_env[i + 1] = 0;
    return (tmp_env);
}

int my_setenv(char **tab, my_env_t *my_env, my_struct_t *verif)
{
    if (my_strcmp(tab[0], "setenv") == 0) {
        if ((tab[1] == NULL && tab[2] == NULL) || (tab[0][7] != '\0') ||
        (tab[3] != NULL) || ((tab[1][0] < 'A' || tab[1][0] > 'Z')
        && (tab[1][0] < 'a' || tab[1][0] > 'z')))
            return (0);
        else {
            my_env->stock = my_strdup(tab[1]);
            verif->i = 1;
            if (tab[1] != NULL && tab[2] == NULL)
                my_env->str = charge_setenv(tab, 1);
            else if (tab[1] != NULL && tab[2] != NULL)
                my_env->str = charge_setenv(tab, 2);
            my_env->tmp_env = my_new_env(my_env->env, my_env->str);
        }
    }
    return (0);
}