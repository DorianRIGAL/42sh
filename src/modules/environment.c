/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Environment variables handling.
*/

#include "main.h"

char **env_get(shell_t *shell)
{
	char **res = malloc(sizeof(char*) * (1 + shell->env_list->size));
	char *line = NULL;
	item_t *item = NULL;
	int i = -1;

	res[shell->env_list->size] = '\0';
	while (++i < shell->env_list->size) {
		item = list_get(shell->env_list, i);
		line = concat(item->var, "=");
		res[i] = concat(line, item->data);
		free(line);
	}
	return (res);
}

item_t *env_get_var(shell_t *shell, char *wanted)
{
	item_t *item = NULL;
	node_t *node = shell->env_list->head;

	while (node) {
		item = node->data;
		if (!my_strcmp(item->var, wanted))
			return (item);
		node = node->next;
	}
	return (NULL);
}

void env_remove_var(shell_t *shell, char *wanted)
{
	item_t *item = NULL;
	node_t *node = shell->env_list->head;
	node_t *prev = shell->env_list->head;

	while (node) {
		item = node->data;
		if (!my_strcmp(item->var, wanted) && node == prev)
			shell->env_list->head = node->next;
		if (!my_strcmp(item->var, wanted)) {
			prev->next = node->next;
			shell->env_list->size--;
			environment_free_node(node, item);
			break;
		}
		prev = node;
		node = node->next;
	}
}

void env_add_var(shell_t *shell, char *variable, char *dat)
{
	item_t *obj = env_get_var(shell, variable);
	int var_len = len(variable);
	int data_len = len(dat);

	if (obj) {
		free(obj->data);
		obj->data = malloc(sizeof(char) * (data_len + 1));
		my_strcpy(obj->data, dat);
	} else {
		obj = malloc(sizeof(item_t));
		obj->var = malloc(sizeof(char) * (var_len + 1));
		obj->data = malloc(sizeof(char) * (data_len + 1));
		my_strcpy(obj->var, variable);
		my_strcpy(obj->data, dat);
		list_push(shell->env_list, obj);
	}
}

void environment_init(shell_t *shell, char **env)
{
	item_t *obj = NULL;
	char **line = NULL;

	shell->env_list = list_init();
	if (!env) {
		path_manual_init(shell);
		return;
	}
	for (int i = 0; env[i]; i++) {
		obj = malloc(sizeof(item_t));
		line = my_strcut(env[i], '=');
		obj->var = line[0];
		obj->data = line[1];
		list_push(shell->env_list, obj);
		free(line);
	}
	if (shell->env_list->size == 0)
		path_manual_init(shell);
	if (termcaps_init(shell, env_get(shell)))
		shell->termcaps_initialized = true;
}