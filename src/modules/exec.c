/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Execute Plx
*/

#include "main.h"

xerror_t errors[17] = {
	{0, "", 0},
	{1, "Hangup", 129},
	{2, "", 1},
	{3, "Quit", 131},
	{4, "Illegal instruction", 132},
	{5, "Trace/BPT trap", 133},
	{6, "Abort", 134},
	{7, "Bus error", 135},
	{8, "Floating exception", 136},
	{9, "Killed", 137},
	{10, "User signal 1", 138},
	{11, "Segmentation fault", 139},
	{12, "User signal 2", 140},
	{13, "", 0},
	{14, "Alarm clock", 142},
	{15, "Terminated", 143},
	{16, "Stack limit exceeded", 144},
};

xsignal_t signals[] = {
	{EACCES, EXECUTE_RIGHTS},
	{ENOENT, COMMAND_NOT_FOUND},
	{ENOEXEC, EXEC_ERR},
	{0, NULL},
};

int error_handler(int state)
{
	int length = 0;
	char dump[] = " (core dumped)\n";

	if (WTERMSIG(state) > 16)
		return (1);
	if (WIFSIGNALED(state)) {
		length = len(errors[WTERMSIG(state)].msg);
		write(2, errors[WTERMSIG(state)].msg, length);
	}
	if (WCOREDUMP(state))
		write(2, dump, len(dump));
	else if (WTERMSIG(state) != 0 && WTERMSIG(state) != 13)
		write(2, "\n", 1);
	return (errors[WTERMSIG(state)].num);
}

int exec_err_handler(char *path)
{
	for (int i = 0; signals[i].loc; i++) {
		if (errno == signals[i].loc) {
			put_err(path);
			put_err(signals[i].msg);
			break;
		}
	}
	return (1);
}

int raw_execute(char **env, char **splitted)
{
	return (global_execute(splitted[0], splitted, env));
}

int global_execute(char *path, char **args, char **env)
{
	int loc = 0;
	int res = 0;

	if (fork() == 0) {
		if (execve(path, args, env) == -1) {
			exit(exec_err_handler(path));
		}
	} else {
		wait(&loc);
		if (!WIFEXITED(loc))
			res = error_handler(loc);
		else
			res = WEXITSTATUS(loc);
		block_free(args);
	}
	return (res);
}

void output_not_found(char *path)
{
	put_err(path);
	put_err(COMMAND_NOT_FOUND);
}
