/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** error.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "leolib.h"
#include "error.h"
#include "main.h"

int is_redir_in_par(char **arr, int i)
{
	int passed = 0;

	for (; arr && arr[i] != NULL && is_pipe_and_or(arr[i]) != 1 &&
	my_strcmp(arr[i], ";") != 0; i += 1) {
		if (my_strcmp(arr[i], "<<") == 0)
			passed = 1;
	}
	for (; passed == 1 && arr && arr[i] != NULL &&
	is_pipe_and_or(arr[i]) != 1 &&
	my_strcmp(arr[i], ";") != 0; i += 1) {
		if (arr[i][0] == ')')
			return (0);
	}
	if (passed == 1) {
		write(2, "Can't << within ()'s.\n", 22);
		return (-1);
	}
	return (0);
}

int is_in_par(char **arr, int i)
{
	for (; arr[i] != NULL && is_pipe_and_or(arr[i]) != 1 &&
	my_strcmp(arr[i], ";") != 0; i += 1) {
		if (is_sep(arr[i]) != 1)
			return (1);
	}
	return (0);
}

int and_err(char **arr, int i)
{
	if ((my_strcmp(arr[i], "&&") == 0) &&
	i > 0 && is_sep(arr[i - 1]) == 0 && (arr[i + 1] == NULL ||
	(is_sep(arr[i + 1]) == 1 && arr[i + 1][0] != '('))) {
		return (-1);
	}
	return (0);
}

int invalid_command_error(char **arr, int i)
{
	if (and_err(arr, i) || ((is_pipe_and_or(arr[i]) == 1 ||
	is_a_redirect(arr[i]) == 1) &&
	my_strcmp(arr[i], "&&") != 0 &&
	(i == 0 || arr[i + 1] == NULL ||
	(is_sep(arr[i - 1]) == 1 && arr[i - 1][0] != ')') ||
	(is_sep(arr[i + 1]) == 1 && arr[i + 1][0] != '(')))) {
		write(1, "Invalid null command.\n", 22);
		return (-1);
	} else if (my_strcmp(arr[i], "(") == 0 && is_in_par(arr, i) == 0) {
		write(1, "Invalid null command.\n", 22);
		return (-1);
	}
	return (invalid_command_error_dep(arr, i));
}

int error_red(char **arr, shell_t *shell)
{
	if (arr == NULL)
		return (-1);
	if (error_paranthesis(arr) == -1 || missing_name_redirect(arr) == -1) {
		shell->state = 1;
		free_str_arr(arr);
		return (-1);
	}
	for (int i = 0; arr != NULL && arr[i] != NULL; i += 1) {
		if (is_a_redipipe(arr[i]) == 1 &&
		(ambiguous_redirect_error(arr, i) == -1 ||
		missing_name_error(arr, i) == -1 ||
		invalid_command_error(arr, i) == -1 ||
		ambiguous_pipe_error(arr, i) == -1)) {
			shell->state = 1;
			free_str_arr(arr);
			return (-1);
		}
	}
	free_str_arr(arr);
	return (0);
}
