/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** path_completion
*/

#include "term_prototype.h"

void	path_completion_add(ctx_t *ctx)
{
	char *tmp = from_list_to_array(ctx->list);
	char *path = get_current_path(ctx, tmp);
	DIR *fd = NULL;

	if (access(path, F_OK) == -1) {
		free(tmp);
		return;
	}
	fd = opendir(path);
	if (!fd)
		add_node(ctx->list, ' ', ctx->cursor_pos - 1);
	else {
		add_node(ctx->list, '/', ctx->cursor_pos - 1);
		closedir(fd);
	}
	ctx->cursor_pos += 1;
	free(tmp);
}

void	cut_path(char *str, char *path)
{
	for (int i = 0; str[i]; i += 1) {
		if (str[i] != path[i]) {
			str[i] = 0;
			break;
		}
	}
}

void	path_completion(ctx_t *ctx, char *end, path_t *list)
{
	char *str = list->path;
	int j = 0;

	for (list = list->next; list; list = list->next)
		cut_path(str, list->path);
	for (j = 0; str[j] && end[j] && str[j] == end[j]; j += 1);
	str += j;
	for (int i = 0; str[i]; i += 1) {
		add_node(ctx->list, str[i], ctx->cursor_pos - 1);
		ctx->cursor_pos += 1;
	}
	path_completion_add(ctx);
}
