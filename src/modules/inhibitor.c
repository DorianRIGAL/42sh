/*
** EPITECH PROJECT, 2017
** dante
** File description:
** home/dorianrigal/B2-Shell_Programming/PSU_42sh_2017/src/modules/inhibitor.c
*/

#include "main.h"

char *special_inhib(char *str, int *i)
{
	char *result = malloc(sizeof(char) * len(str));

	for (int u = 0; u < *i; u++)
		result[u] = str[u];
	for (int u = *i; str[u + 1] != '\0'; u++)
		result[u] = str[u + 1];
	result[len(str) - 1] = '\0';
	return (result);
}

char *classic_inhib(char *str, int *i)
{
	char *result = malloc(sizeof(char) * (len(str) - 1));

	for (int u = 0; u < *i; u++)
		result[u] = str[u];
	for (int u = *i; str[u + 2] != '\0'; u++)
		result[u] = str[u + 2];
	result[len(str) - 2] = '\0';
	return (result);
}

char *place_inhibitor(char *str, int *i)
{
	printf("%s\n", str);
	if (str[*i + 1] == '\\' || str[*i + 1] == '\0') {
		str = special_inhib(str, i);
	} else {
		str = classic_inhib(str, i);
	}
	printf("%s\n", str);
	return (str);
}

char *inhibitor(char *str)
{
	for (int i = 0; i < len(str) && str[i] != '\0'; i++)
		if (str[i] == '\\')
			str = place_inhibitor(str, &i);
	return (str);
}

int main(int ac, char **av)
{
	printf("%s\n", inhibitor(av[1]));
}