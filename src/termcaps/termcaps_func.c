/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** term_func
*/

#include "term_prototype.h"
#include "termcaps.h"

void    supression(ctx_t *ctx)
{
	if (ctx->cursor_pos < ctx->list->size)
		delete_node_term(ctx->list, ctx->cursor_pos);
}

void    backspace(ctx_t *ctx, UNUSED char buffer[4])
{
	if (ctx->cursor_pos - 1 >= 0) {
		delete_node_term(ctx->list, ctx->cursor_pos - 1);
		ctx->cursor_pos -= 1;
	}
}

void    go_end(ctx_t *ctx, UNUSED char buffer[4])
{
	ctx->cursor_pos = ctx->list->size;
}

void    go_begining(ctx_t *ctx, UNUSED char buffer[4])
{
	ctx->cursor_pos = 0;
}

void    clear_screen(UNUSED ctx_t *ctx, UNUSED char buffer[4])
{
	exec_term("cl");
}
