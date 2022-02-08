/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_exec.c
*/

#include "../include/my.h"

void status_checker(int *ret, int status)
{
    if (status == SIGSEGV) {
        my_putstr_error("Segmentation fault.\n");
        *ret = 139;
    }
    if (status == SIGFPE) {
        my_putstr_error("Floating exception.\n");
        *ret = 136;
    }
}

void my_exec(char *path, char **tab, char **env, int *ret)
{
    pid_t pid = fork();
    int status = 0;
    if (pid == -1)
        perror("fork ");
    else if (pid > 0) {
        waitpid(pid, &status, 0);
        kill(pid, SIGTERM);
        if (status != 0 && status != 256)
            *ret = 2;
        status_checker(ret, status);
    }
    else {
        if (execve(path, tab, env) == -1);
        exit(EXIT_FAILURE);
    }
}

int exec(my_env_t *m, int *ret)
{
    int j = 0;
    char *stock = my_strdup(m->tab[0]);
    for (int i = 2; m->tab[0][i] != '\0'; i += 1) {
        m->tab[0][j] = m->tab[0][i];
        j += 1;
    }
    m->tab[0][j] = '\0';
    if (access(m->tab[0], X_OK) == 0)
        my_exec(stock, m->tab, m->env, ret);
    else {
        *ret = 1;
        print_error(stock, ": No such file or directory\n");
    }
    return (0);
}
