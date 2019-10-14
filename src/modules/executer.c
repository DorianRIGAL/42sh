/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** src/modules/executer.c
*/

#include "main.h"

static const op_funcs_t operations[] = {
	{OP_COLON, &op_exec_colon},
	{OP_PIPE, &op_exec_pipe},
	{OP_RIGHT, &op_exec_right},
	{OP_LEFT, &op_exec_left},
	{OP_DRIGHT, &op_exec_dright},
	{OP_DLEFT, &op_exec_dleft},
	{OP_AND, &op_exec_and},
	{OP_OR, &op_exec_or},
	{OP_NULL, NULL},
};

void type_exec(token_t *token, int inc, shell_t *shell)
{
	for (int i = 0; operations[i].func; i++) {
		if (operations[i].type == token->op)
			operations[i].func(inc, token, shell);
	}
}

void token_exec(token_t *token, int fdin, int fdout, shell_t *shell)
{
	if (!token)
		return;
	if (token->type)
		type_exec(token, fdout, shell);
	else
		parse(shell, token->cmd, fdin, fdout);
}

void executer(shell_t *shell)
{
	token_t *root = shell->root;

	token_exec(root, 0, 1, shell);
}