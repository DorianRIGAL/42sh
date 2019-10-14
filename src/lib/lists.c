/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** Generic List System.
*/

#include "leolib.h"

list_t *list_init(void)
{
	list_t *list = malloc(sizeof(list_t));

	if (!list) {
		write(2, "Malloc Error.\n", 15);
		return (NULL);
	}
	list->head = NULL;
	list->size = 0;
	return (list);
}

void *list_get(list_t *list, int id)
{
	node_t *node = list->head;
	int i = -1;

	if (!node)
		return (NULL);
	while (node) {
		if (++i == id)
			return (node->data);
		node = node->next;
	}
	return (NULL);
}

node_t *list_last(list_t *list)
{
	node_t *node = list->head;

	while (node->next)
		node = node->next;
	return (node);
}

void list_push(list_t *list, void *data)
{
	node_t *new_node;
	node_t *last;

	if (!list || !data)
		return;
	new_node = malloc(sizeof(node_t));
	new_node->id = 0;
	new_node->data = data;
	new_node->next = NULL;
	if (!list->head) {
		new_node->id = 0;
		list->head = new_node;
	} else {
		last = list_last(list);
		new_node->id = last->id + 1;
		last->next = new_node;
	}
	list->size++;
}