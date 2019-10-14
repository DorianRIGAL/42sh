/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/conditionals.c
*/

#include "main.h"
#include "conditionals.h"

conditional_box_t conditions[] = {
	{">", 0, &condition_size},
	{"<", 1, &condition_size},
	{">=", 2, &condition_size},
	{"<=", 3, &condition_size},
	{"==", 0, &condition_equals},
	{"!=", 1, &condition_equals},
	{NULL, -1, NULL},
};

void builtin_if_execute(shell_t *shell, char *cmd)
{
	token_t *root = shell->root;

	parse(shell, cmd, 0, 0);
	shell->root = root;
}

void condition_size(shell_t *shell, char **input, int data, char *cmd)
{
	if (!shell || !input || !input[0] || !input[1] || !input[1] || !cmd)
		return;
	if (!my_str_isnum(input[0]) || !my_str_isnum(input[2])) {
		put_str(IF_EXPRESSION);
		shell->state = 1;
		return;
	}
	if ((!data && my_getnbr(input[0]) > my_getnbr(input[2])) ||
	(data == 1 && my_getnbr(input[0]) < my_getnbr(input[2])) ||
	(data == 2 && (my_getnbr(input[0]) > my_getnbr(input[2]) ||
	my_getnbr(input[0]) == my_getnbr(input[2]))) ||
	(data == 3 && (my_getnbr(input[0]) < my_getnbr(input[2]) ||
	my_getnbr(input[0]) == my_getnbr(input[2]))))
		builtin_if_execute(shell, cmd);
}

void condition_equals(shell_t *shell, char **input, int data, char *cmd)
{
	if (!shell || !input || !input[0] || !input[1] || !input[1] || !cmd)
		return;
	if (!data && !my_strcmp(input[0], input[2]))
		builtin_if_execute(shell, cmd);
	else if (data && my_strcmp(input[0], input[2]))
		builtin_if_execute(shell, cmd);
}

void builtin_if_check(shell_t *x, char **str)
{
	char **box = NULL;

	box = my_str_to_word_array(str[0], ' ');
	if (!box || my_is_clear(box[0]))
		return;
	if (my_tab_len(box) == 1 && !my_str_isnum(box[0])) {
		put_str(IF_EXPRESSION);
		x->state = 1;
		return;
	}
	if (!str[1] || !str[1][0]) {
		put_str(IF_EMPTY);
		x->state = 1;
		return;
	}
	for (int i = 0; conditions[i].str && box[0] && box[1]; i++) {
		if (!my_strcmp(conditions[i].str, box[1]))
			conditions[i].func(x, box, conditions[i].data, str[1]);
	}
}

void builtin_if(shell_t *shell, char **input)
{
	int point = 0;
	char **sides = NULL;

	if (!input || !input[0] || !input[1])
		return;
	point = my_str_where_contains(input[1], ')');
	if (!point) {
		shell->state = 1;
		put_str(IF_TOO_FEW);
		return;
	}
	sides = my_strcut_at(input[1], point);
	if (!sides || !sides[0])
		return;
	str_remove_char(sides[0], '(');
	str_remove_char(sides[0], ')');
	builtin_if_check(shell, sides);
}