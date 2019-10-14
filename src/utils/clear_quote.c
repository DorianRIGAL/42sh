/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** clear quote
*/

#include "main.h"

void	clear_quote(char *s)
{
	int j = 0;
	int i = 0;
	int save = 0;

	for (; s && s[i]; i += 1) {
		if ((s[i] == 39 || s[i] == 34) && !save) {
			save = s[i];
			continue;
		}
		if (s[i] && s[i] == save) {
			save = 0;
			continue;
		}
		s[j] = s[i];
		j += 1;
	}
	if (s)
		s[j] = 0;
}

void	clear_quote_tab(char **tab)
{
	for (int i = 0; tab && tab[i]; i += 1)
		clear_quote(tab[i]);
}
