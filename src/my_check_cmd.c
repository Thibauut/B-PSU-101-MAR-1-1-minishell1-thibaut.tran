/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_check_cmd.c
*/

#include "../include/my.h"

int my_cmd(my_env_t *m, my_struct_t *verif)
{
    m_cmp(m->tab[0], "cd") == 0 ? cd(m) : 0;
    m_cmp(m->tab[0], "exit") == 0 ? my_exit(m) : 0;
    m_cmp(m->tab[0], "setenv") == 0 ? my_setenv(m) : 0;
    // m_cmp(m->tab[0], "unsetenv") == 0 ? my_unsetenv(m) : 0;
    // if (verif->i == 0 && m->tab[0][0] != '\n')
    //     write(2, "invalid command\n", 16);
    return (0);
}

int check_cmd(my_env_t *m, my_struct_t *verif)
{
    if (m_cmp(m->tab[0], "exit") == 0 || m_cmp(m->tab[0], "setenv") == 0
    || m_cmp(m->tab[0], "unsetenv") == 0 || m_cmp(m->tab[0], "cd") == 0)
        my_cmd(m, verif);
    else {
        if (path_cmd(m) == 0)
            print_error(m->tab[0], ": Command not found.\n");
    }
    return (0);
}