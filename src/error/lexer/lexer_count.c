/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** get_semicolon.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "error.h"
#include "leolib.h"

int is_if_fill(char *str)
{
	if (*str == 'i' && *(str+ 1) == 'f')
		return (1);
	return (0);
}

int is_if(char *str, int i)
{
	if (str && str[i] != '\0' && str[i] == 'i' &&
	str[i + 1] != '\0' && str[i + 1] == 'f')
		return (1);
	return (0);
}

int count_quote_and_regular(char *to_lex, int *i, int count)
{
	int pass = 0;

	if ((*i = shift_quote(to_lex, *i, &pass)) == -1)
		return (-1);
	if (pass > 0) {
		count += 1;
		*i += 1;
		pass = 0;
	}
	for (int passed = 0; to_lex[*i] != '\0' && is_if(to_lex, *i) == 0 &&
	separator(to_lex[*i]) == -1; *i += 1, passed = 1) {
		count += (passed == 0 && pass == 0) ? 1 : 0;
		if ((*i = shift_quote(to_lex, *i, &pass)) == -1)
			return (-1);
	}
	if (is_if(to_lex, *i) == 1) {
		count += 1;
		*i = *i + 2;
	}
	return (count);
}

int count_separator(char *to_lex, int *i, int count)
{
	int sep_1 = -1;
	int sep_2 = -1;

	if (to_lex[*i] != '\0' && (sep_1 = separator(to_lex[*i])) != -1 &&
	sep_1 > 2 && to_lex[*i + 1] != '\0' &&
	(sep_2 = separator(to_lex[*i + 1])) == sep_1) {
		*i += 1;
		count += 1;
	} else if (to_lex[*i] != '\0' && ((sep_1 == 1 || sep_1 == 2) ||
	(sep_1 != -1 && (to_lex[*i + 1] == '\0' || sep_2 != sep_1)))) {
		count += 1;
	}
	return (count);
}

int count_semicolon(char *to_lex)
{
	int lenght = len(to_lex);
	int count = 0;

	for (int i = 0; i < lenght; i += 1) {
		if ((count = count_quote_and_regular(to_lex, &i, count)) == -1)
			return (-1);
		count = count_separator(to_lex, &i, count);
	}
	return (count);
}
