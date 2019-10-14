/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** src/utils/cutter.c
*/

#include "main.h"

op_struct_t ope_tab[] = {
	{"<<", '}'},
	{">>", '{'},
	{"||", 'O'},
	{"&&", 'A'},
	{NULL, 0}
};

char	detect_op(char *str, int i)
{
	for (int ct = 0; ope_tab[ct].str; ct++) {
		if (str[i] == ope_tab[ct].str[1] && str[i - 1] ==
		ope_tab[ct].str[0]) {
			str[i - 1] = ' ';
			return (ope_tab[ct].c);
		}
	}
	if (str[i] == OP_PIPE || str[i] == OP_RIGHT || str[i] == OP_LEFT)
		return (str[i]);
	return (0);
}

int	match_next_quote(char *str, int i)
{
	bool quote = false;
	bool dquote = false;

	if (str[i] == 39) {
		quote = !quote;
		i--;
	} else if (str[i] == '"') {
		dquote = !dquote;
		i--;
	}
	for (; i >= 0 && (quote || dquote); i--) {
		if (str[i] == 39)
			quote = !quote;
		if (str[i] == '"')
			dquote = !dquote;
	}
	return (i);
}

void cut_replace(cutted_t *cutted, char *str)
{
	int trig = 0;

	cutted->type = OP_NULL;
	for (int i = len(str); i >= 0; i--) {
		i = match_next_quote(str, i);
		if (i < 0)
			break;
		if ((str[i] == '>' || str[i] == '|' || str[i] == '<' ||
		str[i] == ';' || str[i] == '&') && !trig) {
			trig = 1;
		}
		if (str[i] == ')' && trig == 0) {
			str[i] = ' ';
			trig = 2;
		}
		else if (str[i] == '(' && trig == 2) {
			str[i] = ' ';
			trig = 0;
		}
	}
}

char	**semicolon_detector(int *i, cutted_t *cutted, int *cnt, char *str)
{
	if (str[*i] == ')')
		*cnt += 1;
	else if (str[*i] == '(')
		*cnt -= 1;
	if (str[*i] == ';' && *cnt == 0) {
		cutted->type = OP_COLON;
		return (my_strcut_at(str, *i));
	}
	return (NULL);
}

cutted_t *cut_sides(char *str)
{
	cutted_t *cutted = malloc(sizeof(cutted_t));
	char **sides = NULL;
	static int cnt = 0;

	if (!str || len(str) == 0)
		return (NULL);
	cut_replace(cutted, str);
	for (int i = len(str); i >= 0 && !sides; i--) {
		if ((i = match_next_quote(str, i)) < 0)
			break;
		sides = semicolon_detector(&i, cutted, &cnt, str);
	}
	for (int i = len(str); i > 0 && !sides; i--) {
		if ((i = match_next_quote(str, i)) < 0)
			break;
		if ((cutted->type = detect_op(str, i)))
			sides = my_strcut_at(str, i);
	}
	cutted->sides = sides;
	return (cutted);
}