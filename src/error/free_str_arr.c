/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** error.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "leolib.h"
#include "error.h"
#include "main.h"

void free_str_arr(char **arr)
{
	if (arr == NULL)
		return;
	for (int i = 0; arr[i] != NULL; i += 1)
		free(arr[i]);
	free(arr);
}