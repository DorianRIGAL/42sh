/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** arrow
*/

#include "term_prototype.h"
#include "termcaps.h"

void	move_up(ctx_t *ctx)
{
	if (ctx->tmp) {
		free_node(ctx->list->head);
		ctx->list->head = ctx->tmp;
		ctx->tmp = NULL;
	}
	ctx->list->size = get_list_len(ctx->list->head);
	ctx->list = ctx->list->prev;
	ctx->cursor_pos = ctx->list->size;
	if (!ctx->tmp && ctx->list->next != NULL)
		ctx->tmp = cp_list(ctx->list->head);
}

void	move_down(ctx_t *ctx)
{
	if (ctx->tmp) {
		free_node(ctx->list->head);
		ctx->list->head = ctx->tmp;
		ctx->tmp = NULL;
	}
	ctx->list->size = get_list_len(ctx->list->head);
	ctx->list = ctx->list->next;
	ctx->cursor_pos = ctx->list->size;
	if (!ctx->tmp && ctx->list->next != NULL)
		ctx->tmp = cp_list(ctx->list->head);
}

void	check_history(ctx_t *ctx, char key)
{
	if (key == 65 && ctx->list->prev)
		move_up(ctx);
	if (key == 66 && ctx->list->next)
		move_down(ctx);
}

void	arrow(ctx_t *ctx, char buffer[3])
{
	if (buffer[2] == 67 && ctx->cursor_pos < ctx->list->size)
		ctx->cursor_pos += 1;
	if (buffer[2] == 68 && ctx->cursor_pos > 0)
		ctx->cursor_pos -= 1;
	if (buffer[2] == 65 || buffer[2] == 66)
		check_history(ctx, buffer[2]);
}
