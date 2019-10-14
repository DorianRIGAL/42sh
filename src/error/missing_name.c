/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** error.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "error.h"

int missing_name_error(char **arr, int i)
{
	if (is_a_redirect(arr[i]) == 1 && (
	arr[i + 1] == NULL || (arr[i + 1] != NULL &&
	is_a_sep(arr[i + 1], 0) != 0))) {
		write(1, "Missing name for redirect.\n", 27);
		return (-1);
	}
	return (0);
}

int missing_name_redirect(char **arr)
{
	for (int i = 0; arr != NULL && arr[i] != NULL; i += 1) {
		if (is_a_redirect(arr[i]) == 1 &&
		missing_name_error(arr, i) == -1)
			return (-1);
	}
	return (0);
}
