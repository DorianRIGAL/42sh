/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** src/modules/free.c : Free allocated memory.
*/

#include "main.h"

void block_free(char **block)
{
	if (!block)
		return;
	for (int i = 0; block[i]; i++)
		free(block[i]);
	if (block)
		free(block);
}

void environment_free_node(node_t *node, item_t *item)
{
	free(item->var);
	free(item->data);
	free(item);
	free(node);
}

void environment_free(shell_t *shell)
{
	list_t *list = shell->env_list;
	node_t *node = NULL;
	item_t *obj = NULL;

	while (list->head) {
		node = list->head;
		list->head = node->next;
		obj = node->data;
		free(obj->var);
		free(obj->data);
		free(obj);
		free(node);
	}
	free(list);
}

void free_up(char *new_paths, char **env, char **std_paths)
{
	if (new_paths)
		free(new_paths);
	block_free(std_paths);
	block_free(env);
}

void free_all(shell_t *shell, UNUSED char *input)
{
	termcaps_end(shell);
	environment_free(shell);
	alias_free_all(shell);
	vars_free_all(shell);
	free(shell);
}