/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** list tool
*/

#include "term_prototype.h"

term_node_t	*cp_list(term_node_t *list)
{
	term_list_t new;

	new.size = 0;
	new.next = NULL;
	new.prev = NULL;
	new.head = NULL;
	for (term_node_t *tmp = list; tmp; tmp = tmp->next)
		add_node(&new, tmp->data, new.size - 1);
	return (new.head);
}

int	get_list_len(term_node_t *list)
{
	int i = 0;

	for (; list; list = list->next, i += 1);
	return (i);
}

int	cmp_list(term_node_t *l1, term_node_t *l2)
{
	if (get_list_len(l1) != get_list_len(l2))
		return (0);
	for (; l1 && l2; l1 = l1->next, l2 = l2->next) {
		if (l1->data != l2->data)
			return (0);
	}
	return (1);
}

int	cmp_begin_list(term_node_t *l1, term_node_t *l2)
{
	if (get_list_len(l1) > get_list_len(l2))
		return (0);
	for (; l1 && l2; l1 = l1->next, l2 = l2->next) {
		if (l1->data != l2->data)
			return (0);
	}
	return (1);
}
