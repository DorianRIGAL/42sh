/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** path_list
*/

#include "term_prototype.h"

path_t	*add_path(path_t *next, char *name)
{
	path_t *new = malloc(sizeof(*new));

	if (!new)
		return (next);
	new->next = next;
	new->path = name;
	return (new);
}
