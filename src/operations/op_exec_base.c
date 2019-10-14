/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** src/operations/op_exec_base.c
*/

#include "main.h"

void	put_tty(char *str)
{
	if (isatty(0))
		put_str(str);
}

void op_exec_colon(int inc, token_t *token, shell_t *shell)
{
	token_exec(token->left, 0, inc, shell);
	token_exec(token->right, 0, inc, shell);
}

void op_exec_and(int inc, token_t *token, shell_t *shell)
{
	token_exec(token->left, 0, inc, shell);
	if (!shell->state)
		token_exec(token->right, 0, inc, shell);
}

void op_exec_or(int inc, token_t *token, shell_t *shell)
{
	token_exec(token->left, 0, inc, shell);
	if (shell->state)
		token_exec(token->right, 0, inc, shell);
	else
		shell->state = 1;
}

void op_exec_pipe(int UNUSED inc, token_t *token, shell_t *shell)
{
	int pip[2];
	int ret = 0;
	int du = dup(1);
	int duu = dup(0);

	if (du == - 1 || duu == -1)
		exit(84);
	pipe(pip);
	if (!fork()) {
		set_pipes_receiver(pip[0], pip[1], 1);
		token_exec(token->left, 1, pip[1], shell);
		exit(0);
	} else {
		set_pipes_receiver(pip[1], pip[0], 0);
		token_exec(token->right, pip[0], 1, shell);
		dup2(duu, 0);
		dup2(du, 1);
		wait(&ret);
	}
}