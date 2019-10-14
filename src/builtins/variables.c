/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/variables.c
*/

#include "main.h"

void builtin_set_add_var(shell_t *shell, char *name, char *data)
{
	variable_t *var = get_node(shell->variables, name);

	if (!var) {
		var = malloc(sizeof(variable_t));
		var->name = my_strdup(name);
		var->data = my_strdup(data);
		add_node_sort(shell->variables, var);
	} else if (data)
		var->data = my_strdup(data);
}

void builtin_set_check(shell_t *shell, char *input)
{
	char **cutted = NULL;
	bool found = false;
	int i = 0;

	while (input[i]) {
		if (input[i] == '=') {
			found = true;
			break;
		}
		i++;
	}
	if (found) {
		cutted = my_strcut_at(input, i);
		builtin_set_add_var(shell, cutted[0], input + i + 1);
		block_free(cutted);
	} else
		builtin_set_add_var(shell, input, NULL);
}

void builtin_set(shell_t *shell, char **input)
{
	if (my_tab_len(input) == 1) {
		builtin_set_print(shell);
		return;
	}
	for (int i = 1; input && input[i]; i++) {
		if (input[i][0] < 'A' || input[i][0] > 'z' ||
		(input[i][0] > 'Z' && input[i][0] < 'a')) {
			put_err(SET_VAR_ERR);
			return;
		} else if (input[i + 1] && !my_strcmp(input[i + 1], "=")
		&& input[i + 2]) {
			builtin_set_add_var(shell, input[i], input[i + 2]);
			i += 2;
		} else
			builtin_set_check(shell, input[i]);
	}
}

void builtin_unset(shell_t *shell, char **input)
{
	variable_t *var = NULL;

	if (!input || !input[0] || !input[1]) {
		put_err(UNSET_TOO_FEW);
		return;
	}
	var = get_node(shell->variables, input[1]);
	if (var)
		delete_node(shell->variables, var->name, &variable_destroy);
}