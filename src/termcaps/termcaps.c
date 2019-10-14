/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/


#include "main.h"
#include "termcaps.h"

void	update_term(shell_t *shell)
{
	item_t *name_term = NULL;

	name_term = env_get_var(shell, "TERM");
	if (!name_term)
		return;
	if (tgetent(NULL, name_term->data) == -1)
		return;
}

bool	termcaps_init(shell_t *shell, char **env)
{
	ctx_t *ctx = malloc(sizeof(ctx_t));

	shell->context = ctx;
	ctx->list = add_list(NULL);
	ctx->cursor_pos = 0;
	ctx->pos_relative[1] = 0;
	ctx->pos_relative[0] = 0;
	ctx->line_save = 0;
	ctx->col = 0;
	ctx->save = NULL;
	ctx->tmp = NULL;
	ctx->bin = NULL;
	get_binary(ctx, env);
	if (!ctx->list)
		return (false);
	block_free(env);
	return (true);
}

void	termcaps_end(shell_t *shell)
{
	free_all_term(*shell->context);
	free(shell->context);
}

char	*termcaps(shell_t *shell)
{
	ctx_t *ctx = shell->context;
	char buffer[4];
	int lock = 1;
	char *ret = NULL;

	while (lock) {
		read(0, buffer, 4);
		check_input(buffer, ctx, &lock);
		update_term(shell);
		ctx->col = tgetnum("co");
		display(shell);
		if (buffer[0] == 10) {
			ret = start_exec(ctx);
			break;
		}
	}
	return (ret);
}
