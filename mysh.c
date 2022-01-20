/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** minishell1.c
*/

#include "include/my.h"

void my_exec(char *ls, char **tab, char **env)
{
    int pid = fork();
    int status;
    if (pid == 0)
        execve(ls, tab, env);
    else
        waitpid(pid, &status, 0);
}

int my_cmd(char **tab, my_env_t *my_env, char **av, my_struct_t *verif)
{
    verif->i = 0;
    verif->verif_env = 0;
    ls(tab, my_env->env, verif);
    pwd(tab, verif);
    cd(tab, verif);
    clear(tab, my_env->env, verif);
    my_exit(tab);
    my_setenv(tab, my_env, verif);
    my_unsetenv(tab, my_env, verif);
    my_envp(tab, my_env, verif);
    if (verif->i == 0 && tab[0][0] != '\n')
        write(2, "invalid command\n", 16);
    return (0);
}

int my_prompt(char **av, my_env_t *my_env)
{
    char *line = NULL;
    char **tab;
    int *d = 0;
    size_t size = 2000; my_struct_t *verif = malloc(sizeof(my_struct_t));
    write(0, ">$ ", 3);
    while (getline(&line, &size, stdin) > 0) {
        tab = word_to_tab(line);
        my_cmd(tab, my_env, av, verif);
        write(0, ">$ ", 3);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    my_env_t *my_env = malloc(sizeof(my_env_t));
    my_env->env = env;
    if (ac > 1)
        return (84);
    my_prompt(av, my_env);
    return (0);
}