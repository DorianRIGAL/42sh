/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** history
*/

#include "term_prototype.h"

void	manage_history(ctx_t *ctx)
{
	term_node_t *tmp = ctx->list->head;

	if (ctx->list->next != NULL) {
		cut_list(ctx->list);
		ctx->list->head = ctx->tmp;
		ctx->list->size = get_list_len(ctx->list->head);
		for (; ctx->list->next; ctx->list = ctx->list->next);
		ctx->list = add_list(ctx->list);
		ctx->list->head = tmp;
		ctx->list->size = get_list_len(ctx->list->head);
	}
	if (ctx->list->prev
	&& cmp_list(ctx->list->head, ctx->list->prev->head)) {
		ctx->list = ctx->list->prev;
		cut_list(ctx->list);
	}
}
