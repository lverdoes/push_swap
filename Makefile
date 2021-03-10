# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/03 15:09:36 by lverdoes      #+#    #+#                  #
#    Updated: 2021/03/10 12:17:05 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	checker
NAME_2		=	push_swap

LIBFT_DIR	=	libft/
LIBFT		=	libft.a
INCL_DIR	=	incl/
INCL		=	-I $(INCL_DIR) -I $(LIBFT_DIR)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -pedantic -O3 $(INCL)

SRC_DIR		=	src/
OBJ_DIR		=	obj/
SUBO_DIR	=	obj/cmds obj/errors obj/groups obj/input obj/solve obj/sorting

COMMON_SRC	=	input/check_args.c \
				errors/check_duplicate.c \
				errors/exit.c \
				input/init.c \
				cmds/push.c \
				cmds/reverse_rotate.c \
				cmds/rotate.c \
				cmds/swap.c \
				utils.c

SRC_FILES_1	=	main_checker.c \
				input/read_instruction.c \
				$(COMMON_SRC)

SRC_FILES_2	=	main_push_swap.c \
				cmds/cmd_rev_rot.c \
				cmds/cmd_rot.c \
				cmds/cmd_push_swap.c \
				solve/solve.c \
				solve/solve_small.c \
				solve/solve_medium.c \
				solve/solve_large.c \
				solve/solve_large_utils.c \
				solve/solve_huge.c \
				solve/solve_huge_phase_two.c \
				solve/solve_huge_phase_three.c \
				sorting/rotation_order.c \
				sorting/is_ordered.c \
				sorting/find_high_low.c \
				groups/groups.c \
				groups/group_a.c \
				groups/group_b.c \
				groups/group_c.c \
				$(COMMON_SRC)

SRC_1 		=	$(addprefix $(SRC_DIR), $(SRC_FILES_1))
SRC_2 		=	$(addprefix $(SRC_DIR), $(SRC_FILES_2))
OBJ_1 		=	$(SRC_1:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJ_2 		=	$(SRC_2:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME) $(NAME_2)

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR) $(SUBO_DIR)
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

py: all
	python3 ./tester/pyviz.py `ruby -e "puts (0..500).to_a.shuffle.join(' ')"`

arg: all
	@./push_swap $($@) | ./checker $($@)
	@./push_swap $($@) | wc -l
