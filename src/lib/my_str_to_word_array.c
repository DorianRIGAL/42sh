/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** parser
*/

#include "main.h"

int	check_sep(char c, char sep, int tab[3])
{
	check_spec(c, tab);
	if ((c == ' ' || c == 9 || c == sep) && tab[0] + tab[1] + tab[2] == 0)
		return (0);
	return (1);
}

int	word_count(char *s, char sep)
{
	int spec[3] = {0, 0, 0};
	int nb = 0;
	int i = 0;

	if (!s)
		return (0);
	for (; s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == sep); i += 1);
	while (s[i]) {
		for (; s[i] && check_sep(s[i], sep, spec); i += 1);
		nb += 1;
		for (; s[i] && (s[i] == ' ' ||
		s[i] == '\t' || s[i] == sep); i += 1);
	}
	return (nb);
}

int	get_next_word(char **str, char sep)
{
	int spec[3] = {0, 0, 0};
	int len = 0;
	int i = 0;
	char *s = *str;

	for (; s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == sep); i += 1);
	s += i;
	*str = s;
	for (; s[len] && check_sep(s[len], sep, spec); len += 1);
	return (len);
}

int	fill_tab(char **tab, int size, char sep, char *str)
{
	int len = 0;

	for (int j = 0; j < size; j += 1) {
		len = get_next_word(&str, sep);
		tab[j] = malloc(sizeof(char) * (len + 1));
		if (!tab[j])
			return (-1);
		for (int i = 0; i < len; i += 1)
			tab[j][i] = str[i];
		tab[j][len] = 0;
		str += len;
	}
	tab[size] = NULL;
	return (0);
}

char	**my_str_to_word_array(char *str, char sep)
{
	int size = word_count(str, sep);
	char **tab = NULL;

	if (!size)
		return (NULL);
	tab = malloc(sizeof(char*) * (size + 1));
	if (!tab)
		return (NULL);
	if (fill_tab(tab, size, sep, str) == -1)
		return (NULL);
	return (tab);
}
