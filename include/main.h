/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <signal.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <sys/wait.h>
	#include <string.h>
	#include <errno.h>
	#include "macros.h"
	#include "core.h"
	#include "leolib.h"
	#include "tokens.h"
	#include "term_prototype.h"

	typedef struct op_struct_s {
		char *str;
		char c;
	} op_struct_t;

	typedef struct item {
		char *var;
		char *data;
	} item_t;

	typedef struct shell {
		ctx_t *context;
		list_t *aliases;
		list_t *variables;
		list_t *env_list;
		token_t *root;
		int parse_err;
		int state;
		int sig_id;
		int quit;
		int tree_error;
		bool termcaps_initialized;
		int script_fd;
		char *buffer;
		char *old;
	} shell_t;

	typedef struct xerror {
		int loc;
		char *msg;
		int num;
	} xerror_t;

	typedef struct xsignal {
		int loc;
		char *msg;
	} xsignal_t;

	typedef struct alias_s {
		char *name;
		char **after;
		int loop;
	} alias_t;

	typedef struct variable_s {
		char *name;
		char *data;
	} variable_t;

	typedef void(*op_type_func_t)(int, token_t*, shell_t*);

	typedef struct op_funcs {
		op_type_t type;
		op_type_func_t func;
	} op_funcs_t;

	typedef void (*builtin_func_t)(shell_t*, char**);

	typedef struct builtin {
		char *var;
		builtin_func_t func;
	} builtin_t;

	void display(shell_t *shell);
	int my_is_clear(char*);
	char *box_to_str(char**);
	int shell_init(shell_t*, char**);
	void environment_init(shell_t*, char**);
	void environment_free(shell_t*);
	void environment_free_node(node_t*, item_t*);
	void block_free(char**);
	void free_all(shell_t*, char*);
	void free_up(char*, char**, char**);
	char **env_get(shell_t*);
	item_t *env_get_var(shell_t*, char*);
	void env_add_var(shell_t*, char*, char*);
	void env_remove_var(shell_t*, char*);
	void parse(shell_t*, char*, int, int);
	void path_update(shell_t*);
	void path_show(shell_t*);
	void path_manual_init(shell_t*);
	int global_execute(char*, char**, char**);
	bool is_builtin(char *input);
	builtin_func_t builtin_func(char *input);
	void builtin_set(shell_t*, char**);
	void builtin_set_print(shell_t*);
	void builtin_set_print_last(shell_t*);
	void builtin_unset(shell_t*, char**);
	void builtin_alias(shell_t*, char**);
	void builtin_if(shell_t*, char**);
	void builtin_cd(shell_t*, char**);
	void builtin_setenv(shell_t*, char**);
	void builtin_unsetenv(shell_t*, char**);
	void builtin_env(shell_t*, char**);
	void builtin_exit(shell_t*, char**);
	void builtin_repeat(shell_t *, char **);
	void builtin_if(shell_t *, char **);
	void builtin_which(shell_t *shell, char **input);
	void builtin_where(shell_t *shell, char **input);
	void builtin_foreach(shell_t *shell, char **input);
	void builtin_echo(shell_t *shell, char **input);
	void builtin_builtins(shell_t *shell, char **input);
	void builtin_set_add_var(shell_t *shell, char *name, char *data);
	void input_handler(shell_t *box, char **input);
	void main_exit(shell_t*);
	int raw_execute(char**, char**);
	void output_not_found(char*);
	token_t *token_parser(token_t*, char*, shell_t *);
	void token_exec(token_t*, int, int, shell_t*);
	void executer(shell_t*);
	void op_exec_colon(int, token_t*, shell_t*);
	void op_exec_pipe(int, token_t*, shell_t*);
	void op_exec_right(int, token_t*, shell_t*);
	void op_exec_left(int, token_t*, shell_t*);
	void op_exec_dright(int, token_t*, shell_t*);
	void op_exec_dleft(int, token_t*, shell_t*);
	void set_pipes(int, int, bool);
	void set_pipes_receiver(int, int, int);
	char **my_lexer(char *to_lex);
	int error_red(char**, shell_t*);
	bool termcaps_init(shell_t*, char**);
	void termcaps_end(shell_t*);
	char *termcaps(shell_t*);
	char *pull_next_line(char**);
	int globbing(shell_t*, node_t**);
	node_t *node_add(node_t**, node_t*, char*);
	char **analyse_input(shell_t*, char**);
	void builtin_unalias(shell_t*, char**);
	int check_alias(shell_t*, node_t**);
	void free_alias(alias_t*);
	void alias_free_all(shell_t*);
	void vars_free_all(shell_t*);
	void clear_quote(char*);
	void clear_quote_tab(char**);
	void destroy_alias(void*);
	void variable_destroy(void*);
	char *variable_get(shell_t*, char*);
	int check_var(shell_t*, node_t**);
	void print_space_alias(char*);
	void op_exec_and(int inc, token_t *token, shell_t *shell);
	void op_exec_or(int inc, token_t *token, shell_t *shell);
	int check_env_var(char**, char*, shell_t*);
	char *add_quote_func(char *str);
	int my_str_where_contains(char *str, char c);
	void str_remove_char(char *str, char x);
#endif
