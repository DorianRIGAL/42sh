/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** Int to String.
*/

#include <stdlib.h>

char *concat(char*, char*);

int my_count_nbr(long long nb)
{
	int i = 0;

	if (nb < 0) {
		i += 2;
		if (nb <= -10)
			i += my_count_nbr((nb / 10) * -1);
	} else {
		i++;
		if (nb >= 10)
			i += my_count_nbr(nb / 10);
	}
	return (i);
}

char *my_str_nbr(int nb)
{
	int i = -1;
	int size = my_count_nbr(nb);
	char *output = malloc(sizeof(char) * (size + 1));
	int neg = 0;

	if (!output)
		return ((void*)0);
	if (nb < 0 && ++neg && !++i)
		nb *= -1;
	while (++i < size) {
		output[size - i - 1] = (nb % 10) + '0';
		if (nb >= 10)
			nb /= 10;
	}
	output[i] = '\0';
	return ((neg == 1) ? output = concat("-", output) : output);
}