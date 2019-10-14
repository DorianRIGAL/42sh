/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** start exec
*/

#include "term_prototype.h"
#include "termcaps.h"

char	*start_exec(ctx_t *ctx)
{
	char *tmp = NULL;

	if (ctx->list->head && ctx->list->head->data == '!'
	&& ctx->list->head->next)
		search_in_history(ctx);
	tmp = from_list_to_array(ctx->list);
	my_putchar('\n');
	ctx->cursor_pos = 0;
	ctx->line_save = 0;
	manage_history(ctx);
	ctx->list = add_list(ctx->list);
	ctx->tmp = NULL;
	return (tmp);
}
