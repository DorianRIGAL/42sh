/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** completion.c
*/

#include "term_prototype.h"

char	*get_current_path(ctx_t *ctx, char *tmp)
{
	int i = 0;

	if (!tmp)
		return (NULL);
	tmp[ctx->cursor_pos] = 0;
	for (i = ctx->cursor_pos - 1; i >= 0 && tmp[i] != ' '; i -= 1);
	tmp += i + 1;
	if (tmp[0] == 0)
		return (NULL);
	return (tmp);
}

char	*get_end(char *path)
{
	int i = strlen(path);
	char *tmp = NULL;

	for (; i >= 0 && path[i] != '/'; i -= 1);
	tmp = path + i + 1;
	if (i >= 0)
		path[i] = 0;
	if (tmp[0] == 0)
		return (NULL);
	return (tmp);
}

path_t	*completion_next(ctx_t *ctx, char *path, char *tmp, char **end)
{
	path_t *list = NULL;

	*end = get_end(path);
	if (!(*end)) {
		free(tmp);
		return (NULL);
	}
	if (path == *end)
		list = check_bin(ctx, *end);
	if (!list) {
		if (path == *end)
			path = "./";
		list = check_folder(ctx, path, *end);
	}
	if (!list) {
		free(tmp);
		return (NULL);
	}
	return (list);
}

void	completion(ctx_t *ctx)
{
	char *tmp = from_list_to_array(ctx->list);
	char *path = get_current_path(ctx, tmp);
	char *end = NULL;
	path_t *list = NULL;

	if (!path) {
		free(tmp);
		return;
	}
	list = completion_next(ctx, path, tmp, &end);
	if (!list)
		return;
	path_completion(ctx, end, list);
	free(tmp);
	free_path(list);
}
