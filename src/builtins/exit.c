/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** src/builtins/exit.c : Exit builtin.
*/

#include "main.h"

bool	check_nbr(char *str)
{
	int y = 0;

	if (str[0] == '-')
		y++;
	for (; str[y]; y++) {
		if (str[y] < '0' || str[y] > '9')
			return (false);
	}
	return (true);
}

void builtin_exit(shell_t *shell, char **input)
{
	if (my_tab_len(input) > 2 || (my_tab_len(input) == 2 &&
	((input[1][0] < '0' && input[1][0] != '-') || input[1][0] > '9'))
	|| (my_tab_len(input) == 2 && input[1][0] == '-' &&
	len(input[1]) == 1)) {
		put_err("exit: Expression Syntax.\n");
		shell->state = 1;
		return;
	}
	if (my_tab_len(input) == 2 && !check_nbr(input[1])) {
		put_err("exit: Badly formed number.\n");
		shell->state = 1;
		return;
	}
	if (isatty(0))
		write(1, "exit\n", 5);
	if (input[1])
		shell->state = (unsigned char)my_getnbr(input[1]);
	shell->quit = 1;
}

void main_exit(shell_t *shell)
{
	if (isatty(0))
		write(1, "exit\n", 5);
	else
		write(1, "\n", 1);
	shell->quit = 1;
}