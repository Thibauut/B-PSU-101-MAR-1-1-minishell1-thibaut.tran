/*
** EPITECH PROJECT, 2021
** B-PSU-101-MAR-1-1-minishell1-thibaut.tran
** File description:
** my.h
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define m_len my_strlen

#ifndef MY_H_
#define MY_H_

typedef struct verif_s {
    int i;
    int verif_env;
    int verif_func;
} my_struct_t;

typedef struct env_s {
    char **env;
    char **tmp_env;
    char *str;
    char *stock;
    int verif;
} my_env_t;

int tab_len(char **tab);
char *my_strdup(char *str);
void my_putchar(char c);
void my_putstr(char *str);
int my_getnbr(char *str);
int my_strlen(char *str);
int my_show_word_array(char **tab);
char *my_strncpy (char *dest, char *src, int n);
char *my_itoa(int nb);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char const *src);
void print_arg ( char ** arg );
char **word_to_tab(char *str);
char **check_spaces(char **tab);
char *my_strcat(char *dest, char const *src);
int my_cmd(char **tab, my_env_t *my_env, char **av, my_struct_t *verif);
void my_exec(char *ls, char **tab, char **env);
int pwd(char **tab, my_struct_t *verif);
int ls(char **tab, char **env, my_struct_t *verif);
int cd(char **tab, my_struct_t *verif, char **env);
int clear(char **tab, char **env, my_struct_t *verif);
int my_exit(char **tab);
int my_envp(char **tab, my_env_t *my_env, my_struct_t *verif);
char **my_setenv(char **tab, my_env_t *my_env, my_struct_t *verif, char **env);
char *charge_setenv(char **tab, int arg);
int my_unsetenv(char **tab, my_env_t *my_env, my_struct_t *verif);
char *clean_get_home(char *home);
int exec(char **tab, char **env, my_struct_t *verif);
char **set_setenv(char **tab, my_env_t *my_env, char **env);
char *charge_setenv(char **tab, int arg);
char **my_new_env(char **env, char *str, char **env2);
char **my_new_env2(char **env, char *str);
int pos_env(my_env_t *my_env, char **tab);
char **exist_setenv(char **tab, my_env_t *my_env, char *str);
char **no_exist_setenv(char **tab, my_env_t *my_env, char **env);
char **set_setenv(char **tab, my_env_t *my_env, char **env);

#endif