/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_cd_env.c
*/

#include "../include/my.h"

int if_setenv_for_cd(my_env_t *m)
{
    char *str = malloc(sizeof(char) * 4096);
    str = my_strdup(m->tab_pwd[1]);
    str = my_strcat(str, "=");
    int j = pos_env(m, str);
    if (my_strcmp2(m->env[j], str) == 0)
        exist_setenv_for_cd(m, str);
    return (0);
}

int exist_setenv_for_cd(my_env_t *m, char *str)
{
    m->str2 = malloc(sizeof(char) * 4096);
    if (m->tab_pwd[1] != NULL && m->tab_pwd[2] != NULL) {
        m->str2 = my_strcpy(m->str2, str);
        m->str2 = my_strcat(m->str2, m->tab_pwd[2]);
    }
    my_env_exist_for_cd(m);
    return (0);
}

int my_env_exist_for_cd(my_env_t *m)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(m->str2)));
    for (int j = 0; m->str2[j] != '='; j += 1)
        tmp[j] = m->str2[j];
    tmp = my_strcat(tmp, "=");
    for (int i = 0; m->env[i] != 0; i += 1) {
        if (my_strcmp2(m->env[i], tmp) == 0)
            m->env[i] = my_strdup(m->str2);
    }
    return (0);
}

char *clean_get_home(char *home)
{
    char *tmp = malloc(sizeof(char) * my_strlen(home) + 1);
    int j = 0, i = 0, verif = 0;
    for (; home[i] != '\0'; i += 1) {
        if (home[i] == '/')
            verif = 1;
        if (verif == 1) {
            tmp[j] = home[i];
            j += 1;
        }
    }
    return (tmp);
}

int pwd_tab(my_env_t *m)
{
    m->tab_pwd = malloc(sizeof(char *) * 4);
    m->tab_pwd[0] = "setenv";
    m->tab_pwd[1] = "PWD";
    m->tab_pwd[2] = m->refresh_pwd;
    m->tab_pwd[3] = 0;
    return (0);
}
