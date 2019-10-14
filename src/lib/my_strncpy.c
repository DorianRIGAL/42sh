/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** Copies n characters from a string into another.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	while (i < n) {
		if (dest[i] == '\0')
			break;
		dest[i] = src[i];
		i += 1;
	}
	return (dest);
}