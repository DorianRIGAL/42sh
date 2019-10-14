/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** src/builtins/directory.c : Cd builtin.
*/

#include "main.h"

bool builtin_cd_check(shell_t *shell, char *path)
{
	if (path && len(path) >= 256) {
		put_err(path);
		put_err(ERR_LONG_CD);
		shell->state = 1;
		return (false);
	}
	return (true);
}

void builtin_cd_go(shell_t *shell, char *path)
{
	struct stat found_data;
	int res = lstat(path, &found_data);

	if (!builtin_cd_check(shell, path))
		return;
	if (res == 0) {
		if (S_ISDIR(found_data.st_mode)) {
			chdir(path);
		} else {
			put_err(path);
			put_err(": Not a directory.\n");
			shell->state = 1;
		}
	} else {
		put_err(path);
		put_err(": No such file or directory.\n");
		shell->state = 1;
	}
}

void	builtin_apply(shell_t *shell, item_t *actual)
{
	char path_env[4096];

	shell->old = my_strdup(actual->data);
	getcwd(path_env, sizeof(path_env));
	env_add_var(shell, "PWD", path_env);
}

void builtin_cd_do(shell_t *shell, char **i)
{
	item_t *actual = env_get_var(shell, "PWD");

	if (i[1][0] && i[1][0] == '-') {
		if (len(i[1]) == 1 && shell->old) {
			builtin_cd_go(shell, shell->old);
			builtin_apply(shell, actual);
		} else if (len(i[1]) == 1 && !shell->old)
			write(2, ": No such file or directory.\n", 29);
		else
			write(2, "Usage: cd [-plvn][-|<dir>].\n", 28);
	} else if (i[1][0] && i[1][0] != '-') {
		builtin_cd_go(shell, i[1]);
		if (shell->state != 1) {
			builtin_apply(shell, actual);
		}
	}
}

void builtin_cd(shell_t *shell, char **input)
{
	item_t *std_home = env_get_var(shell, "HOME");
	item_t *actual = env_get_var(shell, "PWD");

	if (!input[1]) {
		if (!std_home || !len(std_home->data)) {
			put_err("cd: No home directory.\n");
			shell->state = 1;
			return;
		}
		shell->old = my_strdup(actual->data);
		builtin_cd_go(shell, std_home->data);
		return;
	}
	if (input[2]) {
		put_err("cd: Too many arguments.\n");
		shell->state = 1;
		return;
	}
	builtin_cd_do(shell, input);
}