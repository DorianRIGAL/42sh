/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** print_node.c
*/

#include "term_prototype.h"

void	print_node(term_list_t *list)
{
	for (term_node_t *tmp = list->head; tmp; tmp = tmp->next)
		my_putchar(tmp->data);
}
