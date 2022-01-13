/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** minishell1.c
*/

#include "include/my.h"

void print_arg(char **arg)
{
    char **tab;
    while (* arg) {
        tab = word_to_tab(* arg);
        arg ++;
    }
    my_show_word_array(tab);
    return;
}

int main(int ac, char **av, char **env)
{
    execve(av[1], av + 1, env);
}