/*
** EPITECH PROJECT, 2017
** dante
** File description:
** home/dorianrigal/B2-Shell_Programming/PSU_42sh_2017/src/error/paranthesis.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "leolib.h"
#include "error.h"
#include "main.h"

int side_paranthesis(char **arg, int pos, int side)
{
	if (pos < 0 || arg[pos] == NULL)
		return (0);
	if (side == -1 && (arg[pos][0] == ')' || arg[pos][0] == '>' ||
	arg[pos][0] == '<')) {
		put_err("Too many )'s.\n");
		return (84);
	}
	if (side == 1 && arg[pos][0] != '<' && arg[pos][0] != '>' &&
	arg[pos][0] != '|' && arg[pos][0] != ';' && arg[pos][0] != '&') {
		put_err("Badly placed ()'s.\n");
		return (84);
	}
	return (0);
}

int parameter_paranthesis(char **arg)
{
	int check = 0;

	for (int i = 0; arg[i] != NULL && check == 0; i++) {
		if (arg[i][0] == '(')
			check = side_paranthesis(arg, i - 1, -1);
		if (arg[i][0] == ')')
			check = side_paranthesis(arg, i + 1, 1);
	}
	return (check);
}

int manage_paranthesis(char **arg, int left, int right)
{
	if (left > right) {
		put_err("Too many ('s.\n");
		return (84);
	} else if (right > left) {
		put_err("Too many )'s.\n");
		return (84);
	}
	if (parameter_paranthesis(arg) == 84)
		return (84);
	return (0);
}

int error_paranthesis(char **arg)
{
	int right = 0;
	int left = 0;

	for (int i = 0; arg[i] != NULL; i++) {
		if (arg[i][0] == '(')
			left += 1;
		if (arg[i][0] == ')')
			right += 1;
	}
	if (manage_paranthesis(arg, left, right) == 84)
		return (-1);
	return (0);
}