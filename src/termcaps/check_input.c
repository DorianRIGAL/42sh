/*
** EPITECH PROJECT, 2018
** 42.sh
** File description:
** check_input
*/

#include "term_prototype.h"
#include "termcaps.h"

tab_t tab[9] = {
	{8, &backspace},
	{127, &backspace},
	{27, &redirection},
	{1, &go_begining},
	{5, &go_end},
	{12, &clear_screen},
	{11, &copy},
	{25, &paste},
	{9, &tabulation}
};

void	copy(ctx_t *ctx, UNUSED char buffer[4])
{
	term_node_t *tmp = ctx->list->head;

	for (int i = 0; i < ctx->cursor_pos; i += 1, tmp = tmp->next);
	if (tmp) {
		free_node(ctx->save);
		ctx->save = tmp;
		ctx->list->size -= get_list_len(tmp);
	}
	if (ctx->cursor_pos == 0)
		ctx->list->head = NULL;
	else if (tmp && tmp->prev) {
		tmp->prev->next = NULL;
		tmp->prev = NULL;
	}
}

void	paste_next(ctx_t *ctx, term_node_t *tmp,
term_node_t *tmp2, term_node_t *tmp3)
{
	if (ctx->cursor_pos - get_list_len(ctx->save) == 0) {
		ctx->list->head = tmp;
		tmp3->next = tmp2;
		tmp2->prev = tmp3;
		return;
	}
	tmp3->next = tmp2->next;
	if (tmp3->next)
		tmp3->next->prev = tmp3;
	tmp->prev = tmp2;
	tmp2->next = tmp;
}

void	paste(ctx_t *ctx, UNUSED char buffer[4])
{
	term_node_t *tmp = cp_list(ctx->save);
	term_node_t *tmp2 = ctx->list->head;
	term_node_t *tmp3 = tmp;

	if (!tmp)
		return;
	for (; tmp3->next; tmp3 = tmp3->next);
	for (int i = 1; tmp2 && i < ctx->cursor_pos; i += 1, tmp2 = tmp2->next);
	ctx->list->size += get_list_len(tmp);
	ctx->cursor_pos += get_list_len(tmp);
	if (!ctx->list->head) {
		ctx->list->head = tmp;
		return;
	}
	paste_next(ctx, tmp, tmp2, tmp3);
}

void	redirection(ctx_t *ctx, char buffer[4])
{
	if (buffer[2] <= 68 && buffer[2] >= 65)
		arrow(ctx, buffer);
	if (buffer[2] == 51)
		supression(ctx);
}

void	check_input(char buffer[4], ctx_t *ctx, int *lock)
{
	if (buffer[0] == 4 && ctx->list->head == NULL)
		*lock = 0;
	if ((buffer[0] >= 32 && buffer[0] <= 126)) {
		add_node(ctx->list, buffer[0], ctx->cursor_pos - 1);
		ctx->cursor_pos += 1;
		return;
	}
	for (int i = 0; i < 9; i += 1) {
		if (tab[i].key == buffer[0])
			tab[i].ptr(ctx, buffer);
	}
}
