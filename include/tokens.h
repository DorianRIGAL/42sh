/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** include/tokens.h
*/

#ifndef TOKENS_H_
	#define TOKENS_H_

	typedef enum {
		OP_NULL = 0,
		OP_COLON = ';',
		OP_PIPE = '|',
		OP_RIGHT = '>',
		OP_LEFT = '<',
		OP_DRIGHT = '{',
		OP_DLEFT = '}',
		OP_OR = 'O',
		OP_AND = 'A'
	} op_type_t;

	typedef enum {
		NODE_CMD,
		NODE_OP,
	} token_type_t;

	typedef struct cutted {
		op_type_t type;
		char **sides;
	} cutted_t;

	typedef struct token {
		token_type_t type;
		op_type_t op;
		char *cmd;
		struct token *right;
		struct token *left;
		struct token *parent;
	} token_t;

	token_t *token_init(token_t*, char*);
	cutted_t *cut_sides(char*);
#endif