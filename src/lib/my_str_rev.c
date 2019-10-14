/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** String reverse.
*/

int len(char*);
char *my_strdup(char*);

char *my_revstr(char *new)
{
	char *str = my_strdup(new);
	int length = len(str);

	for (int i = -1; ++i < length && str[i]; str[i] = new[length - i - 1]);
	return (str);
}