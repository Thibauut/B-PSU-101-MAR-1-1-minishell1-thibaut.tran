/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_func_2.c
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i]; i += 1);
    return i;
}

char *my_itoa(int nb)
{
    int size = 0;
    char *nb_in_str = NULL;
    int tmp = nb;
    if (tmp == 0)
        size = 1;
    while (tmp > 0) {
        tmp /= 10;
        size++;
    }
    nb_in_str = malloc(sizeof(char) * (size + 1));
    nb_in_str[size] = '\0';
    while (size--) {
        nb_in_str[size] = nb % 10  + '0';
        nb /= 10;
    }
    return (nb_in_str);
}

void my_put_nbr(int nb)
{
    int a;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0)
    {
        if (nb >= 10) {
            a = (nb % 10);
            nb = (nb - a) / 10;
            my_put_nbr(nb);
            my_putchar(48 + a);
        }
        else
            my_putchar(48 + nb % 10);
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    while ((s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0')
        i += 1;
    for (; s1[j] != '\0'; j += 1);
    if (j == i)
        return (0);
    else
        return (1);
    return (0);
}

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;
    while (src[a] != '\0') {
        dest[a] = src [a];
        a = a + 1;
    }
    dest[a] = src[a];
    return (dest);
}