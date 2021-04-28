# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/04 13:12:33 by lverdoes      #+#    #+#                  #
#    Updated: 2021/04/09 15:45:12 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -I$(INCL) $(UNUSED)
INCL	= includes/
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

EXT = \
	ft_append.c \
	ft_array_size.c \
	ft_arraydup.c \
	ft_atod.c \
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
	ft_node_combine.c \
	ft_node_del_all.c \
	ft_node_del_one.c \
	ft_node_dup.c \
	ft_node_find.c \
	ft_node_insert_after.c \
	ft_node_insert_before.c \
	ft_node_insert_sort.c \
	ft_node_is_sorted.c \
	ft_node_iter.c \
	ft_node_index.c \
	ft_node_join.c \
	ft_node_last.c \
	ft_node_new.c \
	ft_node_number.c \
	ft_node_remove_if.c \
	ft_node_remove_one.c \
	ft_node_size.c \
	ft_node_sort.c \
	ft_node_unlink.c \
	ft_print_node_list.c

DICT = \
	ft_dict_clear.c \
	ft_dict_del_one.c \
	ft_dict_find.c \
	ft_dict_new.c \
	ft_dict_size_content.c \
	ft_dict_size_page.c

SRC_DIRS = \
	$(addprefix mandatory/, $(MANDATORY)) \
	$(addprefix ext/, $(EXT)) \
	$(addprefix gnl/, $(GNL)) \
	$(addprefix node/, $(NODE)) \
	$(addprefix dict/, $(DICT))

OBJ_DIRS = \
	obj \
	obj/mandatory \
	obj/ext \
	obj/gnl \
	obj/node \
	obj/dict

SRC	= $(addprefix src/, $(SRC_DIRS))
OBJ = $(SRC:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Created $@\x1b[1A\x1b[M"

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIRS)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "Compiling libft/$<\x1b[1A\x1b[1M"

.PHONY:	clean fclean re

clean:
	@/bin/rm -rf $(OBJ_DIRS)
	@echo "Deleted libft/obj"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f a.out
	@/bin/rm -f .DS_Store
	@echo "Deleted $(NAME)"
	@echo ""

re: fclean all

main: all
	$(CC) $(FLAGS) $(UNUSED) $(NAME) main.c
	@./a.out

test: main
