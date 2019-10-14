/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/builtins.c : The real builtin database.
*/

#include "main.h"

builtin_t builtins[] = {
	{"alias", &builtin_alias},
	{"builtins", &builtin_builtins},
	{"cd", &builtin_cd},
	{"echo", &builtin_echo},
	{"env", &builtin_env},
	{"exit", &builtin_exit},
	{"foreach", &builtin_foreach},
	{"if", &builtin_if},
	{"repeat", &builtin_repeat},
	{"set", &builtin_set},
	{"setenv", &builtin_setenv},
	{"unalias", &builtin_unalias},
	{"unset", &builtin_unset},
	{"unsetenv", &builtin_unsetenv},
	{"where", &builtin_where},
	{"which", &builtin_which},
	{"\0", NULL},
};

void builtin_builtins(shell_t *shell, char **input)
{
	int i = 0;

	if (my_tab_len(input) > 1) {
		put_err("builtins: Too many arguments.");
		shell->state = 1;
		return;
	}
	for (; builtins[i].func; i++)
		printf("%-11s", builtins[i].var);
	printf("\n");
	shell->state = 0;
}

bool is_builtin(char *input)
{
	for (int i = 0; builtins[i].func; i++) {
		if (!my_strcmp(builtins[i].var, input))
			return (true);
	}
	return (false);
}

builtin_func_t builtin_func(char *input)
{
	if (!is_builtin(input))
		return (NULL);
	for (int i = 0; builtins[i].func; i++) {
		if (!my_strcmp(builtins[i].var, input))
			return (builtins[i].func);
	}
	return (NULL);
}
