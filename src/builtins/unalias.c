/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** unalias
*/

#include "main.h"

void	print_space_alias(char *tmp)
{
	if (tmp)
		my_putchar(' ');
}

void	destroy_alias(void *tmp)
{
	alias_t *alias = (alias_t*)tmp;

	free(alias->name);
	block_free(alias->after);
	free(alias);
}

void	builtin_unalias(shell_t *shell, char **input)
{
	shell->state = 0;
	if (!input[1]) {
		put_err("unalias: Too few arguments.\n");
		shell->state = 1;
	}
	for (int i = 1; input[i]; i += 1)
		delete_node(shell->aliases, input[i], &destroy_alias);
}

void alias_free_all(shell_t *shell)
{
	node_t *node;

	while (shell->aliases->head) {
		node = shell->aliases->head;
		shell->aliases->head = shell->aliases->head->next;
		destroy_alias(node->data);
		free(node);
	}
	free(shell->aliases);
}