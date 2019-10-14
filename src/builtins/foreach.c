/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** /src/builtins/foreach.c
*/

#include "main.h"

int error_variable_foreach(char *str)
{
	char **tab = my_str_to_word_array(str, ' ');

	if ((tab[0][0] < 'a' || tab[0][0] > 'z') && (tab[0][0] < 'A' ||
	tab[0][0] > 'Z')) {
		put_err(FOR_BASE);
		put_err(FOR_ERR);
		return (84);
	}
	for (int i = 1; tab[0][i] != '\0'; i++)
		if ((tab[0][i] < 'a' || tab[0][i] > 'z') && (tab[0][i] < 'A' ||
		tab[0][i] > 'Z') && (tab[0][i] < '0' || tab[0][i] > '9')) {
			put_err(FOR_BASE);
			put_err(FOR_ARR);
			return (84);
		}
	if (my_tab_len(tab) > 1) {
		put_err(FOR_PAR);
		return (84);
	}
	return (0);
}

int error_paranthesis_foreach(char **input)
{
	int i = 2;
	int size = 0;

	if (len(input[1]) != 1 || input[1][0] != '(')
		return (-1);
	for (; input[i] != NULL && (len(input[i]) != 1 && input[i][0] != ')');
	i++, size++);
	if (input[i] == NULL)
		return (-1);
	if (input[i + 1] != NULL)
		return (-1);
	return (size);
}

char **error_foreach(char *str)
{
	char **input = my_lexer(str);
	char **result = NULL;
	int size = 0;

	if (my_tab_len(input) < 3) {
		put_err(FOR_FEW);
		return (NULL);
	}
	if (error_variable_foreach(input[0]) == 84)
		return (NULL);
	if ((size = error_paranthesis_foreach(input)) == -1) {
		put_err(FOR_PAR);
		return (NULL);
	}
	result = my_str_to_word_array(input[2], ' ');
	return (result);
}

void create_shell_buffer(shell_t *shell, char **tab, char **var, char *tmp)
{
	for (int i = 0; var[i] != NULL; i++) {
		shell->buffer = concat(shell->buffer, "set ");
		shell->buffer = concat_free(shell->buffer, tab[0]);
		shell->buffer = concat_free(shell->buffer, "=");
		shell->buffer = concat_free(shell->buffer, var[i]);
		shell->buffer = concat_free(shell->buffer, "\n");
		shell->buffer = concat_free(shell->buffer, tmp);
	}
}

void builtin_foreach(shell_t *shell, char **input)
{
	char **var;
	char *tmp = NULL;
	char *str;

	if ((var = error_foreach(input[1])) == NULL) {
		shell->state = 1;
		return;
	}
	put_tty("foreach? ");
	for (; (str = get_next_line(0)) != NULL &&
	my_strcmp(str, "end") != 0;) {
		tmp = concat(tmp, str);
		tmp = concat_free(tmp, "\n");
		free(str);
		put_tty("foreach? ");
	}
	create_shell_buffer(shell, my_str_to_word_array(input[1], ' '),
	var, tmp);
}