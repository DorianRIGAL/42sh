/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** Every uppercase letter to lowercase
*/

char *my_strlowcase(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i += 1;
	}
	return (str);
}