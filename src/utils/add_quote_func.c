/*
** EPITECH PROJECT, 2017
** dante
** File description:
** home/dorianrigal/PSU_42sh_2017/src/utils/add_quote_func.c
*/

#include "main.h"

char *add_quote(char *str, int check)
{
	char *result = malloc(sizeof(char) * (len(str) + 2));

	if (check == -1) {
		result[0] = '"';
		for (int i = 0; str[i] != '\0'; i++)
			result[i + 1] = str[i];
	} else {
		for (int i = 0; str[i] != '\0'; i++)
			result[i] = str[i];
		result[len(str)] = '"';
	}
	result[len(str) + 1] = '\0';
	free(str);
	return (result);
}

char *first_quote_foreach(char *str)
{
	int i = 0;
	char *result = malloc(sizeof(char) * (len(str) + 3));

	for (; i < 7; i++)
		result[i] = str[i];
	result[i] = ' ';
	i += 1;
	result[i] = '"';
	i += 1;
	for (int u = i - 1; str[u] != '\0'; i++, u++)
		result[i] = str[u];
	result[len(str) + 1] = '\0';
	free(str);
	return (result);
}

char **add_quote_if(char **tab, int i)
{
	int u = i + 1;

	if (tab[u] == NULL)
		return (tab);
	tab[u] = add_quote(tab[u], -1);
	for (; tab[u] != NULL && my_strcmp(tab[u], ";") != 0; u++)
		if (my_strcmp(tab[u], "(") == 0)
			for (; my_strcmp(tab[u], ")") != 0; u++);
	tab[u - 1] = add_quote(tab[u - 1], 1);
	return (tab);
}

char **add_quote_foreach(char **tab, int i)
{
	int u = i + 1;

	tab[i] = first_quote_foreach(tab[i]);
	for (; tab[u] != NULL && my_strcmp(tab[u], ";") != 0 &&
	my_strcmp(tab[u], "|") != 0 && my_strcmp(tab[u], ">") != 0 &&
	my_strcmp(tab[u], "<") != 0 && my_strcmp(tab[u], ">>") != 0 &&
	my_strcmp(tab[u], "<<") != 0; u++) {
		if (my_strcmp(tab[u], "(") == 0) {
			for (; my_strcmp(tab[u], ")") != 0; u++);
		}
	}
	tab[u - 1] = add_quote(tab[u - 1], 1);
	return (tab);
}

char *add_quote_func(char *str)
{
	char *result = " ";
	char **tab = my_lexer(str);

	for (int i = 0; tab != NULL && tab[i] != NULL; i++) {
		if (my_strcmp_till("foreach", tab[i], 7) == 0)
			tab = add_quote_foreach(tab, i);
		else if (my_strcmp(tab[i], "if") == 0)
			tab = add_quote_if(tab, i);
	}
	if (tab == NULL || tab[0] == NULL)
		return (str);
	result = concat(tab[0], result);
	for (int i = 1; tab != NULL && tab[i] != NULL; i++) {
		result = concat(result, tab[i]);
		result = concat(result, " ");
	}
	return (result);
}