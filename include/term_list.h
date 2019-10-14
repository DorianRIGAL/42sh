/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** TERM_list.h
*/

#ifndef TERM_LIST_H_
	#define TERM_LIST_H_

	typedef struct term_node_s {
		char data;
		struct term_node_s *next;
		struct term_node_s *prev;
	} term_node_t;

	typedef struct term_list_s {
		term_node_t *head;
		int size;
		struct term_list_s *next;
		struct term_list_s *prev;
	} term_list_t;

	term_list_t	*add_list(term_list_t *prev);
	int	add_node(term_list_t *list, char data, int index);
	void	delete_node_term(term_list_t *list, int index);
	void	print_node(term_list_t *list);
	char	*from_list_to_array(term_list_t *list);
	void	free_node(term_node_t *node);
	void	cut_list(term_list_t *list);
	term_node_t	*cp_list(term_node_t *list);
	int	get_list_len(term_node_t *list);
	int	cmp_list(term_node_t *l1, term_node_t *l2);
#endif
