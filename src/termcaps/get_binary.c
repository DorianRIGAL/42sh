/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** get_binary
*/

#include "term_prototype.h"

void	get_bin_in_folder(ctx_t *ctx, char *path)
{
	DIR *fd;
	struct dirent *dir;

	fd = opendir(path);
	if (fd == NULL)
		return;
	dir = readdir(fd);
	while (dir) {
		if (dir->d_name[0] != '.')
			ctx->bin = add_path(ctx->bin, strdup(dir->d_name));
		dir = readdir(fd);
	}
	closedir(fd);
}

void	get_binary(ctx_t *ctx, char **env)
{
	char *path_array = get_env("PATH", env);
	char **path_tab = my_str_to_word_array(path_array, ':');

	for (int i = 0; path_tab[i]; i += 1) {
		get_bin_in_folder(ctx, path_tab[i]);
		free(path_tab[i]);
	}
	free(path_tab);
	free(path_array);
}
