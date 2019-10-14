/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** variable
*/

#include "main.h"

int	get_value(char **dest, char *name, shell_t *shell)
{
	node_t *tmp = shell->variables->head;

	if (name[0] == '?') {
		*dest = my_str_nbr(shell->state);
		free(name);
		return (0);
	}
	for (; tmp && strcmp(((variable_t*)tmp->data)->name, name);
		tmp = tmp->next);
	if (tmp){
		free(name);
		*dest = ((variable_t*)tmp->data)->data;
		return (0);
	}
	return (check_env_var(dest, name, shell));
}

int	put_value_next(char **str, int *i, char *value, int j)
{
	char *ret = NULL;
	char *tmp = *str + *i + 1;

	(*str)[*i] = 0;
	if (value)
		ret = concat(*str, value);
	else
		ret = my_strdup(*str);
	tmp = concat(ret, tmp + j);
	free(ret);
	free(*str);
	*str = tmp;
	*i += len(value) - 1;
	return (0);
}

int	put_value(char **str, int *i, shell_t *shell)
{
	char *tmp = *str + *i + 1;
	char *value = NULL;
	int j = 0;

	for (; tmp[j] && tmp[j] != 39 && tmp[j] != 34 && tmp[j] != '(' && tmp[j]
	!= ')' && tmp[j] != '$' && tmp[j] != ' ' && tmp[j] != '\t'; j += 1);
	if (!j && tmp[j] != '$')
		return (0);
	if (!j && tmp[j] == '$') {
		value = my_str_nbr(getpid());
		j += 1;
	}
	if (j && *tmp != '$' && get_value
	(&value, my_strndup(*str + *i + 1, j), shell))
		return (-1);
	return (put_value_next(str, i, value, j));
}

int	replace_var(node_t *tmp, shell_t *shell)
{
	char *str = tmp->data;
	int i = 0;
	int quote = 1;
	int ret = 0;

	for (; str[i]; i += 1) {
		quote *= str[i] != 39 ? 1 : -1;
		if (str[i] == '$' && quote == 1)
			ret = put_value(&str, &i, shell);
		if (ret == -1)
			return (-1);
	}
	tmp->data = str;
	return (0);
}

int	check_var(shell_t *shell, node_t **head)
{
	node_t *tmp = *head;

	for (; tmp; tmp = tmp->next) {
		if (replace_var(tmp, shell) == -1)
			return (-1);
	}
	return (0);
}
