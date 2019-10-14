/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** src/builtins/where.c
*/

#include "main.h"

int error_where(char **input)
{
	if (my_tab_len(input) < 2) {
		write(2, "where: Too few arguments.\n", 26);
		return (84);
	}
	return (0);
}

int where_alias(shell_t *shell, char *str)
{
	alias_t *tmp = get_node(shell->aliases, str);

	if (tmp == NULL)
		return (84);
	write(1, str, len(str));
	write(1, " is aliased to", 14);
	for (int i = 0; tmp->after[i] != NULL; i++) {
		write(1, " ", 1);
		write(1, tmp->after[i], len(tmp->after[i]));
	}
	write(1, "\n", 1);
	return (0);
}

int where_path(shell_t *shell, char *str)
{
	item_t *paths_base = NULL;
	char **std_paths = NULL;
	struct stat data;
	char *test;
	int check = 84;

	paths_base = env_get_var(shell, "PATH");
	if (paths_base == NULL)
		return (84);
	std_paths = my_str_to_word_array(paths_base->data, ':');
	for (int i = 0; std_paths != NULL && std_paths[i] != NULL; i++) {
		test = concat(std_paths[i], "/");
		test = concat(test, str);
		if (!lstat(test, &data) && data.st_mode & S_IXUSR) {
			write(1, test, len(test));
			write(1, "\n", 1);
			check = 0;
		}
	}
	return (check);
}

int where_builtin(UNUSED shell_t *shell, char *input)
{
	if (is_builtin(input)) {
		put_str(input);
		put_str(" is a shell built-in\n");
		return (0);
	}
	return (84);
}

void builtin_where(shell_t *shell, char **input)
{
	shell->state = 0;
	if (error_where(input) == 84) {
		shell->state = 1;
		return;
	}
	for (int i = 1, check = 0; input[i]; i++) {
		check += where_alias(shell, input[i]);
		check += where_builtin(shell, input[i]);
		check += where_path(shell, input[i]);
		if (check == 252)
			continue;
		shell->state = 1;
	}
}
