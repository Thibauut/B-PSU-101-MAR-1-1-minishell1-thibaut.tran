/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_unsetenv.c
*/

#include "../include/my.h"

char **refresh_env(my_env_t *m, char *str)
{
    char **tmp = malloc(sizeof(char *) * (tab_len(m->env) + 20));
    for (int i = 0, j = 0; m->env[i] != 0; i += 1) {
        tmp[j] = malloc(sizeof(char) * (m_len(m->env[i]) + 1));
        tmp[j] = my_strcpy(tmp[j], m->env[i]);
        if (my_strcmp2(m->env[i], str) == 0)
            printf("abc");
        j += 1;
    }
    return (tmp);
}

int if_unsetenv(my_env_t *m)
{
    char *str = malloc(sizeof(char) * 4096);
    str = my_strdup(m->tab[1]);
    str = my_strcat(str, "=");
    int j = pos_env(m, str);
    if (my_strcmp2(m->env[j], str) == 0)
        m->env = refresh_env(m, str);
    return (0);
}

int my_unsetenv(my_env_t *m)
{
    if (m->tab[1] == NULL)
        print_error(m->tab[0], ": : Too few arguments.\n");
    else
        if_unsetenv(m);
    return (0);
}