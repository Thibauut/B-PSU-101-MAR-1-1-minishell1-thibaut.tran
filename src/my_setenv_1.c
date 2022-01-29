/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_setenv.c
*/

#include "../include/my.h"
#define error1 ": Variable name must begin with a letter.\n"
#define error2 ": Variable name must contain alphanumeric characters.\n"
#define error3 ": Too many arguments.\n"

int pos_env(my_env_t *m, char *str)
{
    int i = 0, j = 0;
    for (; m->env[i] != 0; i += 1) {
        if (my_strcmp2(m->env[i], str) == 0)
            return (i);
        else
            j = 0;
    }
    return (j);
}

int exist_setenv(my_env_t *m, char *str)
{
    m->str = malloc(sizeof(char) * 4096);
    if (m->tab[1] != NULL && m->tab[2] == NULL)
        m->str = my_strdup(str);
    else if (m->tab[1] != NULL && m->tab[2] != NULL) {
        m->str = my_strdup(str);
        m->str = my_strcat(m->str, m->tab[2]);
    }
    my_env_exist(m);
    return (0);
}

int no_exist_setenv(my_env_t *m, char *str)
{
    if (m->tab[1] != NULL && m->tab[2] == NULL)
        m->str = my_strdup(str);
    else if (m->tab[1] != NULL && m->tab[2] != NULL) {
        m->str = my_strdup(str);
        m->str = my_strcat(m->str, m->tab[2]);
    }
    my_new_env(m);
    return (0);
}

int if_setenv(my_env_t *m)
{
    char *str = malloc(sizeof(char) * 4096);
    str = my_strdup(m->tab[1]);
    str = my_strcat(str, "=");
    int j = pos_env(m, str);
    if (my_strcmp2(m->env[j], str) == 0)
        exist_setenv(m, str);
    else
        no_exist_setenv(m, str);
    return (0);
}

int my_setenv(my_env_t *m, int *ret)
{
    if (m->tab[1] == NULL && m->tab[2] == NULL)
        return (my_show_word_array(m->env));
    if ((m->tab[1][0] < 'A' || m->tab[1][0] > 'Z') && (m->tab[1][0] < 'a'
    || m->tab[1][0] > 'z')) {
        *ret = 1;
        return (print_error(m->tab[0], error1));
    }
    if (is_alpha(m->tab[1]) == 0) {
        *ret = 1;
        return (print_error(m->tab[0], error2));
    }
    if (m->tab[1] != NULL && m->tab[2] != NULL && m->tab[3]) {
        *ret = 1;
        return (print_error(m->tab[0], error3));
    }
    else
        if_setenv(m);
    return (0);
}