/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_exec.c
*/

#include "../include/my.h"

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
    }
    else {
        if (execve(path, tab, env) == -1);
        exit(EXIT_FAILURE);
    }
}
