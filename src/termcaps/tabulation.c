/*
** EPITECH PROJECT, 2018
** tabulation
** File description:
** 42sh
*/

#include "term_prototype.h"

void	search_in_history(ctx_t *ctx)
{
	term_list_t *tmp = ctx->list;

	for (; tmp && tmp->next; tmp = tmp->next);
	for (; tmp; tmp = tmp->prev) {
		if (tmp == ctx->list)
			continue;
		if (cmp_begin_list(ctx->list->head->next, tmp->head))
			break;
	}
	if (!tmp)
		return;
	free_node(ctx->list->head);
	ctx->list->head = cp_list(tmp->head);
	ctx->list->size = get_list_len(ctx->list->head);
	ctx->cursor_pos = ctx->list->size;
}

void	tabulation(ctx_t *ctx, UNUSED char buffer[3])
{
	if (ctx->list->head && ctx->list->head->data == '!'
	&& ctx->list->head->next)
		search_in_history(ctx);
	completion(ctx);
}
