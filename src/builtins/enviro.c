/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** src/builtins/enviro.c : Env builtins.
*/

#include "main.h"

void builtin_unsetenv(shell_t *shell, char **input)
{
	if (!input[1]) {
		put_err(UNSET_MANY);
		shell->state = 1;
		return;
	}
	for (int x = 1; input[x]; x++)
		env_remove_var(shell, input[x]);
}

void builtin_env(shell_t *shell, UNUSED char **input)
{
	char **env = env_get(shell);

	for (int x = 0; env[x]; x++) {
		write(1, env[x], len(env[x]));
		write(1, "\n", 1);
	}
	block_free(env);
}

int setenv_check_characters(char *str)
{
	if (my_char_isnum(str[0])) {
		put_err(ENV_HELP);
		return (0);
	} else if (!my_str_isalpha(str)) {
		put_err(ENV_ALPHA);
		put_err(ENV_BETA);
		return (0);
	}
	return (1);
}

void builtin_setenv(shell_t *shell, char **input)
{
	int count = -1;

	while (input[++count]);
	if (count == 1) {
		builtin_env(shell, input);
		return;
	} else if (count > 3) {
		put_err(ENV_MANY);
		shell->state = 1;
		return;
	}
	if (!setenv_check_characters(&input[1][0])) {
		shell->state = 1;
		return;
	}
	if (count == 3) {
		env_add_var(shell, input[1], input[2]);
	} else if (count == 2)
		env_add_var(shell, input[1], "");
}