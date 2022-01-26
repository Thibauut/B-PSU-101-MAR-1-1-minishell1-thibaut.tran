/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_cmd_2.c
*/

#include "../include/my.h"

int clear(char **tab, char **env, my_struct_t *verif)
{
    char *ls = "/bin/clear";
    if (my_strcmp(tab[0], "clear") == 0) {
        if (tab[0][6] != '\0')
            return (0);
        verif->i = 1;
        my_exec(ls, tab, env);
    }
    return (0);
}

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
        if (tab[1] != NULL)
            exit(my_getnbr(tab[1]));
        else
            exit (0);
    }
    return (0);
}

int pwd(char **tab, my_struct_t *verif)
{
    char *pwd = malloc(sizeof(char) * 4096);
    if (my_strcmp(tab[0], "pwd") == 0) {
        if (tab[0][4] != '\0')
            return (0);
        verif->i = 1;
        getcwd(pwd, 4096);
        my_putstr(pwd);
        my_putstr("\n");
    }
    return (0);
}

// int exec(char **tab, char **env, my_struct_t *verif)
// {
//     char *i = my_strdup(tab[0]);
//     if (tab[0][0] == '.' && tab[0][1] == '/') {
//         printf("tab[0] = %s", i);
//         verif->i = 1;
//         my_exec(i, tab, env);
//     }
//     return (0);
// }
