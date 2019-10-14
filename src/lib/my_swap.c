/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** Swap stuff
*/

void my_swap_str(char **a, char **b)
{
	char *temp = *a;

	*a = *b;
	*b = temp;
}

void my_swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}