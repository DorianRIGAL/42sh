/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** get_semicolon.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "error.h"

int is_a_sep(char *path, int i)
{
	if (path && path[0] != '\0' && ((path[i] == '|' &&
	(path[i + 1] == '\0' ||
	(path[i + 1] != '\0' && path[i + 1] != '|'))) ||
	path[i] == ';' || ((path[i] == '>' || path[i] == '<') &&
	path[i + 1] == '\0') || (path[i] == '>' && path[i + 1] != '\0' &&
	path[i + 1] != '>') || (path[i] == '<' && path[i + 1] != '\0' &&
	path[i + 1] != '<')))
		return (1);
	else if (path && path[0] != '\0' && ((path[i] == '>' &&
	path[i + 1] != '\0' && path[i + 1] == '>') || (path[i] == '<' &&
	path[i + 1] != '\0' && path[i + 1] == '<') || (path[i] == '&' &&
	path[i + 1] != '\0' && path[i + 1] == '&') || (path[i] == '|' &&
	path[i + 1] != '\0' && path[i + 1] == '|')))
		return (2);
	return (0);
}

int separator(char c)
{
	int i = 0;
	op_t op_list[] = {{1, ';'}, {2, ')'}, {2, '('}, {3, '|'}, {4, '<'},
	{5, '>'}, {6, '&'}, {-1, -1}};

	if (c == '\0')
		return (-1);
	for (; op_list[i].id != -1 && op_list[i].op != c; i += 1);
	return (op_list[i].id);
}

void pass_space_and_tab(char *path, int *i)
{
	for (; path && path[0] != '\0' &&
	(path[*i] == ' ' || path[*i] == '\t'); *i += 1);
}

char **my_lexer(char *to_lex)
{
	char **arr = malloc_sem_arr(to_lex);

	if (arr == NULL)
		return (NULL);
	arr = fill_sem_arr(arr, to_lex);
	return (arr);
}