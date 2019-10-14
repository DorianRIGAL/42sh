/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** alias
*/

#include "main.h"

node_t	*apply_alias(alias_t *alias, node_t *tmp_head, node_t **head)
{
	node_t *tmp = NULL;

	for (int i = 0; alias->after[i]; i += 1)
		tmp = node_add(head, tmp, strdup(alias->after[i]));
	tmp->next = tmp_head->next;
	free(tmp_head->data);
	free(tmp_head);
	alias->loop = 1;
	return (*head);
}

int	check_alias_loop(shell_t *shell, node_t *tmp, node_t *tmp_head)
{
	if (!strcmp(((alias_t*)tmp->data)->name, tmp_head->data)
	&& ((alias_t*)tmp->data)->loop && strcmp(
	((alias_t*)tmp->data)->after[0], ((alias_t*)tmp->data)->name)) {
		shell->state = 1;
		put_err("Alias loop.\n");
		for (tmp = shell->aliases->head; tmp; tmp = tmp->next)
			((alias_t*)tmp->data)->loop = 0;
		return (-1);
	}
	return (0);
}

int	check_alias(shell_t *shell, node_t **head)
{
	node_t *tmp = shell->aliases->head;
	node_t *tmp_head = *head;

	while (tmp) {
		if (!strcmp(((alias_t*)tmp->data)->name, tmp_head->data)
		&& !((alias_t*)tmp->data)->loop) {
			tmp_head = apply_alias(
			(alias_t*)tmp->data, tmp_head, head);
			tmp = shell->aliases->head;
			continue;
		}
		if (check_alias_loop(shell, tmp, tmp_head) == -1)
			return (-1);
		tmp = tmp->next;
	}
	for (tmp = shell->aliases->head; tmp; tmp = tmp->next)
		((alias_t*)tmp->data)->loop = 0;
	return (0);
}
