/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** src/utils/my_strcat.c : Concatenate two strings.
*/

#include <stdlib.h>

int len(char const*);

char *concat(char *str1, char *str2)
{
	int len_a = len(str1);
	int len_b = len(str2);
	char *ns = malloc(sizeof(char) * (len_a + len_b + 1));
	int i = 0;
	int j = 0;

	if (!ns)
		return (NULL);
	while (str1 && str1[i]) {
		ns[i] = str1[i];
		i += 1;
	}
	while (str2 && str2[j]) {
		ns[i + j] = str2[j];
		j += 1;
	}
	ns[i + j] = 0;
	return (ns);
}

char *concat_free(char *str1, char *str2)
{
	int len_a = len(str1);
	int len_b = len(str2);
	char *ns = malloc(sizeof(char) * (len_a + len_b + 1));
	int i = 0;
	int j = 0;

	if (!ns)
		return (NULL);
	while (str1 && str1[i]) {
		ns[i] = str1[i];
		i += 1;
	}
	while (str2 && str2[j]) {
		ns[i + j] = str2[j];
		j += 1;
	}
	ns[i + j] = 0;
	if (str1)
		free(str1);
	return (ns);
}