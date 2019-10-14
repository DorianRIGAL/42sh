/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** init_termcaps
*/

#include "term_prototype.h"
#include "termcaps.h"
#include "main.h"

int	init_term(struct termios *term, char **env)
{
	char *name_term = NULL;

	name_term = get_env("TERM", env);
	if (!name_term)
		return (-1);
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	free(name_term);
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	block_free(env);
	return (0);
}

int	reset_term(struct termios *term)
{
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, term) == -1)
		return (-1);
	return (0);
}

int	my_outc(int c)
{
	my_putchar(c);
	return (0);
}

int	exec_term(char *str)
{
	char *test = NULL;

	if ((test = tgetstr(str, NULL)) == NULL)
		return (84);
	tputs(test, 0, &my_outc);
	return (0);
}
