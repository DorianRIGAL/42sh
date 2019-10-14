/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** paranthesis_v2.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "leolib.h"
#include "error.h"
#include "main.h"

int count_paranthesis(char **arr, int *i)
{
	int right = 0;
	int left = 0;

	for (; arr[*i] != NULL && arr[*i][0] != ')'; *i += 1) {
		if (arr[*i][0] == '(')
			right += 1;
	}
	for (; arr[*i] != NULL && arr[*i][0] != ';'; *i += 1) {
		if (arr[*i][0] == ')')
			left += 1;
	}
	if (left > right) {
		write(2, "Too many )'s.\n", 14);
		return (-1);
	} else if (right > left) {
		write(2, "Too many ('s.\n", 14);
		return (-1);
	}
	return (0);
}

int too_many_paranthesis(char **arr)
{
	int i = 0;

	while (arr[i] != NULL) {
		if (count_paranthesis(arr, &i) == -1)
			return (-1);
	}
	return (0);
}

int is_foreach(char *str)
{
	char **tmp = my_str_to_word_array(str, ' ');

	if (my_strcmp(tmp[0], "foreach") == 0) {
		free_str_arr(tmp);
		return (1);
	}
	free_str_arr(tmp);
	return (0);
}

int badly_place_paranthesis(char **arr)
{
	int i = 0;

	for (; arr[i] != NULL; i += 1) {
		if (arr[i][0] == '(' && i >= 1 && arr[i - 1][0] != '('
		&& is_if(arr[i - 1], 0) == 0 && is_foreach(arr[i - 1]) == 0 &&
		is_cmd_sep(arr[i - 1]) == 0) {
			write(2, "Badly placed ()'s.\n", 19);
			return (-1);
		} else if (arr[i][0] == '(' && i >= 2 && arr[i - 1][0] != '('
		&& is_if(arr[i - 1], 0) == 1 &&
		is_cmd_sep(arr[i - 2]) == 0) {
			write(2, "Badly placed ()'s.\n", 19);
			return (-1);
		}
	}
	return (0);
}

int error_paranthesis(char **arr)
{
	if (badly_place_paranthesis(arr) == -1 ||
	too_many_paranthesis(arr) == -1)
		return (-1);
	return (0);
}