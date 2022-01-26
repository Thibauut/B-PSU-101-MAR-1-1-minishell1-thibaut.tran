/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_setenv.c
*/

#include "../include/my.h"

int pos_env(my_env_t *my_env, char **tab)
{
    int i = 0, j = 0, k = 1;
    char *tmp = my_strdup(tab[1]);
    if (tab[2] != NULL)
        k = 0;
    tmp[my_strlen(tmp) - k] = '\0';
    char *str = malloc(sizeof(char) * 4096);
    str = my_strcpy(str, tmp), str = my_strcat(str, "=");
    for (; my_env->env[i] != 0; i += 1) {
        if (my_strcmp(my_env->env[i], str) == 0)
            return (i);
        else
            j = 0;
    }
    return (j);
}

char **exist_setenv(char **tab, my_env_t *my_env, char *str)
{
    if (tab[1] != NULL && tab[2] == NULL)
        my_env->str = my_strdup(str);
    else if (tab[1] != NULL && tab[2] != NULL) {
        my_env->str = my_strdup(str);
        my_env->str = my_strcat(my_env->str, tab[2]);
        my_env->str[my_strlen(my_env->str) - 1] = '\0';
    }
    my_env->tmp_env = my_new_env2(my_env->tmp_env, my_env->str);
    return (my_env->tmp_env);
}

char **no_exist_setenv(char **tab, my_env_t *my_env, char **env)
{
    if (tab[1] != NULL && tab[2] == NULL)
        my_env->str = charge_setenv(tab, 1);
    else if (tab[1] != NULL && tab[2] != NULL)
        my_env->str = charge_setenv(tab, 2);
    my_env->tmp_env = my_new_env(my_env->tmp_env, my_env->str, my_env->tmp_env);
    return (my_env->tmp_env);
}

char **set_setenv(char **tab, my_env_t *my_env, char **env)
{
    my_env->verif = 0;
    int i = 0, j = pos_env(my_env, tab), k = 1;
    if (tab[2] != NULL)
        k = 0;
    char *str = malloc(sizeof(char) * 4096);
    str = my_strdup(tab[1]), str[my_strlen(str) - k] = '\0';
    str = my_strcat(str, "=");
    if (my_strcmp(my_env->env[j], str) == 0)
        my_env->tmp_env = exist_setenv(tab, my_env, str);
    else
        my_env->tmp_env = no_exist_setenv(tab, my_env, env);
    return (my_env->tmp_env);
}

char **my_setenv(char **tab, my_env_t *my_env, my_struct_t *verif, char **env)
{
    int i = 0;
    if (my_strcmp(tab[0], "setenv") == 0) {
        if ((tab[1] == NULL && tab[2] == NULL) || (tab[0][7] != '\0') ||
        (tab[3] != NULL) || ((tab[1][0] < 'A' || tab[1][0] > 'Z')
        && (tab[1][0] < 'a' || tab[1][0] > 'z')))
            return (0);
        else {
            my_env->stock = my_strdup(tab[1]);
            verif->i = 1;
            my_env->tmp_env = set_setenv(tab, my_env, my_env->tmp_env);
        }
    }
    return (my_env->tmp_env);
}