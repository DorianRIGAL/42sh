/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/variables_tools.c
*/

#include "main.h"

void variable_destroy(void *var)
{
	if (((variable_t*)var)->name)
		free(((variable_t*)var)->name);
	if (((variable_t*)var)->data)
		free(((variable_t*)var)->data);
	free((variable_t*)var);
}

char *variable_get(shell_t *shell, char *str)
{
	variable_t *var = NULL;

	var = get_node(shell->variables, str);
	if (var && var->data)
		return (var->data);
	return (NULL);
}

void builtin_set_print_last(shell_t *shell)
{
	char *last = NULL;

	if (shell->context->list->prev && shell->context->list->prev->prev)
		last = from_list_to_array(shell->context->list->prev->prev);
	put_str("_\t");
	if (last) {
		put_str(last);
		free(last);
	}
	put_str("\n");
	if (shell->variables->size > 0)
		put_str("\n");
}

void builtin_set_print(shell_t *shell)
{
	variable_t *var = NULL;

	builtin_set_print_last(shell);
	for (int i = 0; shell->variables->size; i++) {
		var = list_get(shell->variables, i);
		if (!var)
			break;
		put_str(var->name);
		put_str("\t");
		if (var->data)
			put_str(var->data);
		put_str("\n");
	}
}

void vars_free_all(shell_t *shell)
{
	node_t *node;

	while (shell->variables->head) {
		node = shell->variables->head;
		shell->variables->head = shell->variables->head->next;
		variable_destroy(node->data);
		free(node);
	}
	free(shell->variables);
}
