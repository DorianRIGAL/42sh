/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** str_to_word_array
*/

#include "main.h"

void    check_spec(char c, int tab[3])
{
	if (c == 34) {
		if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0)
			tab[0] = 1;
		else if (tab[0] == 1)
			tab[0] = 0;
	}
	if (c == 39) {
		if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0)
			tab[1] = 1;
		else if (tab[1] == 1)
			tab[1] = 0;
	}
	if (c == 40 || c == 41) {
		if (tab[0] == 0 && tab[1] == 0 && c == 40)
			tab[2] += 1;
		else if (tab[2] != 0 && c == 41)
			tab[2] -= 1;
	}
}
