/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** main.h
*/

#ifndef TERMS_H_
	#define TERMS_H_

	#include <unistd.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
	#include <sys/types.h>
	#include <dirent.h>
	#include <sys/stat.h>
	#include "term_list.h"
	#include "leolib.h"
	#include <termios.h>

	typedef struct path_s {
		char *path;
		struct path_s *next;
	} path_t;

	typedef struct ctx_s {
		struct termios term;
		int path_len;
		term_list_t *list;
		int cursor_pos;
		term_node_t *save;
		term_node_t *tmp;
		path_t *bin;
		int col;
		int line_save;
		int pos_relative[2];
	} ctx_t;

	typedef struct tab_s {
		char key;
		void (*ptr)(ctx_t *ctx, char buffer[3]);
	} tab_t;

	void	search_in_history(ctx_t *ctx);
	void	check_input(char buffer[3], ctx_t *ctx, int *lock);
	void	backspace(ctx_t *ctx, char buffer[3]);
	void	arrow(ctx_t *ctx, char buffer[3]);
	void	redirection(ctx_t *ctx, char buffer[3]);
	char	*start_exec(ctx_t *ctx);
	void	manage_history(ctx_t *ctx);
	void	go_end(ctx_t *ctx, char buffer[3]);
	void	go_begining(ctx_t *ctx, char buffer[3]);
	void	clear_screen(ctx_t *ctx, char buffer[3]);
	void	copy(ctx_t *ctx, char buffer[3]);
	void	paste(ctx_t *ctx, char buffer[3]);
	void	tabulation(ctx_t *ctx, char buffer[3]);
	char	*get_env(char *name, char **env);
	char	**str_to_tab(char *str, char *cut, int opt);
	int	search_char_in_array(char c, char *array);
	path_t	*add_path(path_t *next, char *name);
	void	get_binary(ctx_t *ctx, char **env);
	path_t	*check_bin(ctx_t *ctx, char *end);
	path_t	*check_folder(ctx_t *ctx, char *path, char *end);
	void	path_completion(ctx_t *ctx, char *end, path_t *list);
	char	*get_current_path(ctx_t *ctx, char *tmp);
	void	free_path(path_t *path);
	void	free_all_term(ctx_t ctx);
	int	cmp_begin_list(term_node_t *l1, term_node_t *l2);
	void	move_cursor(ctx_t *ctx);
	void	completion(ctx_t *ctx);
	void	supression(ctx_t *ctx);
	void	backspace(ctx_t *ctx, UNUSED char buffer[4]);
	void	go_end(ctx_t *ctx, UNUSED char buffer[4]);
	void	go_begining(ctx_t *ctx, UNUSED char buffer[4]);
	void	clear_screen(UNUSED ctx_t *ctx, UNUSED char buffer[4]);
#endif
