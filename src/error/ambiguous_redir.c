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

int ambiguous_redirect_error_red(char **arr, int i)
{
	if ((my_strcmp(arr[i], "<") == 0 || my_strcmp(arr[i], "<<") == 0)
	&& (my_strcmp(arr[i + 2], "<") == 0 ||
	my_strcmp(arr[i + 2], "<<") == 0)) {
		write(1, "Ambiguous input redirect.\n", 26);
		return (-1);
	}
	return (0);
}

int ambiguous_redirect_error(char **arr, int i)
{
	if (arr[i + 1] == NULL || arr[i + 2] == NULL)
		return (0);
	else if ((my_strcmp(arr[i], ">") == 0 || my_strcmp(arr[i], ">>") == 0)
	&& (my_strcmp(arr[i + 2], ">") == 0 ||
	my_strcmp(arr[i + 2], ">>") == 0 || my_strcmp(arr[i + 2], "|") == 0)) {
		write(1, "Ambiguous output redirect.\n", 27);
		return (-1);
	}
	return (ambiguous_redirect_error_red(arr, i));
}

int ambiguous_pipe_error(char **arr, int i)
{
	if (my_strcmp(arr[i], "|") != 0)
		return (0);
	for (int k = i; arr[k] != NULL; k += 1) {
		if (my_strcmp(arr[k], "<") == 0 ||
		my_strcmp(arr[k], "<<") == 0) {
			write(1, "Ambiguous input redirect.\n", 26);
			return (-1);
		} else if (my_strcmp(arr[k], "&&") == 0 ||
		my_strcmp(arr[k], "||") == 0 ||
		my_strcmp(arr[k], ";") == 0) {
			return (0);
		}
	}
	return (0);
}

int ambiguous_redirect(char **arr)
{
	for (int i = 0; arr != NULL && arr[i] != NULL; i += 1) {
		if (is_a_redipipe(arr[i]) == 1 &&
		(ambiguous_redirect_error(arr, i) == -1 ||
		ambiguous_pipe_error(arr, i) == -1))
			return (-1);
	}
	return (0);
}