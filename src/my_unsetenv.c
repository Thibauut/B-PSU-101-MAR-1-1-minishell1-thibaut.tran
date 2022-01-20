/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_unsetenv.c
*/

#include "../include/my.h"

int error_unsetenv(char *tab)
{
    if (tab[my_strlen(tab) - 1] == '\0') {
        write(2, "invalid name\n", 13);
        return (1);
    }
    return (0);
}

int unsetenv_cond(char **tab, my_env_t *my_env)
{
    if (error_unsetenv(my_env->stock) == 1 && tab[2] != NULL)
        return (0);
    if ((my_strcmp(tab[1], my_env->stock) == 0) && tab[2] == NULL) {
        if (tab[0][my_strlen(tab[0]) + 1] != '\0')
            return (0);
        my_env->tmp_env = 0;
    }
    else {
        write(2, "invalid name\n", 13);
        return (0);
    }
    return (0);
}

int my_unsetenv(char **tab, my_env_t *my_env, my_struct_t *verif)
{
    if (my_strcmp(tab[0], "unsetenv") == 0) {
        if ((tab[1] == NULL && tab[2] == NULL) || (tab[0][9] != '\0') ||
        (tab[3] != NULL) || ((tab[1][0] < 'A' || tab[1][0] > 'Z')
        && (tab[1][0] < 'a' || tab[1][0] > 'z')) || my_env->stock == NULL)
            return (0);
        verif->i = 1;
        if (unsetenv_cond(tab, my_env) == 0)
            return (0);
    }
    return (0);
}