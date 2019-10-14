/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** src/utils/my_strcpy.c : Copy an string into another.
*/

#include <stdlib.h>
#include <stdio.h>

int len(char const*);

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (src[i]) {
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

char *my_strdup(char *src)
{
	char *dest;

	if (!src)
		return (NULL);
	dest = malloc(sizeof(char) * (len(src) + 1));
	if (!dest)
		return (NULL);
	dest = my_strcpy(dest, src);
	return (dest);
}

char *my_strndup(char *src, int n)
{
	char *dest;

	if (!src)
		return (NULL);
	dest = calloc(n + 1, sizeof(char));
	if (!dest)
		return (NULL);
	for (int i = 0; i <= n; i += 1)
		dest[i] = 0;
	for (int i = 0; src[i] && i < n; i += 1)
		dest[i] = src[i];
	return (dest);
}