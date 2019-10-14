/*
** EPITECH PROJECT, 2017
** dante
** File description:
** home/dorianrigal/B2-Shell_Programming/PSU_42sh_2017/src/builtins/echo.c
*/

#include "main.h"

void echo_flag_n(char **input)
{
	int i = 2;

	if (input[i] == NULL)
		return;
	for (; input[i + 1] != NULL; i++) {
		put_str(input[i]);
		put_str(" ");
	}
	put_str(input[i]);
}

void builtin_echo(shell_t *shell, char **input)
{
	int i = 1;

	(void)shell;
	if (my_tab_len(input) < 2) {
		put_str("\n");
		return;
	} else if (my_strcmp(input[1], "-n") == 0) {
		echo_flag_n(input);
	} else {
		for (; input[i + 1] != NULL; i++) {
			put_str(input[i]);
			put_str(" ");
		}
		put_str(input[i]);
		put_str("\n");
	}
}