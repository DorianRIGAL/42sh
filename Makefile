##
## EPITECH PROJECT, 2017
## Project mysh
## File description:
## Build mysh binary.
##

MAIN_SRC	=	src/main.c

SRC	=	src/utils/my_is_clear.c		\
		src/utils/clear_quote.c		\
		src/utils/add_quote_func.c		\
		src/modules/environment.c	\
		src/modules/shell.c		\
		src/modules/path.c		\
		src/modules/parser.c		\
		src/modules/free.c		\
		src/modules/exec.c		\
		src/modules/variable.c		\
		src/modules/env_variable.c		\
		src/modules/glob.c		\
		src/modules/alias.c		\
		src/modules/analyse_input.c	\
		src/builtins/builtins.c	\
		src/builtins/variables.c	\
		src/builtins/variables_tools.c	\
		src/builtins/directory.c	\
		src/builtins/enviro.c		\
		src/builtins/exit.c		\
		src/builtins/alias.c		\
		src/builtins/repeat.c		\
		src/builtins/which.c		\
		src/builtins/where.c		\
		src/builtins/unalias.c		\
		src/builtins/foreach.c		\
		src/builtins/echo.c		\
		src/builtins/conditionals.c	\
		src/modules/tokenize.c		\
		src/modules/executer.c		\
		src/utils/pull_line.c		\
		src/utils/cutter.c		\
		src/utils/pipes.c		\
		src/utils/box_to_str.c		\
		src/operations/op_exec_base.c	\
		src/operations/op_exec_dirs.c	\
		src/error/ambiguous_redir.c	\
		src/error/exotic_redir_cor.c	\
		src/error/str_arr_to_str.c	\
		src/error/error.c		\
		src/error/error_dep.c		\
		src/error/free_str_arr.c		\
		src/error/missing_name.c	\
		src/error/whose_sep.c	\
		src/error/paranthesis_v2.c		\
		src/error/exotic_redirection.c		\
		src/error/lexer/lexer_count.c	\
		src/error/lexer/lexer_fill.c	\
		src/error/lexer/lexer_malloc.c	\
		src/error/lexer/lexer.c		\
		src/termcaps/termcaps.c		\
		src/termcaps/termcaps_func.c	\
		src/termcaps/term.c		\
		src/termcaps/list.c		\
		src/termcaps/print_node.c	\
		src/termcaps/display.c		\
		src/termcaps/check_input.c	\
		src/termcaps/start_exec.c	\
		src/termcaps/free.c		\
		src/termcaps/list_tool.c	\
		src/termcaps/history.c		\
		src/termcaps/arrow.c		\
		src/termcaps/tabulation.c	\
		src/termcaps/get_env.c		\
		src/termcaps/search_char_in_array.c	\
		src/termcaps/get_binary.c	\
		src/termcaps/path_list.c	\
		src/termcaps/check_bin.c	\
		src/termcaps/path_completion.c	\
		src/termcaps/completion.c	\

OBJ	=	$(MAIN_SRC:.c=.o) $(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -I ./include/

LDFLAGS	=	-l ncurses -L ./src/lib/ -l leo

NAME	=	42sh

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./src/lib/
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	make clean -C ./src/lib/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./src/lib/
	rm -f $(NAME)

re:	fclean all
