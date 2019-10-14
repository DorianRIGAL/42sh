/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** src/utils/pipes.c
*/

#include "main.h"

void descriptor_handler(int output)
{
	if (output == -1) {
		exit(errno);
	}
}

void set_pipes_receiver(int end, int duplicate, int at)
{
	descriptor_handler(close(end));
	descriptor_handler(dup2(duplicate, at));
}

void set_pipes(int fdin, int fdout, bool reset)
{
	static int base_fdin = 0;
	static int base_fdout = 1;

	if (reset) {
		if (fdout != 1)
			descriptor_handler(dup2(base_fdout, STDOUT_FILENO));
		if (fdin != 0)
			descriptor_handler(dup2(base_fdin, STDIN_FILENO));
		base_fdin = 0;
		base_fdout = 0;
	} else {
		if (fdout != 1) {
			base_fdout = dup(1);
			descriptor_handler(dup2(fdout, STDOUT_FILENO));
		}
		if (fdin != 0) {
			base_fdin = dup(0);
			descriptor_handler(dup2(fdin, STDIN_FILENO));
		}
	}
}