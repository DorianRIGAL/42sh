/*
** EPITECH PROJECT, 2017
** dante
** File description:
** PSU_42sh_2017/src/error/exotic_cor.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "leolib.h"
#include "error.h"
#include "main.h"

char **exotic_redir_cor(char **arr)
{
	for (int i = 0; arr && arr[i] != NULL; i += 1) {
		if ((arr[i][0] == '<' || arr[i][0] == '>') &&
		arr[i + 1] != NULL &&
		tablen(my_str_to_word_array(arr[i + 1], ' ')) > 1) {
			arr = modif_exotic_redirec(arr, i);
			i += 2;
		}
	}
	return (arr);
}