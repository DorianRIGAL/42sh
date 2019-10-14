/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** Put number function
*/

void my_putchar(char);

int my_put_nbr(long long nb)
{
	int i = 0;

	if (nb < 0) {
		i += 2;
		my_putchar('-');
		if (nb <= -10)
			i += my_put_nbr((nb / 10) * -1);
		my_putchar(((nb % 10) * -1) + '0');
	} else {
		i++;
		if (nb >= 10)
			i += my_put_nbr(nb / 10);
		my_putchar((nb % 10) + '0');
	}
	return (i);
}
