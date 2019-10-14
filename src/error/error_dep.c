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

int invalid_command_error_dep(char **arr, int i)
{
	if (my_strcmp(arr[i], "(") == 0 && is_redir_in_par(arr, i) == -1) {
		return (-1);
	}
	return (0);
}