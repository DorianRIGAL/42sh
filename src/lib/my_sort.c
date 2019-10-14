/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** Sort an array of stuff.
*/

void my_swap_int(int*, int*);
void my_swap_str(char**, char**);
int my_strcmp(char const*, char const*);
char **my_str_to_word_array(char const*, char);

void sort_check_size(int *a, int *b)
{
	if (*a > *b)
		my_swap_int(a, b);
}

void sort_check_str(char **str_a, char **str_b)
{
	if (my_strcmp(str_a[0], str_b[0]) > 0)
		my_swap_str(&str_a[0], &str_b[0]);
}

void my_sort_int_array(int *box, int size)
{
	if (!box || !size)
		return;
	for (int x = 0; x < size; x++) {
		for (int y = x + 1; y < size; y++)
			sort_check_size(&box[x], &box[y]);
	}
}

char **my_sort_words(char *str, char sep)
{
	char **data = my_str_to_word_array(str, sep);
	int size = -1;

	while (data[++size]);
	for (int x = 0; x < size; x++) {
		for (int y = x + 1; y < size; y++)
			sort_check_str(&data[x], &data[y]);
	}
	return (data);
}