/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** src/utils/my_strcut.c : Cut an string.
*/

#include <stdlib.h>
#include <leolib.h>

int find_sep(char *str, char sep)
{
	int i = 0;

	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

int find_end(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char **my_strcut(char *str, char sep)
{
	char **res = malloc(sizeof(char*) * 3);
	int sep_at = find_sep(str, sep);
	int str_end = find_end(str + sep_at + 1);
	int i = -1;
	int j = -1;

	res[0] = malloc(sizeof(char) * (sep_at + 1));
	res[1] = malloc(sizeof(char) * (str_end + 1));
	res[0][sep_at] = '\0';
	res[1][str_end] = '\0';
	res[2] = '\0';
	while (++i < sep_at)
		res[0][i] = str[i];
	while (++j < str_end)
		res[1][j] = str[++i];
	return (res);
}

char **my_strcut_at(char *str, int at)
{
	char **res = NULL;
	int sep_at = at;
	int str_end = find_end(str + sep_at + 1);
	int i = -1;
	int j = -1;

	if (at == -1 || !str || at > len(str))
		return (NULL);
	res = malloc(sizeof(char*) * 3);
	res[0] = malloc(sizeof(char) * (sep_at + 1));
	res[1] = malloc(sizeof(char) * (str_end + 1));
	res[0][sep_at] = '\0';
	res[1][str_end] = '\0';
	res[2] = '\0';
	while (++i < sep_at)
		res[0][i] = str[i];
	while (++j < str_end)
		res[1][j] = str[++i];
	return (res);
}