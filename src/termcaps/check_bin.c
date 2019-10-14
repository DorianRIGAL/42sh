/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** check_bin
*/

#include "term_prototype.h"

path_t	*check_bin(ctx_t *ctx, char *end)
{
	unsigned int i = len(end);
	path_t *list = NULL;
	path_t *tmp = ctx->bin;

	for (; tmp; tmp = tmp->next) {
		if (strncmp(tmp->path, end, i) == 0 && strlen(tmp->path) >= i)
			list = add_path(list, strdup(tmp->path));
	}
	return (list);
}

path_t	*check_folder(UNUSED ctx_t *ctx, char *path, char *end)
{
	unsigned int i = len(end);
	path_t *list = NULL;
	DIR *fd = opendir(path);
	struct dirent *dir = NULL;

	if (!fd)
		return (NULL);
	dir = readdir(fd);
	while (dir) {
		if (strncmp(dir->d_name, end, i) == 0
		&& strlen(dir->d_name) >= i)
			list = add_path(list, strdup(dir->d_name));
		dir = readdir(fd);
	}
	closedir(fd);
	return (list);
}
