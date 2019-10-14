/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** display, one by one characters of a string
*/

#include <unistd.h>

int len(char const*);

int put_str(char *str)
{
	int i = len(str);

	write(1, str, i);
	return (i);
}

int put_err(char *str)
{
	int i = len(str);

	write(2, str, i);
	return (i);
}