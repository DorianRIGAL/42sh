/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** src/modules/tokenize.c
*/

#include "main.h"

token_t *token_init(token_t *parent, char *data)
{
	token_t *token = malloc(sizeof(token_t));

	token->type = NODE_CMD;
	token->op = OP_NULL;
	token->cmd = data;
	token->right = NULL;
	token->left = NULL;
	token->parent = parent;
	return (token);
}

token_t *token_parser(token_t *parent, char *cmd, shell_t *shell)
{
	token_t *tok = token_init(parent, NULL);
	cutted_t *cutted = cut_sides(cmd);

	if (!cutted || !cutted->type) {
		tok->cmd = my_strdup(cmd);
	} else {
		tok->type = NODE_OP;
		tok->op = cutted->type;
		if (!(tok->right = token_parser(tok,
		my_strdup(cutted->sides[1]), shell))
		|| !(tok->left = token_parser(tok,
		my_strdup(cutted->sides[0]), shell)))
			return (NULL);
		free(cutted->sides[0]);
		free(cutted->sides[1]);
		free(cutted);
	}
	return (tok);
}
