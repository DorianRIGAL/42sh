/*
** EPITECH PROJECT, 2017
** my_str_isalpha
** File description:
** Return 1 if string contains abc and 123
*/

int my_str_isalpha(char const *str)
{
	char x = '\0';
	int i = 0;

	while (str[i] != '\0') {
		x = str[i];
		if ((x >= 97 && x <= 122) || (x >= 65 && x <= 90))
			i++;
		else if ((x >= 48 && x <= 57))
			i++;
		else
			return (0);
	}
	return (1);
}