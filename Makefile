# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/03 15:09:36 by lverdoes      #+#    #+#                  #
#    Updated: 2021/04/30 20:26:08 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CH			=	checker
PS			=	push_swap

LIBFT_DIR	=	libft
LIBFT		=	libft.a
INCL_DIR	=	includes
INCL		=	-I $(INCL_DIR) -I $(LIBFT_DIR)/$(INCL_DIR)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -O3 $(INCL)

SRC_DIR		=	src
OBJ_DIR		=	obj
SUBO_DIR	=	obj/cmds obj/errors obj/groups obj/input obj/solve obj/sorting \
				obj/bonus

COMMON_SRC	=	input/check_args.c \
				errors/check_ints.c \
				errors/exit.c \
				input/init_stacks.c \
				cmds/push.c \
				cmds/reverse_rotate.c \
				cmds/rotate.c \
				cmds/swap.c \
				sorting/find_high_low.c \
				bonus/read_color_instructions.c \
				utils.c

SRC_F_CH	=	checker.c \
				input/read_instruction.c \
				$(COMMON_SRC)

SRC_F_PS	=	push_swap.c \
				cmds/cmd_rev_rot.c \
				cmds/cmd_rot.c \
				cmds/cmd_push_swap.c \
				solve/small.c \
				solve/medium.c \
				solve/large.c \
				solve/large_utils.c \
				solve/huge.c \
				solve/huge_part_1_5.c \
				solve/huge_part_6_10.c \
				solve/huge_utils.c \
				sorting/rotation_order.c \
				sorting/swap_routine.c \
				$(COMMON_SRC)

SRC_F_BO	=	\
				bonus/options.c \
				bonus/print_stacks.c \
				bonus/print_data.c \
				bonus/help.c

SRC_CH 		=	$(addprefix $(SRC_DIR)/, $(SRC_F_CH))
SRC_PS 		=	$(addprefix $(SRC_DIR)/, $(SRC_F_PS))
SRC_BO	 	=	$(addprefix $(SRC_DIR)/, $(SRC_F_BO))
OBJ_CH 		=	$(SRC_CH:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJ_PS 		=	$(SRC_PS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJ_BO 		=	$(SRC_BO:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

ifeq ($(BONUS),1)
	COMMON_SRC += SRC_F_BO
endif

all: $(CH) $(PS)

$(NAME): $(CH) $(PS)

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR) $(SUBO_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)/$(LIBFT) .

$(CH): $(LIBFT) $(OBJ_CH)
	$(CC) $(FLAGS) -o $(CH) $(LIBFT) $(OBJ_CH)

$(PS): $(LIBFT) $(OBJ_PS)
	$(CC) $(FLAGS) -o $(PS) $(LIBFT) $(OBJ_PS)

.PHONY: clean fclean re

clean:
	/bin/rm -rf $(OBJ_DIR)
	@/bin/rm -f .DS_Store

fclean: clean
	/bin/rm -f $(PS) $(CH)
##	/bin/rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

bonus:
	BONUS=1

py: all
	python3 pyviz.py `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`

arg: all
	@./push_swap $($@) | ./checker $($@)
	@./push_swap $($@) | wc -l
