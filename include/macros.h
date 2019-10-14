/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Macros
*/

#ifndef MACROS_H_
	#define MACROS_H_
	#define STD_HOME "/home/"
	#define ENV_HELP "setenv: Variable name must begin with a letter.\n"
	#define ENV_MANY "setenv: Too many arguments.\n"
	#define ENV_ALPHA "setenv: Variable name must contain "
	#define ENV_BETA "alphanumeric characters.\n"
	#define UNSET_MANY "unsetenv: Too few arguments.\n"
	#define EXECUTE_RIGHTS ": Permission denied.\n"
	#define COMMAND_NOT_FOUND ": Command not found.\n"
	#define EXEC_ERR ": Exec format error. Binary file not executable.\n"
	#define CMD_NULL "Invalid null command.\n"
	#define CMD_REDIRECT "Missing name for redirect.\n"
	#define ERR_LONG_CD ": File name too long.\n"
	#define IF_TOO_FEW "if: Too few arguments.\n"
	#define IF_EMPTY "if: Empty if.\n"
	#define IF_EXPRESSION "if: Expression Syntax.\n"
	#define SET_VAR_ERR "set: Variable name must begin with a letter.\n"
	#define UNSET_TOO_FEW "unset: Too few arguments.\n"
	#define FOR_BASE "foreach: Variable name must "
	#define FOR_ERR "begin with a letter.\n"
	#define FOR_ARR "contain alphanumeric characters.\n"
	#define FOR_FEW "foreach: Too few arguments.\n"
	#define FOR_PAR "foreach: Words not parenthesized.\n"
#endif