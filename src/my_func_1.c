/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_func.c
*/

#include "../include/my.h"

void my_putstr(char *str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i]; i += 1)
        write(1, &str[i], 1);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

char *my_strncpy (char *dest, char *src, int n)
{
    int a = 0;
    while (a != n) {
        dest[a] = src[a];
        a = a + 1;
    }
    if (n > a)
        dest[a] = '\0';
    return (dest);
}

int my_show_word_array(char **tab)
{
    int a = 0;
    while (tab[a] != NULL) {
        write(1, tab[a], my_strlen(tab[a]));
        my_putchar('\n');
        a += 1;
    }
    return (0);
}

int my_getnbr(char *str)
{
    int a = 0, nb = 0;
    int neg = 1;
    while (str[a] != '\0' && (str[a] < '0' || str[a] > '9')) {
        if (str[a] == '-')
            neg = neg * (-1);
        if (a == my_strlen(str))
            return (0);
        a++;
    }
    while (str[a] != '\0' && (str[a] >= '0' && str[a] <= '9')) {
        nb = nb * 10 + str[a] - 48;
        a++;
    }
    if (nb > 2147483647 || nb < -2147483647)
        return (0);
    return (nb * neg);
}