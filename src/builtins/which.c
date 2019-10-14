/*
** EPITECH PROJECT, 2017
** dante
** File description:
** home/dorianrigal/B2-Shell_Programming/PSU_42sh_2017/src/builtins/wich.c
*/

#include "main.h"

int error_which(char **input)
{
	if (my_tab_len(input) < 2) {
		write(2, "which: Too few arguments.\n", 26);
		return (84);
	}
	return (0);
}

int which_alias(shell_t *shell, char *str)
{
	alias_t *tmp = get_node(shell->aliases, str);

	if (tmp == NULL)
		return (84);
	write(1, str, len(str));
	put_str(": \t aliased to");
	for (int i = 0; tmp->after[i] != NULL; i++) {
		write(1, " ", 1);
		write(1, tmp->after[i], len(tmp->after[i]));
	}
	write(1, "\n", 1);
	return (0);
}

int which_path(shell_t *shell, char *str)
{
	item_t *paths_base = NULL;
	char **std_paths = NULL;
	struct stat data;
	char *test;

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
			return (0);
		}
	}
	return (84);
}

int which_builtin(UNUSED shell_t *shell, char *input)
{
	if (is_builtin(input)) {
		put_str(input);
		put_str(": shell built-in command.\n");
		return (0);
	}
	return (84);
}

void builtin_which(shell_t *shell, char **input)
{
	shell->state = 0;
	if (error_which(input) == 84) {
		shell->state = 1;
		return;
	}
	for (int i = 1; input[i] != NULL; i++) {
		if (which_alias(shell, input[i]) == 0)
			continue;
		if (which_builtin(shell, input[i]) == 0)
			continue;
		if (which_path(shell, input[i]) == 0)
			continue;
		write(2, input[i], len(input[i]));
		write(2, ": Command not found.\n", 21);
		shell->state = 1;
	}
}
