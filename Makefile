# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/03 15:09:36 by lverdoes      #+#    #+#                  #
#    Updated: 2021/03/08 17:52:42 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	checker
NAME_2		=	push_swap

LIBFT_DIR	=	libft/
LIBFT		=	libft.a
INCL_DIR	=	incl/
INCL		=	-I $(INCL_DIR) -I $(LIBFT_DIR)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -pedantic $(INCL)

SRC_DIR		=	src/
OBJ_DIR		=	obj/

COMMON_SRC	=	check_args.c \
				check_duplicate.c \
				exit.c \
				init.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				swap.c \
				utils.c

SRC_FILES_1	=	main_checker.c \
				read_instruction.c \
				$(COMMON_SRC)

SRC_FILES_2	=	main_push_swap.c \
				solve.c \
				cmd_rev_rot.c \
				cmd_rot.c \
				cmd_push_swap.c \
				solve_small.c \
				solve_medium.c \
				solve_large.c \
				solve_huge.c \
				solve_huge_phase_two.c \
				solve_huge_phase_three.c \
				rotation_order.c \
				is_ordered.c \
				find_high_low.c \
				groups.c \
				group_b.c \
				group_c.c \
				$(COMMON_SRC)

SRC_1 		=	$(addprefix $(SRC_DIR), $(SRC_FILES_1))
SRC_2 		=	$(addprefix $(SRC_DIR), $(SRC_FILES_2))
OBJ_1 		=	$(SRC_1:$(SRC_DIR)%.c=$(OBJ_DIR%.o)
OBJ_2 		=	$(SRC_2:$(SRC_DIR)%.c=$(OBJ_DIR%.o)

all: $(NAME) $(NAME_2)

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)$(LIBFT) .

$(NAME): $(LIBFT) $(OBJ_1)
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(OBJ_1)

$(NAME_2): $(LIBFT) $(OBJ_2)
	$(CC) $(FLAGS) -o $(NAME_2) $(LIBFT) $(OBJ_2)

.PHONY: clean fclean re

clean:
	/bin/rm -rf $(OBJ_DIR)
	@/bin/rm -f .DS_Store

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME_2)
	/bin/rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all
