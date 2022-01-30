/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_env.c
*/

#include "../include/my.h"

int my_env(my_env_t *m, int *ret)
{
    if (m->env == NULL) {
        *ret = 1;
        my_putstr_error("Env is empty.\n");
        return (0);
    }
    if (m->tab[1] != NULL) {
        *ret = 1;
        return (print_error(m->tab[0], ": Too many arguments.\n"));
    }
    else {
        for (int i = 0; m->env[i] != 0; i += 1)
            my_putstr(m->env[i]), my_putchar('\n');
    }
    return (0);
}
