/*
** EPITECH PROJECT, 2018
** env_variable.c
** File description:
** 42sh
*/

#include "main.h"

int	check_env_var(char **dest, char *name, shell_t *shell)
{
	item_t *tmp = env_get_var(shell, name);

	if (!tmp) {
		put_err(name);
		put_err(": Undefined variable.\n");
		shell->state = 1;
		free(name);
		return (84);
	}
	*dest = tmp->data;
	free(name);
	return (0);
}
