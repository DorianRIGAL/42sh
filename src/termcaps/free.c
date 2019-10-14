/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** free
*/

#include "term_prototype.h"

void	free_path(path_t *path)
{
	path_t *tmp = NULL;

	for (; path; tmp = path, path = path->next) {
		if (tmp) {
			free(tmp->path);
			free(tmp);
		}
	}
	if (tmp) {
		free(tmp->path);
		free(tmp);
	}
}

void	free_node(term_node_t *node)
{
	if (!node)
		return;
	if (!node->next) {
		free(node);
		return;
	}
	for (node = node->next; node && node->next; node = node->next)
		free(node->prev);
	free(node->prev);
	free(node);
}

void	free_all_term(ctx_t ctx)
{
	term_list_t *tmp = ctx.list;
	term_list_t *tmp2 = NULL;

	for (;tmp && tmp->prev; tmp = tmp->prev);
	for (; tmp; tmp2 = tmp, tmp = tmp->next) {
		free_node(tmp->head);
		if (tmp2)
			free(tmp2);
	}
	if (tmp2)
		free(tmp2);
	free_node(ctx.tmp);
	free_node(ctx.save);
	free_path(ctx.bin);
}
