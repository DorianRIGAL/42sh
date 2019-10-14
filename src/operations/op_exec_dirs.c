/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** src/operations/op_exec_base.c
*/

#include "main.h"

void op_exec_right(UNUSED int in, token_t *token, shell_t *shell)
{
	int file = -1;

	str_remove_char(token->right->cmd, ' ');
	file = open(token->right->cmd, O_CREAT | O_RDWR | O_TRUNC, 00664);
	set_pipes(0, file, false);
	token_exec(token->left, 0, file, shell);
	set_pipes(0, file, true);
}

void op_exec_left(UNUSED int in, token_t *token, shell_t *shell)
{
	int file = -1;

	str_remove_char(token->right->cmd, ' ');
	file = open(token->right->cmd, O_RDONLY, 00664);
	if (file == -1) {
		put_err(token->right->cmd);
		if (errno == 13)
			put_err(": Permission denied.\n");
		if (errno == 2)
			put_err(": No such file or directory.\n");
	} else {
		set_pipes(file, 1, false);
		token_exec(token->left, file, 1, shell);
		set_pipes(file, 1, true);
	}
}

void op_exec_dright(UNUSED int in, token_t *token, shell_t *shell)
{
	int file = -1;

	str_remove_char(token->right->cmd, ' ');
	file = open(token->right->cmd, O_CREAT | O_RDWR | O_APPEND, 00664);
	set_pipes(0, file, false);
	token_exec(token->left, 0, file, shell);
	set_pipes(0, file, true);
}

void op_exec_dleft(int in, token_t *token, shell_t *shell)
{
	char *path = token->right->cmd;
	int fd = open("./", __O_TMPFILE | O_RDWR);
	int du = dup(0);
	char *str = NULL;

	str_remove_char(path, ' ');
	put_tty("? ");
	str = get_next_line(0);
	while (str && my_strcmp(str, path)) {
		put_tty("? ");
		write(fd, concat(str, "\n"), len(str) + 1);
		str = get_next_line(0);
	}
	lseek(fd, 0, SEEK_SET);
	dup2(fd, 0);
	if (token->left)
		parse(shell, token->left->cmd, fd, in);
	free(path);
	dup2(du, 0);
	close(fd);
}