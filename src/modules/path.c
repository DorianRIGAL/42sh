/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** src/modules/path.c : Path Handling
*/

#include "main.h"

void path_manual_init(shell_t *shell)
{
	char p[] = "/usr/local/sbin:/usr/local/bin/:/usr/sbin:/usr/bin:/bin";
	char pwd[2048];

	if (!getcwd(pwd, sizeof(pwd))) {
		perror("mysh: ");
		exit(84);
		return;
	}
	env_add_var(shell, "PATH", p);
	env_add_var(shell, "PWD", pwd);
	env_add_var(shell, "SHELL", "/bin/bash");
	env_add_var(shell, "_", "./mysh");
	env_add_var(shell, "LOGNAME", "usr");
	env_add_var(shell, "HOME", "");
}

char *path_prepare(shell_t *shell)
{
	item_t *home_item = env_get_var(shell, "HOME");
	char *path = env_get_var(shell, "PWD")->data;
	char *home = home_item ? home_item->data : "";
	char *res = malloc(sizeof(char) * (len(path) - len(home) + 2));
	char *final;

	if (!res)
		return ("");
	if (len(path) > len(home) - 1 && len(home) > 0) {
		my_strcpy(res, path + (len(home)));
		final = concat("~", res);
	} else {
		free(res);
		return (path);
	}
	free(res);
	return (final);
}

void path_free(char *a, char *b, char *c, char *d)
{
	if (a)
		free(a);
	if (b)
		free(b);
	if (c)
		free(c);
	if (d)
		free(d);
}

void path_show(shell_t *shell)
{
	item_t *name = env_get_var(shell, "LOGNAME");
	char *path = path_prepare(shell);
	char *name_color = NULL;
	char *name_end = NULL;
	char *path_color = concat("\e[1m\e[34m", path);
	char *path_end = concat(path_color, "\e[0m");

	if (!isatty(0) || shell->script_fd || shell->buffer)
		return;
	shell->context->path_len = -30;
	if (name) {
		name_color = concat("\e[5m\e[1m\e[32m", name->data);
		name_end = concat(name_color, "\e[0m");
		shell->context->path_len += put_str(name_end);
		shell->context->path_len += put_str(":");
	}
	if (path)
		shell->context->path_len += put_str(path_end);
	shell->context->path_len += put_str("> ");
	path_free(name_color, name_end, path_color, path_end);
}

void path_update(shell_t *shell)
{
	char path[4096];

	getcwd(path, sizeof(path));
	env_add_var(shell, "PWD", path);
	if (shell->buffer)
		return;
	path_show(shell);
}