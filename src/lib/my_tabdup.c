/*
** EPITECH PROJECT, 2017
** dante
** File description:
** home/dorianrigal/B2-Shell_Programming/PSU_42sh_2017/src/lib/my_tabdup.c
*/

#include "main.h"

char **my_tabdup(char **tab)
{
	char **result = malloc(sizeof(char *) * my_tab_len(tab));
	int i = 0;

	for (; tab[i] != NULL; i++)
		result[i] = my_strdup(tab[i]);
	result[i] = NULL;
	return (result);
}