/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_cmd.c
*/

#include "../include/my.h"

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

char *cd_get(char **env, char *arg)
{
    char *home;
    int i = 0;
    for (; env[i] != 0; i += 1) {
        if (my_strcmp2(env[i], arg) == 0) {
            home = my_strdup(env[i]);
            home = clean_get_home(home);
        }
    }
    return (home);
}

int cd(my_env_t *m)
{
    char *str;
    if (m->tab[0] != NULL && m->tab[1] == NULL)
        str = cd_get(m->env, "HOME=");
    else if (m->tab[0] != NULL && m->tab[1][0] == '-')
        str = cd_get(m->env, "OLDPWD=");
    else
        str = my_strdup(m->tab[1]);
    if (access(str, F_OK) == 0)
        chdir(str);
    else
        perror("access ");
    return (0);
}

int my_exit(my_env_t *m)
{
    if (m->tab[1] != NULL) {
        write(2, "exit\n", 5);
        exit(my_getnbr(m->tab[1]));
    }
    else {
        write(2, "exit\n", 5);
        exit (0);
    }
    return (0);
}

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
