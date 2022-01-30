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
#include <signal.h>
#include <errno.h>
#define m_len my_strlen
#define m_cmp my_strcmp
#define m_cpy my_strcpy

#ifndef MY_H_
#define MY_H_

typedef struct verif_s {
    int i;
    int verif_env;
    int verif_func;
} my_struct_t;

typedef struct env_s {
    char *refresh_pwd;
    char **tab_pwd;
    char **tab;
    char **path;
    char **env;
    char **tmp_env;
    char *str;
    char *str2;
    char *stock;
    int verif;
} my_env_t;

int my_prompt(my_env_t *m, my_struct_t *verif, int *ret);
int tab_len(char **tab);
char *my_strdup(char *str);
void my_putchar(char c);
void my_putstr(char *str);
int my_getnbr(char *str);
int my_strlen(char *str);
int my_show_word_array(char **tab);
char *my_itoa(int nb);
int my_strcmp(char *s1, char *s2);
int my_strcmp2(char *s1, char *s2);
int create_tab(char *str, char c);
char **word_to_tab(char *str, char c, int i);
char *my_strcpy(char *dest, char const *src);
char **check_spaces(char **tab, char limit);
char *my_strcat(char *dest, char const *src);
int my_cmd(my_env_t *m, my_struct_t *verif, int *ret);
int check_cmd(my_env_t *m, my_struct_t *verif, int *ret);
int path_cmd(my_env_t *m, int *ret);
char **get_path(char **env);
char *clean_line(char *line);
void my_exec(char *path, char **tab, char **env, int *ret);
void my_putstr_error(char *str);
int print_error(char *str, char *str2);
int cd(my_env_t *m, int *ret);
char *rm_extra_spaces(char *str);
char *tab_to_space(char *str);
int is_alpha(char *str);
int my_exit(my_env_t *m);
int my_setenv(my_env_t *m, int *ret);
char **refresh_env(my_env_t *m, char *str);
char **set_setenv(char **tab, my_env_t *my_env, char **env);
char *charge_setenv(char **tab, int arg);
int my_new_env(my_env_t *my_env);
int my_env_exist(my_env_t *m);
int pos_env(my_env_t *m, char *str);
int exist_setenv(my_env_t *m, char *str);
int no_exist_setenv(my_env_t *m, char *str);
int if_setenv_exist(my_env_t *m);
int if_setenv(my_env_t *m);
int pos_env(my_env_t *m, char *str);
int if_unsetenv(my_env_t *m);
int my_unsetenv(my_env_t *m, int *ret);
int my_env(my_env_t *m, int *ret);
int exec(my_env_t *m, int *ret);
int my_env_exist_for_cd(my_env_t *m);
int exist_setenv_for_cd(my_env_t *m, char *str);
int if_setenv_for_cd(my_env_t *m);
int my_setenv_for_cd(my_env_t *m, int *ret);
char *clean_get_home(char *home);
int pwd_tab(my_env_t *m);

#endif
