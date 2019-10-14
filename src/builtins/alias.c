/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** alias
*/

#include "main.h"

void	add_alias(shell_t *shell, char *name, char **after, int len)
{
	alias_t *new = malloc(sizeof(*new));

	if (!new)
		return;
	if (!strcmp("alias", name)) {
		put_err("alias: Too dangerous to alias that.\n");
		shell->state = 1;
		return;
	}
	new->name = strdup(name);
	new->after = malloc(sizeof(char*) * len);
	if (!new->after)
		return;
	for (int i = 0; after[i]; i += 1)
		new->after[i] = strdup(after[i]);
	new->after[len - 1] = NULL;
	new->loop = 0;
	add_node_sort(shell->aliases, new);
}

void	change_alias(alias_t *alias, char **after, int len)
{
	block_free(alias->after);
	alias->after = malloc(sizeof(char*) * len);
	if (!alias->after)
		return;
	for (int i = 0; after[i]; i += 1)
		alias->after[i] = strdup(after[i]);
	alias->after[len - 1] = NULL;
}

void	print_alias(node_t *alias)
{
	alias_t *tmp = NULL;

	for (; alias; alias = alias->next) {
		tmp = alias->data;
		put_str(tmp->name);
		my_putchar('\t');
		if (my_tab_len(tmp->after) > 1)
			my_putchar('(');
		for (int i = 0; tmp->after[i]; i += 1) {
			put_str(tmp->after[i]);
			print_space_alias(tmp->after[i + 1]);
		}
		if (my_tab_len(tmp->after) > 1)
			my_putchar(')');
		my_putchar('\n');
	}
}

void	print_one_alias(alias_t *alias)
{
	if (!alias)
		return;
	for (int i = 0; alias->after[i]; i += 1) {
		put_str(alias->after[i]);
		my_putchar(alias->after[i + 1] ? ' ' : 0);
	}
	my_putchar('\n');
}

void	builtin_alias(shell_t *shell, char **input)
{
	int len = my_tab_len(input);
	alias_t *tmp = NULL;

	shell->state = 0;
	if (len == 1) {
		print_alias(shell->aliases->head);
		return;
	}
	tmp = get_node(shell->aliases, input[1]);
	if (len == 2)
		print_one_alias(tmp);
	else if (!tmp) {
		add_alias(shell, input[1], input + 2, len - 1);
	} else
		change_alias(tmp, input + 2, len - 1);
}
