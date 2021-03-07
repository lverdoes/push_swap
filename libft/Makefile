# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/04 13:12:33 by lverdoes      #+#    #+#                  #
#    Updated: 2021/03/05 16:54:53 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
HEADERS = libft.h
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -pedantic -I.
UNUSED	= -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function

MANDATORY =	\
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

LST = \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstfind.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \

EXT =	\
	ft_append.c \
	ft_array_size.c \
	ft_arraydup.c \
	ft_atod.c \
	ft_atoi_base.c \
	ft_concat_array.c \
	ft_counter.c \
	ft_free_array.c \
	ft_intdup.c \
	ft_iswhitespace.c \
	ft_print_array.c \
	ft_print_int_array.c \
	ft_realloc.c \
	ft_replace.c \
	ft_split_strchr.c \
	ft_split_strnstr.c \
	ft_str_contains_none.c \
	ft_str_contains_only.c \
	ft_str_to_lower.c \
	ft_str_to_upper.c \
	ft_strcmp.c \
	ft_strxjoin.c \
	ft_substrlen.c \
	ft_swap.c \
	ft_unique_chars.c

GNL = \
	ft_getline.c \
	get_next_line.c

NODE = \
	ft_node_add_back.c \
	ft_node_add_front.c \
	ft_node_del_all.c \
	ft_node_del_one.c \
	ft_node_dup.c \
	ft_node_find.c \
	ft_node_insert_after.c \
	ft_node_insert_before.c \
	ft_node_insert_sort.c \
	ft_node_is_sorted.c \
	ft_node_iter.c \
	ft_node_join.c \
	ft_node_last.c \
	ft_node_merge.c \
	ft_node_new.c \
	ft_node_number.c \
	ft_node_remove_if.c \
	ft_node_remove_one.c \
	ft_node_size.c \
	ft_node_sort.c \
	ft_node_unlink.c \
	ft_print_node_list.c

SORT = \
	ft_bubble_sort_int.c \
	ft_bubble_sort_str.c \
	ft_merge_sort_int.c \
	ft_merge_sort_str.c

SRC_DIRS = \
	$(addprefix mandatory/, $(MANDATORY)) \
	$(addprefix ext/, $(EXT)) \
	$(addprefix gnl/, $(GNL)) \
	$(addprefix lst/, $(LST)) \
	$(addprefix node/, $(NODE)) \
	$(addprefix sort/, $(SORT))

OBJ_DIRS = \
	obj \
	obj/mandatory \
	obj/ext \
	obj/gnl \
	obj/lst \
	obj/node \
	obj/sort

all: $(NAME)

SRC	= $(addprefix src/, $(SRC_DIRS))
OBJ = $(SRC:src/%.c=obj/%.o)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $?

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIRS)
	$(CC) $(FLAGS) -c $< -o $@

.PHONY:	clean fclean re

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f .DS_Store
	@/bin/rm -f a.out

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *.a
	@/bin/rm -rf $(OBJ_DIRS)

re: fclean all

main: all
	$(CC) $(FLAGS) $(UNUSED) $(NAME) main.c utils/*.c
	./a.out

test: main
