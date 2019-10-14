/*
** EPITECH PROJECT, 2018
** lib
** File description:
** tab len
*/

int	my_tab_len(char **tab)
{
	int i = 0;

	for (i = 0; tab && tab[i]; i += 1);
	return (i);
}
