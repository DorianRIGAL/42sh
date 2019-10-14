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

int is_a_redirect(char *str)
{
	if (str != NULL && (my_strcmp(str, "<") == 0 ||
	my_strcmp(str, ">") == 0 ||
	my_strcmp(str, "<<") == 0 || my_strcmp(str, ">>") == 0))
		return (1);
	return (0);
}

int is_a_redipipe(char *str)
{
	if (str != NULL && (my_strcmp(str, "<") == 0 ||
	my_strcmp(str, ">") == 0 || my_strcmp(str, "|") == 0 ||
	my_strcmp(str, "||") == 0 || my_strcmp(str, "<<") == 0 ||
	my_strcmp(str, ">>") == 0 || my_strcmp(str, "&&") == 0 ||
	my_strcmp(str, "(") == 0 || my_strcmp(str, ")") == 0))
		return (1);
	return (0);
}

int is_pipe_and_or(char *str)
{
	if (my_strcmp(str, "|") == 0 || my_strcmp(str, "||") == 0 ||
	my_strcmp(str, "&&") == 0)
		return (1);
	return (0);
}

int is_cmd_sep(char *str)
{
	if (my_strcmp(str, "|") == 0 || my_strcmp(str, "||") == 0 ||
	my_strcmp(str, "&&") == 0 || my_strcmp(str, ";") == 0)
		return (1);
	return (0);
}

int is_sep(char *str)
{
	if (str != NULL && (my_strcmp(str, "<") == 0 ||
	my_strcmp(str, ">") == 0 || my_strcmp(str, "|") == 0 ||
	my_strcmp(str, "||") == 0 || my_strcmp(str, "<<") == 0 ||
	my_strcmp(str, ">>") == 0 || my_strcmp(str, "&&") == 0 ||
	my_strcmp(str, ";") == 0 || my_strcmp(str, "&&") == 0 ||
	my_strcmp(str, "(") == 0 || my_strcmp(str, ")") == 0))
		return (1);
	return (0);
}