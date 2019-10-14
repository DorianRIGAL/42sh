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

char *fill_shift_quote(char **arr, char *str, int *k, int *m)
{
	if (*str == '"') {
		str += 1;
		for (;*str != '\0' && *str != '"'; str++) {
			arr[*k][*m] = *str;
			*m += 1;
		}
		arr[*k][*m] = *str;
		*m += 1;
		arr[*k][*m] = '\0';
	} else if (*str == '\'') {
		str += 1;
		for (;*str != '\0' && *str != '\''; str++) {
			arr[*k][*m] = *str;
			*m += 1;
		}
		arr[*k][*m] = *str;
		*m += 1;
		arr[*k][*m] = '\0';
	}
	return (str);
}

char *fill_regular(char **arr, char *to_lex, int *k)
{
	int m = 0;

	for (; *to_lex != '\0' && is_if_fill(to_lex) == 0 &&
	separator(*to_lex) == -1; to_lex ++) {
		arr[*k][m++] = *to_lex;
		to_lex = fill_shift_quote(arr, to_lex, k, &m);
	}
	if (m > 0) {
		arr[*k][m] = '\0';
		*k += 1;
		m = 0;
	}
	if (is_if_fill(to_lex) == 1) {
		arr[*k][0] = *to_lex;
		arr[*k][1] = *(to_lex + 1);
		arr[*k][2] = '\0';
		to_lex += 2;
		*k += 1;
	}
	return (to_lex);
}

char *fill_separator(char **arr, char *to_lex, int *k)
{
	int sep_1 = -1;
	int sep_2 = -1;

	if (*to_lex != '\0' && (sep_1 = separator(*to_lex)) != -1 &&
	sep_1 > 2 && *(to_lex + 1) != '\0' &&
	(sep_2 = separator(*(to_lex + 1))) == sep_1) {
		arr[*k][0] = *to_lex;
		arr[*k][1] = *(to_lex + 1);
		arr[*k][2] = '\0';
		*k += 1;
		to_lex += 2;
	} else if ((sep_1 == 1 || sep_1 == 2) || (*to_lex != '\0' &&
	(sep_1 = separator(*to_lex)) != -1 && (*(to_lex + 1) == '\0' ||
	(sep_2 = separator(*(to_lex + 1))) != sep_1))) {
		arr[*k][0] = *to_lex;
		arr[*k][1] = '\0';
		*k += 1;
		to_lex ++;
	}
	return (to_lex);
}

char *fill_pass_space_and_tab(char *path)
{
	for (; path && *path != '\0' &&
	(*path == ' ' || *path == '\t'); path += 1);
	return (path);
}

char **fill_sem_arr(char **arr, char *to_lex)
{
	int k = 0;

	to_lex = fill_pass_space_and_tab(to_lex);
	while (to_lex != NULL && arr != NULL && *to_lex != '\0') {
		to_lex = fill_regular(arr, to_lex, &k);
		to_lex = fill_separator(arr, to_lex, &k);
		to_lex = fill_pass_space_and_tab(to_lex);
	}
	arr[k] = NULL;
	return (arr);
}
