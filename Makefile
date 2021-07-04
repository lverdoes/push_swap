# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/03 15:09:36 by lverdoes      #+#    #+#                  #
#    Updated: 2021/07/04 10:44:21 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CHECKER		=	checker_Mac

LIBFT_DIR	=	libft
LIBFT		=	libft.a
LIB			=	$(LIBFT_DIR)/$(LIBFT)
INCL_DIR	=	includes
SRC_DIR		=	src
OBJ_DIR		=	obj
SUB_DIR		=	obj/cmds obj/init obj/solve obj/solve_utils obj/utils

FLAGS		=	-Wall -Wextra -Werror -pedantic -O3 $(INCL)
INCL		=	-I $(INCL_DIR) -I $(LIBFT_DIR)/$(INCL_DIR)

SRC 		=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ 		=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

FILES		=	push_swap.c \
				cmds/cmd.c \
				cmds/push.c \
				cmds/reverse_rotate.c \
				cmds/rotate.c \
				cmds/swap.c \
				init/check_args.c \
				init/check_ints.c \
				init/init.c \
				solve_utils/find_high_low.c \
				solve_utils/push_back.c \
				solve_utils/rotation_order.c \
				solve_utils/shortest_path.c \
				solve_utils/swap_routine.c \
				solve/huge_utils.c \
				solve/huge.c \
				solve/large_utils.c \
				solve/large.c \
				solve/medium.c \
				solve/small.c \
				utils/print_data.c \
				utils/exit.c \
				utils/utils.c

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR) $(SUB_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

.PHONY: clean fclean re

clean:
	/bin/rm -rf $(OBJ_DIR)
	@/bin/rm -f .DS_Store

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

py: all
	python3 pyviz.py `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`

arg: all
	@./push_swap $($@) | ./$(CHECKER) $($@)
	@./push_swap $($@) | wc -l


##	max=500 ; export arg=`ruby -e "puts (1..$max).to_a.shuffle.join(' ')"` ; ./push_swap $arg | ./checker_Mac $arg ; ./push_swap $arg | wc -l
