/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_env.c
*/

#include "../include/my.h"

int my_env(my_env_t *m)
{
    if (m->env == NULL) {
        my_putstr_error("Env is empty.\n");
        return (0);
    }
    for (int i = 0; m->env[i] != 0; i += 1)
        my_putstr(m->env[i]), my_putchar('\n');
    return (0);
}