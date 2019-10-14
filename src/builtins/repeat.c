/*
** EPITECH PROJECT, 2017
** dante
** File description:
** home/dorianrigal/B2-Shell_Programming/PSU_42sh_2017/src/builtins/repeat.c
*/

#include "main.h"

int error_repeat(char **input)
{
	if (my_tab_len(input) < 3) {
		write(2, "repeat: Too few arguments.\n", 27);
		return (84);
	}
	for (int i = 0; input[1][i] != '\0'; i++)
		if ((input[1][i] < '0' || input[1][i] > '9') &&
		input[1][i] != '-') {
			write(2, "repeat: Badly formed number.\n", 29);
			return (84);
		}
	return (my_getnbr(input[1]));
}

void builtin_repeat(shell_t *shell, char **input)
{
	int iteration = 0;
	char *tmp;

	if ((iteration = error_repeat(input)) == 84) {
		shell->state = 1;
		return;
	}
	tmp = concat(input[2], " ");
	for (int i = 3; input[i] != NULL; i++) {
		tmp = concat(tmp, input[i]);
		tmp = concat(tmp, " ");
	}
	for (int i = 0; i < iteration; i++)
		parse(shell, tmp, 0, 0);
}