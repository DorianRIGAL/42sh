/*
** EPITECH PROJECT, 2017
** dante
** File description:
** PSU_42sh_2017/src/error/exotic_redirection.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "leolib.h"
#include "error.h"
#include "main.h"

int tablen(char **tab)
{
	int result = 0;

	for (; tab[result] != NULL; result++);
	return (result);
}

char *recup_command(char **arg, int pos)
{
	int size = len(arg[pos + 1]);
	int i = 0;
	char *result = NULL;

	for (; arg[pos + 1][i] == ' '; i++);
	for (; arg[pos + 1][i] != ' ' && arg[pos + 1][i] != '\t'; i++);
	size = size - i;
	result = malloc(sizeof(char) * (size + 1));
	for (int u = 0; arg[pos + 1][i] != '\0'; u++, i++)
		result[u] = arg[pos + 1][i];
	result[size] = '\0';
	return (result);
}

char **fill_new(char **result, char **arg, int pos)
{
	int i = 0;

	for (; i < pos; i++) {
		result[i] = my_strdup(arg[i]);
	}
	result[i + 1] = my_strdup(arg[i]);
	i += 2;
	for (int u = i + 1; arg[i] != NULL; i++, u++)
		result[u] = my_strdup(arg[i]);
	return (result);
}

char **fill_arguments(char **result, char **arg, int pos)
{
	char **tmp = my_str_to_word_array(arg[pos + 1], ' ');

	result[pos] = my_strdup(tmp[0]);
	for (int i = 0; tmp[i] != NULL; i++)
		free(tmp[i]);
	result[pos + 2] = recup_command(arg, pos);
	return (result);
}

char **modif_exotic_redirec(char **arg, int pos)
{
	char **result = malloc(sizeof(char *) * (tablen(arg) + 2));
	char *tmp = NULL;

	result[tablen(arg) + 1] = NULL;
	result = fill_new(result, arg, pos);
	result = fill_arguments(result, arg, pos);
	for (int i = 0; arg[i] != NULL; i++)
		free(arg[i]);
	tmp = result[pos];
	result[pos] = result[pos + 2];
	result[pos + 2] = tmp;
	return (result);
}