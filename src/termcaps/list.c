/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** list.c
*/

#include "term_prototype.h"

char	*from_list_to_array(term_list_t *list)
{
	char *new = malloc(sizeof(char) * (list->size) + 1);
	int i = 0;

	if (!new)
		return (NULL);
	for (term_node_t *tmp = list->head; tmp; i += 1, tmp = tmp->next)
		new[i] = tmp->data;
	new[i] = 0;
	return (new);
}

void	cut_list(term_list_t *list)
{
	for (; list && list->next; list = list->next);
	list->prev->next = NULL;
	free_node(list->head);
	free(list);
}

term_list_t	*add_list(term_list_t *prev)
{
	term_list_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->size = 0;
	new->head = NULL;
	new->next = NULL;
	new->prev = prev;
	if (prev)
		prev->next = new;
	return (new);
}

int	add_node(term_list_t *list, char data, int index)
{
	term_node_t *new = malloc(sizeof(*new));
	term_node_t *tmp = list->head;

	if (!new)
		return (-1);
	new->data = data;
	list->size += 1;
	if (index == -1) {
		new->prev = NULL;
		new->next = tmp;
		list->head = new;
		return (0);
	}
	for (int i = 0; i < index && tmp; i += 1, tmp = tmp->next);
	new->next = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	if (new->next)
		new->next->prev = new;
	return (0);
}

void	delete_node_term(term_list_t *list, int index)
{
	term_node_t *tmp = list->head;

	if (!index) {
		if (tmp) {
			list->head = tmp->next;
			free(tmp);
			list->size -= 1;
		}
		return;
	}
	for (int i = 0; index > 0
	&& i < index && tmp; i += 1, tmp = tmp->next);
	if (!tmp || index < 0 || !tmp->prev)
		return;
	tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	free(tmp);
	list->size -= 1;
}
