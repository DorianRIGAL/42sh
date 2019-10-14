/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#ifndef ERROR_H_
	#define ERROR_H_

	typedef struct op_s {
		int id;
		char op;
	} op_t;

	int is_a_redirect(char *str);
	int is_a_redipipe(char *str);
	int is_pipe_and_or(char *str);
	int is_a_sep(char *path, int i);
	int is_sep(char *str);
	int missing_name_redirect(char **arr);
	int ambiguous_redirect(char **arr);
	int error_paranthesis(char **arg);
	int is_if_fill(char *str);
	int is_if(char *str, int i);
	int is_cmd_sep(char *str);
	void free_str_arr(char **arr);
	char **modif_exotic_redirec(char **arg, int pos);
	int tablen(char **tab);
	char **exotic_redir_cor(char **arr);
	int is_redir_in_par(char **arr, int i);

	int badly_place_paranthesis(char **arr);
	int too_many_paranthesis(char **arr);
	int ambiguous_redirect_error(char **arr, int i);
	int ambiguous_pipe_error(char **arr, int i);
	int missing_name_error(char **arr, int i);
	int invalid_command_error_dep(char **arr, int i);

	char **fill_sem_arr_core(int j, int *k, char **arr);
	int is_finish(char *str, int i);
	void pass_space_and_tab(char *path, int *i);
	int is_a_sep(char *path, int i);
	char **malloc_sem_arr(char *to_lex);
	int separator(char c);
	int count_semicolon(char *to_lex);
	int shift_quote(char *str, int i, int *to_malloc);
	char **fill_sem_arr(char **arr, char *to_lex);

	char *str_arr_to_str(char **arr);
#endif