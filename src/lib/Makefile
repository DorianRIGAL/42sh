##
## EPITECH PROJECT, 2018
## Leo Library
## File description:
## Build Library.
##

SRC	=	get_next_line.c		\
		lists.c			\
		my_getnbr.c		\
		my_put_nbr.c		\
		my_putchar.c		\
		my_putstr.c		\
		my_str_isnum.c		\
		my_str_to_word_array.c	\
		str_to_word_array_tool.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcut.c		\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncpy.c		\
		my_swap.c		\
		my_sort.c		\
		my_strcpy.c		\
		my_str_rev.c		\
		my_str_nbr.c		\
		my_str_isalpha.c	\
		my_tab_len.c		\
		my_strcat_space.c	\
		list_tool.c		\
		my_tabdup.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libleo.a

CFLAGS	=	-Werror -Wextra -W -Wall -I ../../include/

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
