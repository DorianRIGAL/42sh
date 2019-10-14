/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** include/conditionals.h
*/

#ifndef CONDITIONALS_H_
	#define CONDITIONALS_H_

	typedef struct shell shell_t;
	typedef void(*condition_analyzer_t)(shell_t*, char**, int, char*);

	typedef struct conditional {
		char *str;
		int data;
		condition_analyzer_t func;
	} conditional_box_t;

	void condition_size(shell_t*, char**, int, char*);
	void condition_equals(shell_t*, char**, int, char*);
#endif