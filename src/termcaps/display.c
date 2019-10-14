/*
** EPITECH PROJECT, 2018
** 42.sh
** File description:
** display.c
*/

#include "termcaps.h"
#include "main.h"

void	move_cursor(ctx_t *ctx)
{
	int tmp = 0;

	ctx->pos_relative[0] = (ctx->cursor_pos + ctx->path_len) % ctx->col;
	ctx->pos_relative[1] = (ctx->cursor_pos + ctx->path_len) / ctx->col;
	ctx->line_save = ctx->cursor_pos + ctx->path_len;
	tmp = (ctx->path_len + ctx->list->size - 1) / (ctx->col);
	for (int i = 0; i < tmp; i += 1)
		exec_term("up");
	for (int i = 0; i < ctx->pos_relative[1]; i += 1)
		exec_term("do");
	exec_term("cr");
	for (int i = 0; i < ctx->pos_relative[0]; i += 1)
		exec_term("nd");
}

void	display(shell_t *shell)
{
	ctx_t *ctx = shell->context;

	for (int i = 0; i < ctx->line_save / ctx->col; i += 1)
		exec_term("up");
	exec_term("cr");
	exec_term("cd");
	path_show(shell);
	print_node(ctx->list);
	move_cursor(ctx);
}
