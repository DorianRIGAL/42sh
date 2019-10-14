/*
** EPITECH PROJECT, 2018
** lib
** File description:
** strcat and add space between and free arg
*/

#include "main.h"

char	*my_strcat_space(char *s1, char *s2)
{
	char *new = malloc(sizeof(char) * (len(s1) + len(s2) + 2));
	int i = 0;
	int j = 0;

	if (!new)
		return (NULL);
	for (; s1 && s1[i]; i += 1)
		new[i] = s1[i];
	if (i)
		new[i] = ' ';
	else
		i = -1;
	for (i += 1; s2 && s2[j]; i += 1, j += 1)
		new[i] = s2[j];
	new[i] = 0;
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (new);
}
