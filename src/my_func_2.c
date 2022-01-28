/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my_func_2.c
*/

#include "../include/my.h"

char *my_strdup(char *str)
{
    int i = 0;
    for (; str[i]; i += 1);
    char *temp = malloc(sizeof(char) * i + 1);
    for (int i = 0; str[i]; i += 1)
        temp[i] = str[i];
    temp[i] = '\0';
    return temp;
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

int my_strcmp(char *s1, char *s2)
{
    int len = my_strlen(s2);
    if (len != my_strlen(s1))
        return (1);
    for (int j = 0; j != len; j += 1) {
        if (s1[j] != s2[j])
            return (1);
    }
    return (0);
}

int my_strcmp2(char *s1, char *s2)
{
    int len = my_strlen(s2);
    for (int j = 0; j != len; j += 1) {
        if (s1[j] != s2[j])
            return (1);
    }
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