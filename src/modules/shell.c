/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Mysh INIT.
*/

#include "main.h"
#include "termcaps.h"

void state_handler(shell_t *shell, char *input)
{
	if (shell->script_fd && input)
		return;
	else if (shell->script_fd && !input) {
		shell->quit = 1;
		return;
	}
	if (!input && isatty(0))
		main_exit(shell);
	else if (!input)
		shell->quit = 1;
}

void script_try_open(shell_t *x, char **args)
{
	int fd;

	if (!args)
		return;
	fd = open(args[1], O_RDONLY);
	if (fd < 0) {
		put_err("err\n");
		exit(84);
	}
	x->script_fd = fd;
	for (int i = 2; args[i]; i++)
		builtin_set_add_var(x, my_str_nbr(i - 1), my_strdup(args[i]));
}

bool buffer_handler(shell_t *shell, char **input)
{
	if (!shell->buffer) {
		return (false);
	} else if (!shell->buffer[0]) {
		free(shell->buffer);
		shell->buffer = NULL;
		return (false);
	}
	*input = pull_next_line(&shell->buffer);
	return (true);
}

void input_handler(shell_t *box, char **input)
{
	if (buffer_handler(box, input))
		return;
	if (box->script_fd) {
		*input = get_next_line(box->script_fd);
		while (*input && input[0][0] == '#')
			*input = get_next_line(box->script_fd);
		return;
	}
	if (!isatty(0)) {
		*input = get_next_line(0);
		return;
	}
	if (init_term(&box->context->term, env_get(box)) == -1)
		box->termcaps_initialized = false;
	if (box->termcaps_initialized && isatty(0))
		*input = termcaps(box);
	else
		*input = get_next_line(0);
	if (reset_term(&box->context->term) == -1)
		box->termcaps_initialized = false;
}

int shell_init(shell_t *shell, char **args)
{
	char *input = NULL;
	int state = 0;

	script_try_open(shell, args);
	while (!shell->quit) {
		path_update(shell);
		input_handler(shell, &input);
		state_handler(shell, input);
		if (input && error_red(my_lexer(input), shell) != -1) {
			input = add_quote_func(input);
			shell->root = token_parser(NULL, input, shell);
			executer(shell);
		}
		free(input);
	}
	state = shell->state;
	free_all(shell, input);
	return (state);
}