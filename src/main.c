/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Mysh main.
*/

#include "main.h"

void	init_shell_list(shell_t *shell)
{
	shell->aliases = list_init();
	shell->variables = list_init();
}

int	second_main(int argc, char **argv, char **env)
{
	shell_t *shell = malloc(sizeof(shell_t));

	signal(SIGINT, SIG_IGN);
	if (!shell)
		return (84);
	memset(shell, 0, sizeof(shell_t));
	environment_init(shell, env);
	init_shell_list(shell);
	return (shell_init(shell, argc > 1 ? argv : NULL));
}

int	main(int ac, char **av, char **env)
{
	int ret = 0;

	if (fork() == 0) {
		exit(second_main(ac, av, env));
	} else {
		wait(&ret);
	}
	return (WEXITSTATUS(ret));
}