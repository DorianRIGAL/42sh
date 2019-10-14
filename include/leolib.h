/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** All the personal library prototypes.
*/

#ifndef LEOLIB_H_
	#define LEOLIB_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <fcntl.h>
	#include <stdbool.h>
	#define UNUSED __attribute__((unused))
	#define READ_SIZE (1)

	typedef struct node {
		int id;
		void *data;
		struct node *next;
	} node_t;

	typedef struct list {
		node_t *head;
		int size;
	} list_t;

	typedef void(*destroy_node_data_t)(void*);

	int len(char*);
	int put_str(char*);
	int put_err(char*);
	void my_putchar(char);
	int my_char_isnum(char);
	int my_str_isalpha(char const*);
	int my_put_nbr(long long);
	int put_str_at(char*, int);
	int my_getnbr(char const*);
	int my_count_nbr(long long);
	void my_swap_int(int*, int*);
	int my_str_isnum(char const*);
	void my_sort_int_array(int*, int);
	void my_swap_str(char**, char**);
	int my_strcmp(char const*, char const*);
	int my_strcmp_till(char const*, char const*, int);
	char *my_str_num(int);
	char *my_strdup(char*);
	char *my_revstr(char*);
	char *get_next_line(int);
	char *concat(char*, char*);
	char *my_strlowcase(char*);
	char *my_strcpy(char*, char*);
	char *concat_free(char*, char*);
	char *my_strncpy(char*, char const*, int);
	char **my_strcut(char*, char);
	char **my_strcut_at(char*, int);
	char **my_sort_words(char*, char);
	char **my_str_to_word_array(char*, char);
	char **my_tabdup(char **);
	list_t *list_init(void);
	void *list_get(list_t*, int);
	void list_push(list_t*, void*);
	int my_tab_len(char **);
	char *my_strcat_space(char*, char*);
	void clear_quote(char*);
	void delete_node(list_t*, char*, destroy_node_data_t);
	void *get_node(list_t*, char*);
	void add_node_sort(list_t*, void*);
	char *my_strndup(char*, int);
	char *my_str_nbr(int);
	void check_spec(char, int[3]);
#endif
