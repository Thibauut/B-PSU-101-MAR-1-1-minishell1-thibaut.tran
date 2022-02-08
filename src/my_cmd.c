/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_cmd.c
*/

#include "../include/my.h"

char *my_get_line(char **env, char *arg)
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

char *cd_checker(my_env_t *m, int *ret)
{
    char *str = NULL;
    if (m->tab[0] != NULL && m->tab[1] == NULL)
        str = my_get_line(m->env, "HOME=");
    else if (m->tab[0] != NULL && m->tab[1][0] == '-') {
        if (m->old_pwd == NULL)
            return (my_itoa(1));
        else
            str = my_strdup(m->old_pwd);
    }
    else
        str = my_strdup(m->tab[1]);
    return (str);
}

int exec_cd(char *str, int *ret, my_env_t *m)
{
    if (access(str, F_OK) == 0) {
        m->old_pwd = my_get_line(m->env, "PWD=");
        chdir(str);
        m->refresh_pwd = getcwd(m->refresh_pwd, 4096);
    }
    else {
        *ret = 1;
        print_error(m->tab[0], ": No such file or directory.\n");
        return (1);
    }
    return (0);
}

int cd(my_env_t *m, int *ret)
{
    char *str;
    if (m->tab[2] != NULL) {
        *ret = 1;
        return (print_error(m->tab[0], ": Too many arguments.\n"));
    }
    str = cd_checker(m, ret); DIR *is_dir = opendir(str);
    if (my_strcmp(str, my_itoa(1)) == 0) {
        *ret = 1;
        return (print_error("", ": No such file or directory.\n"));
    }
    if (is_dir == NULL && access(str, F_OK) == 0) {
        *ret = 1;
        return (print_error(str, ": Not a directory.\n"));
    }
    if (exec_cd(str, ret, m) == 1)
        return (0);
    pwd_tab(m), if_setenv_for_cd(m);
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
        exit (EXIT_SUCCESS);
    }
    return (0);
}
