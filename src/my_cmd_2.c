/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_cmd_2.c
*/

#include "../include/my.h"

int my_envp(char **tab, my_env_t *my_env, my_struct_t *verif)
{
    if (my_strcmp(tab[0], "env") == 0) {
        verif->i = 1;
        if (tab[0][4] != '\0')
            return (0);
        if (my_env->tmp_env == 0)
            my_show_word_array(my_env->env);
        else
            my_show_word_array(my_env->tmp_env);
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