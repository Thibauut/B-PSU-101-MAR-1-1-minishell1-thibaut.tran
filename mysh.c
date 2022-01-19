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

int my_cmd(char **tab, char **env, char **av, my_struct *verif)
{
    verif->i = 0;
    ls(tab, env, verif);
    pwd(tab, verif);
    cd(tab, verif);
    clear(tab, env, verif);
    my_exit(tab);
    if (verif->i == 0 && tab[0][0] != '\n')
        write(2, "invalid command\n", 16);
    return (0);
}

int my_prompt(char **av, char **env)
{
    char *line = NULL;
    char **tab;
    int *d = 0;
    size_t size = 2000; my_struct *verif = malloc(sizeof(my_struct));
    write(0, "$> ", 3);
    while (getline(&line, &size, stdin) > 0) {
        tab = word_to_tab(line);
        my_cmd(tab, env, av, verif);
        write(0, "$> ", 3);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (ac > 1)
        return (84);
    my_prompt(av, env);
    return (0);
}