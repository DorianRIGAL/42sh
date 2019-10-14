/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** Personal My putchar
*/

void write(int, char*, int);

void my_putchar(char c)
{
	write(1, &c, 1);
}