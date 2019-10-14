/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** get_env
*/

#include "term_prototype.h"

char	*get_env(char *name, char **env)
{
	int i = 0;
	int len = strlen(name);

	for (i = 0; env[i] &&
	(strncmp(name, env[i], len) || env[i][len] != '='); i += 1);
	if (!env[i])
		return (NULL);
	return (strdup(env[i] + len + 1));
}
