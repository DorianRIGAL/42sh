/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** src/modules/parser.c : Parse Input
*/

#include "main.h"

int execute_builtin(shell_t *shell, char **splitted)
{
	if (!is_builtin(splitted[0]))
		return (0);
	builtin_func(splitted[0])(shell, splitted);
	return (1);
}

int execute_at(char **std_paths, char **env, char **splitted)
{
	struct stat data;
	char *before;
	char *test;
	int res = 0;

	for (int i = 0; std_paths && std_paths[i]; i++) {
		before = concat(std_paths[i], "/");
		test = concat(before, splitted[0]);
		if (!lstat(test, &data) && data.st_mode & S_IXUSR) {
			res = global_execute(test, splitted, env);
			free(before);
			free(test);
			return (res);
		}
		free(before);
		free(test);
	}
	return (-1);
}

int my_str_contains(char *input, char c)
{
	int i = -1;

	while (input[++i]) {
		if (input[i] == c)
			return (1);
	}
	return (0);
}

int validate_binary(shell_t *shell, char **splitted)
{
	char *paths_base = NULL;
	char **std_paths = NULL;
	char **env = env_get(shell);
	int res = 0;

	if (!env)
		return (res);
	if (!env_get_var(shell, "PATH") || !env_get_var(shell, "PATH")->data
	|| my_str_contains(splitted[0], '/')) {
		res = raw_execute(env, splitted);
		block_free(env);
		return (res);
	}
	paths_base = env_get_var(shell, "PATH")->data;
	std_paths = my_str_to_word_array(paths_base, ':');
	res = execute_at(std_paths, env, splitted);
	if (res == -1)
		output_not_found(splitted[0]);
	free_up(NULL, env, std_paths);
	return (res == -1 ? 1 : res);
}

void parse(shell_t *shell, char *input, UNUSED int fdin, UNUSED int fdout)
{
	char **splitted = NULL;

	if (len(input) < 1)
		return;
	splitted = my_str_to_word_array(input, ' ');
	splitted = analyse_input(shell, splitted);
	if (!splitted)
		return;
	clear_quote_tab(splitted);
	if (!splitted[0] || my_is_clear(splitted[0]))
		return (block_free(splitted));
	if (execute_builtin(shell, splitted))
		return (block_free(splitted));
	shell->state = validate_binary(shell, splitted);
}
