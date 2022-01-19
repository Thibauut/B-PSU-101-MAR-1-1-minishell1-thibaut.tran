/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define m_len my_strlen

#ifndef MY_H_
#define MY_H_

typedef struct verif_s {
    int i;
} my_struct;

void my_putchar(char c);
void my_putstr(char *str);
int my_getnbr(char *str);
int my_strlen(char *str);
int my_show_word_array(char **tab);
char *my_strncpy (char *dest, char *src, int n);
void my_put_nbr(int nb);
char *my_itoa(int nb);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char const *src);
void print_arg ( char ** arg );
char **word_to_tab(char *str);
char **check_spaces(char **tab);
char *my_strcat(char *dest, char const *src);
int my_cmd(char **tab, char **env, char **av, my_struct *verif);
void my_exec(char *ls, char **tab, char **env);
int pwd(char **tab, my_struct *verif);
int ls(char **tab, char **env, my_struct *verif);
int cd(char **tab, my_struct *verif);
int clear(char **tab, char **env, my_struct *verif);
int my_exit(char **tab);

#endif