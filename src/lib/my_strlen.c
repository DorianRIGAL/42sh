/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** counts and returns the numbers of characters
*/

int len(char const *str)
{
	int i = -1;

	if (!str)
		return (0);
	while (str[++i]);
	return (i);
}