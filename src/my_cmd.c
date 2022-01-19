/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_cmd.c
*/

#include "../include/my.h"

int my_exit(char **tab)
{
    if (my_strcmp(tab[0], "exit") == 0)
        exit(0);
}

int ls(char **tab, char **env, my_struct *verif)
{
    char *ls = "/bin/ls";
    if (my_strcmp(tab[0], "ls") == 0) {
        verif->i = 1;
        if (tab[1] != NULL && tab[2] == NULL) {
            tab[1][my_strlen(tab[1]) - 1] = '\0';
            my_exec(ls , tab, env);
        }
        else if (tab[1] != NULL && tab[2] != NULL) {
            tab[2][my_strlen(tab[2]) - 1] = '\0';
            my_exec(ls , tab, env);
        }
        else
            my_exec(ls, tab, env);
    }
    return (0);
}

int clear(char **tab, char **env, my_struct *verif)
{
    char *ls = "/bin/clear";
    if (my_strcmp(tab[0], "clear") == 0) {
        verif->i = 1;
        my_exec(ls, tab, env);
    }
    return (0);
}

int pwd(char **tab, my_struct *verif)
{
    char *pwd;
    if (my_strcmp(tab[0], "pwd") == 0) {
        verif->i = 1;
        size_t size = 4096;
        pwd = getcwd(pwd, 4086);
        my_putstr(pwd);
        my_putstr("\n");
    }
    return (0);
}

int cd(char **tab, my_struct *verif)
{
    if (my_strcmp(tab[0], "cd") == 0 && tab[1] != NULL) {
        tab[1][my_strlen(tab[1]) - 1] = '\0';
        verif->i = 1;
        int i = chdir(tab[1]);
        if (i != 0)
            write(2, "invalid file\n", 13);
    }
    return (0);
}

