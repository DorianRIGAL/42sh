/*
** EPITECH PROJECT, 2018
** 42.h
** File description:
** term.h
*/

#ifndef TERMCAPS_H_
	#define TERMCAPS_H_

	#include <termios.h>
	#include <curses.h>
	#include <termcap.h>

	int	tgetent(char *bp, const char *name);
	int	tputs(const char *str, int affcnt, int (*putc)(int));
	int	init_term(struct termios *term, char **env);
	int	reset_term(struct termios *term);
	int	exec_term(char *str);
#endif
