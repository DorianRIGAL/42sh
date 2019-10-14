/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** get_semicolon.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "error.h"

int shift_quote(char *str, int i, int *to_malloc)
{
	int save_i = i;

	if (str[i] == '"') {
		i = i + 1;
		for (;str[i] != '\0' && str[i] != '"'; i++);
		if (str[i] == '\0') {
			write(2, "Unmatched \".\n", 13);
			return (-1);
		}
	} else if (str[i] == '\'') {
		i = i + 1;
		for (;str[i] != '\0' && str[i] != '\''; i++);
		if (str[i] == '\0') {
			write(2, "Unmatched \'\'\'.\n", 15);
			return (-1);
		}
	}
	*to_malloc += (i != save_i) ? i - save_i : 0;
	return (i);
}

void malloc_separator(char **arr, char *to_lex, int *i, int *k)
{
	int sep_1 = -1;
	int sep_2 = -1;

	if (to_lex[*i] != '\0' && (sep_1 = separator(to_lex[*i])) != -1 &&
	sep_1 > 2 && to_lex[*i + 1] != '\0' &&
	(sep_2 = separator(to_lex[*i + 1])) == sep_1) {
		*i += 2;
		arr[*k] = malloc(sizeof(char) * (3));
		*k += 1;
	} else if ((sep_1 == 1 || sep_1 == 2) || (sep_1 != -1 &&
	(to_lex[*i + 1] == '\0' || sep_2 != sep_1))) {
		arr[*k] = malloc(sizeof(char) * (2));
		*i += 1;
		*k += 1;
	}
}

void malloc_quote(char **arr, char *to_lex, int *i, int *k)
{
	int to_malloc = 0;

	*i = shift_quote(to_lex, *i, &to_malloc);
	if (to_malloc > 0) {
		to_malloc += 1;
		arr[*k] = malloc(sizeof(char) * (to_malloc + 1));
		*k += 1;
		*i += 1;
	}
}

void malloc_regular(char **arr, char *to_lex, int *i, int *k)
{
	int to_malloc = 0;

	for (; to_lex[*i] != '\0' && is_if(to_lex, *i) == 0 &&
	separator(to_lex[*i]) == -1; *i += 1) {
		to_malloc += 1;
		*i = shift_quote(to_lex, *i, &to_malloc);
	}
	if (to_malloc > 0) {
		arr[*k] = malloc(sizeof(char) * (to_malloc + 1));
		*k += 1;
	}
	if (is_if(to_lex, *i) == 1) {
		*i = *i + 2;
		arr[*k] = malloc(sizeof(char) * (3));
		*k += 1;
	}
}

char **malloc_sem_arr(char *to_lex)
{
	int sem = count_semicolon(to_lex);
	char **arr = NULL;
	int i = 0;
	int k = 0;

	if (sem == -1 || (arr = malloc(sizeof(char *) * (sem + 1))) == NULL)
		return (NULL);
	for (int j = 0; to_lex != NULL && arr != NULL && to_lex[i] != '\0';
	j += 1) {
		pass_space_and_tab(to_lex, &i);
		malloc_regular(arr, to_lex, &i, &k);
		malloc_separator(arr, to_lex, &i, &k);
		pass_space_and_tab(to_lex, &i);
	}
	arr[k] = NULL;
	return (arr);
}