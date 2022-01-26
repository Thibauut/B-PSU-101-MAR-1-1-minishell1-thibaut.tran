/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_cmd.c
*/

#include "../include/my.h"

int error_ls(char **tab)
{
    if (tab[0][2] != '\0') {
        write(2, "invalid command\n", 16);
        return (1);
    }
    return (0);
}

int ls(char **tab, char **env, my_struct_t *verif)
{
    char *ls = "/bin/ls";
    if (my_strcmp(tab[0], "ls") == 0) {
        if (tab[0][3] != '\0')
            return (0);
        verif->i = 1;
        if (tab[1] != NULL && tab[2] == NULL) {
            tab[1][my_strlen(tab[1]) - 1] = '\0';
            if (error_ls(tab) == 1) return (0);
            my_exec(ls, tab, env);
        }
        else if (tab[1] != NULL && tab[2] != NULL) {
            tab[2][my_strlen(tab[2]) - 1] = '\0';
            if (error_ls(tab) == 1) return (0);
            my_exec(ls, tab, env);
        }
        else
            my_exec(ls, tab, env);
    }
    return (0);
}

char *cd_get_home(char **env)
{
    char *home;
    int i = 0;
    while (env[i] != 0) {
        if (my_strcmp(env[i], "HOME") == 0) {
            home = my_strdup(env[i]);
            home = clean_get_home(home);
        }
        i += 1;
    }
    return (home);
}

char *clean_get_home(char *home)
{
    char *tmp = malloc(sizeof(char) * my_strlen(home) + 1);
    int j = 0;
    int i = 0;
    int verif = 0;
    while (home[i] != '\0') {
        if (home[i] == '/')
            verif = 1;
        if (verif == 1) {
            tmp[j] = home[i];
            j += 1;
        }
        i += 1;
    }
    return (tmp);
}

int cd(char **tab, my_struct_t *verif, char **env)
{
    char *home = cd_get_home(env);
    int j = 0, i = 0;
    if (my_strcmp(tab[0], "cd") == 0) {
        if (tab[0][3] != '\0') return (0);
        if (tab[0] != NULL && tab[1] == NULL) {
            verif->i = 1;
            j = chdir(home);
            if (i != 0) write(2, "invalid file\n", 13);
        }
        else if (tab[1] != NULL && tab[2] == NULL) {
            if (tab[0][2] != '\0')
                return (0);
            verif->i = 1;
            tab[1][my_strlen(tab[1]) - 1] = '\0';
            i = chdir(tab[1]);
            if (i != 0) write(2, "invalid file\n", 13);
        }
    }
    return (0);
}

