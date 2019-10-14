/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** list tool
*/

#include "main.h"

void	add_node_sort(list_t *list, void *data)
{
	node_t *new = malloc(sizeof(*new));
	node_t *tmp = list->head;

	new->data = data;
	new->id = 0;
	list->size += 1;
	if (!list->head) {
		list->head = new;
		new->next = NULL;
		return;
	}
	if (strcmp(((alias_t*)tmp->data)->name, ((alias_t*)data)->name) > 0) {
		list->head = new;
		new->next = tmp;
		return;
	}
	for (; tmp->next && strcmp(((alias_t*)tmp->next->data)->name,
	((alias_t*)data)->name) < 0; tmp = tmp->next);
	new->next = tmp->next;
	tmp->next = new;
}

void	*get_node(list_t *list, char *name)
{
	node_t *tmp = NULL;

	for (tmp = list->head; tmp &&
	strcmp(((alias_t*)tmp->data)->name, name); tmp = tmp->next);
	if (tmp)
		return (tmp->data);
	return (NULL);
}

void	delete_node(list_t *list, char *name, destroy_node_data_t func)
{
	node_t *tmp = list->head;
	node_t *tmp2 = NULL;

	for (; tmp && strcmp(((alias_t*)tmp->data)->name, name);
	tmp2 = tmp, tmp = tmp->next);
	if (!tmp)
		return;
	list->size -= 1;
	if (!tmp2) {
		list->head = tmp->next;
		func(tmp->data);
		free(tmp);
		return;
	}
	tmp2->next = tmp->next;
	func(tmp->data);
	free(tmp);
}