##
## EPITECH PROJECT, 2021
## B-PSU-101-MAR-1-1-minishell1-thibaut.tran
## File description:
## Makefile
##

SRC	=	mysh.c	\
		src/my_func_1.c	\
		src/my_func_2.c	\
		src/my_func_3.c	\
		src/my_cmd.c	\
		src/my_setenv_1.c	\
		src/my_setenv_2.c	\
		src/my_get_path.c	\
		src/my_exec.c	\
		src/my_error.c	\
		src/my_prompt.c	\
		src/my_check_cmd.c	\
		src/my_unsetenv.c

OBJ	=	$(SRC:.c=.o)

NAME	= mysh

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	gcc	-g $(OBJ) 	-o	$(NAME)

clean :
	rm	-f	*.o
	rm	-f	*~
	rm src/*.o

fclean :
	rm	-f	$(NAME)

re :	fclean	all	clean