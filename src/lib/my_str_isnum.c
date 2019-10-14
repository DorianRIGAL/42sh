/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** Returns 1 if string is 123 only, else 0
*/

int my_str_isnum(char const *str)
{
	int i = -1;

	while (str[++i]) {
		if (str[i] >= 48 && str[i] <= 57)
			continue;
		else
			return (0);
	}
	return (1);
}

int my_char_isnum(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}