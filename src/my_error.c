/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_error.c
*/

#include "../include/my.h"

void my_put_error(char c)
{
    write(2, &c, 1);
}

void my_putstr_error(char *str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i]; i += 1)
        my_put_error(str[i]);
}

int print_error(char *str, char *str2)
{
    my_putstr_error(str);
    my_putstr_error(str2);
    return (0);
}
