/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** analyse.c
*/

#include "main.h"

node_t  *node_add(node_t **head, node_t *tmp, char *data)
{
	node_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->id = 0;
	new->data = data;
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	else
		*head = new;
	return (new);
}

node_t	*create_args_list(char **args)
{
	node_t *tmp = NULL;
	node_t *head = NULL;

	for (int i = 0; args[i]; i += 1)
		tmp = node_add(&head, tmp, args[i]);
	return (head);
}

void	free_args_list(node_t *list)
{
	node_t *tmp = list;

	for (list = list->next; list; tmp = list, list = list->next)
		free(tmp);
	free(tmp);
}

int	change_input(shell_t *shell, node_t **head)
{
	if (check_alias(shell, head) == -1 ||
	check_var(shell, head) == -1 || globbing(shell, head) == -1) {
		free_args_list(*head);
		return (-1);
	}
	return (0);
}

char	**analyse_input(shell_t *shell, char **args)
{
	node_t *head = NULL;
	node_t *tmp;
	int len = 0;
	char *ret = NULL;

	if (!args || !args[0])
		return (NULL);
	head = create_args_list(args);
	free(args);
	if (change_input(shell, &head) == -1)
		return (NULL);
	for (tmp = head; tmp; len += 1, tmp = tmp->next);
	tmp = head;
	for (int i = 0; tmp; i += 1, tmp = tmp->next)
		ret = my_strcat_space(ret, tmp->data);
	free_args_list(head);
	args = my_str_to_word_array(ret, ' ');
	free(ret);
	return (args);
}
