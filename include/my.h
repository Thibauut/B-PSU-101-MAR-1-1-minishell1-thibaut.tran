/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
void my_putstr(char *str);
int my_getnbr(char *str);
int my_strlen(char *str);
int my_show_word_array(char **tab);
char *my_strncpy (char *dest, char *src, int n);
void my_put_nbr(int nb);
char *my_itoa(int nb);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
void print_arg ( char ** arg );
char **word_to_tab(char *str);
char **check_spaces(char **tab);

#endif