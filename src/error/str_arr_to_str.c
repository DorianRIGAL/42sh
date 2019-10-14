/*
** EPITECH PROJECT, 2017
** dante
** File description:
** str_arr_to_str.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "leolib.h"
#include "error.h"
#include "main.h"

int arr_byte(char **arr)
{
	int size = 0;

	for (int i = 0; arr && arr[i] != NULL; i += 1) {
		size += len(arr[i]);
		if (is_sep(arr[i]) == 1)
			size += 1;
	}
	return (size);
}

char *str_arr_to_str(char **arr)
{
	char *str = malloc(sizeof(char) * (arr_byte(arr) + 1));
	int m = 0;

	for (int i = 0; arr && arr[i] != NULL; i += 1) {
		for (int k = 0; arr[i][k] != '\0'; k += 1)
			str[m++] = arr[i][k];
		if (is_sep(arr[i]) == 1)
			str[m++] = ' ';
	}
	str[m] = '\0';
	return (str);
}