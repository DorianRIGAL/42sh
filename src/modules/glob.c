/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** glob
*/

#include "main.h"
#include "leolib.h"
#include <glob.h>

node_t	*glob_no_match(shell_t *shell, char *first, glob_t res)
{
	put_err(first);
	put_err(": No match.\n");
	free(res.gl_pathv);
	shell->state = 1;
	return (NULL);
}

node_t	*test_glob(shell_t *shell, node_t *prev, node_t *list, node_t **head)
{
	glob_t res;

	if (((char*)list->data)[0] == 0)
		return (list);
	glob((char*)list->data, GLOB_NOMAGIC | GLOB_NOESCAPE, NULL, &res);
	if (res.gl_pathc == 1 && !strcmp(res.gl_pathv[0], (char*)list->data)) {
		free(res.gl_pathv[0]);
		free(res.gl_pathv);
		return (list);
	}
	if (res.gl_pathc == 0)
		return (glob_no_match(shell, (*head)->data, res));
	for (unsigned int i = 0; i < res.gl_pathc; i += 1)
		prev = node_add(head, prev, res.gl_pathv[i]);
	prev->next = list->next;
	free(list->data);
	free(list);
	free(res.gl_pathv);
	return (prev);
}

int	globbing(shell_t *shell, node_t **head)
{
	node_t *list = *head;
	node_t *tmp = NULL;

	for (; list; tmp = list, list = list->next) {
		list = test_glob(shell, tmp, list, head);
		if (!list)
			return (-1);
	}
	return (0);
}
