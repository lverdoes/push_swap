# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/04 13:12:33 by lverdoes      #+#    #+#                  #
#    Updated: 2021/07/03 15:33:50 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
FLAGS	= -Wall -Wextra -Werror
STRICT	= -std=c99 -pedantic
UNUSED	= -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function
INCL	= includes

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
	ft_free.c \
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
	ft_getfile.c \
	get_next_line.c

LIST = \
	ft_list_add_back.c \
	ft_list_add_front.c \
	ft_list_combine.c \
	ft_list_del_all.c \
	ft_list_del_one.c \
	ft_list_dup.c \
	ft_list_find.c \
	ft_list_insert_after.c \
	ft_list_insert_before.c \
	ft_list_insert_sort.c \
	ft_list_is_sorted.c \
	ft_list_iter.c \
	ft_list_index.c \
	ft_list_join.c \
	ft_list_last.c \
	ft_list_new.c \
	ft_list_number.c \
	ft_list_remove_if.c \
	ft_list_remove_one.c \
	ft_list_size.c \
	ft_list_sort.c \
	ft_list_unlink.c \
	ft_list_print.c

TRIE = \
	ft_trie_clear.c \
	ft_trie_del_one.c \
	ft_trie_find.c \
	ft_trie_new.c \
	ft_trie_size_content.c \
	ft_trie_size_nodes.c

SRC_DIRS = \
	$(addprefix mandatory/, $(MANDATORY)) \
	$(addprefix ext/, $(EXT)) \
	$(addprefix gnl/, $(GNL)) \
	$(addprefix list/, $(LIST)) \
	$(addprefix trie/, $(TRIE))

OBJ_DIRS = \
	obj \
	obj/mandatory \
	obj/ext \
	obj/gnl \
	obj/list \
	obj/trie

SRC	= $(addprefix src/, $(SRC_DIRS))
OBJ = $(SRC:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Created $@\x1b[1A\x1b[M"

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIRS)
	@gcc $(FLAGS) $(STRICT) -I$(INCL) -c $< -o $@ 
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

test: re all
	gcc $(FLAGS) $(UNUSED) -I$(INCL) main.c $(NAME)
	@./a.out
