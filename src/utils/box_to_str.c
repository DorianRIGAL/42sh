/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/utils/box_to_str.c : Convert a char** to char*
*/

#include "main.h"

char *box_to_str(UNUSED char **splitted)
{
	char *res = NULL;

	for (int i = 0; splitted[i]; i++)
		res = concat_free(res, splitted[i]);
	return (res);
}