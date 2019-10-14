/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/utils/pull_line.c
*/

#include "main.h"

char *pull_next_line(char **input)
{
	char *str = *input;
	char **hola = NULL;

	if (!str || !str[0])
		return (NULL);
	hola = my_strcut(str, '\n');
	free(str);
	*input = hola[1];
	return (hola[0]);
}