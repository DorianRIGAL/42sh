/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** src/utils/my_is_clear.c : Check if str is only ' ', '\t'.
*/

#include "leolib.h"

int my_is_clear(char *str)
{
	int i = -1;

	while (str[++i]) {
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
	}
	return (1);
}

int my_str_where_contains(char *str, char c)
{
	int found = 0;
	int i = -1;

	if (!str || !c)
		return (0);
	while (str[++i]) {
		if (str[i] == c)
			found = i;
	}
	return (found);
}

void str_remove_char(char *str, char x)
{
	char *a = str;
	char *b = str;

	while (*b) {
		*a = *b++;
		if (*a != x)
			a++;
	}
	*a = 0;
}