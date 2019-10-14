/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** src/utils/my_strcmp.c : Compare two strings.
*/

int len(char const*);

int my_strcmp(char const *s1, char const *s2)
{
	int n_length = 0;
	int a_length = len(s1);
	int b_length = len(s2);
	int i = 0;

	if (a_length >= b_length)
		n_length = a_length;
	else
		n_length = b_length;
	while (i < n_length) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i += 1;
	}
	return (0);
}

int my_strcmp_till(char const *s1, char const *s2, int till)
{
	int n_length = 0;
	int a_length = len(s1);
	int b_length = till;
	int i = 0;

	if (a_length >= b_length)
		n_length = a_length;
	else
		n_length = b_length;
	while (i < n_length) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i += 1;
	}
	return (0);
}