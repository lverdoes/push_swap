/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:24:14 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/01 00:50:14 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define MEDIUM 15
# define LARGE 45
# define HUGE 200
# define BONUS 0

# define SPACE " "
# define SPLIT_CHARS " \n\t"
# define ERROR "Error"

# define FALSE 0
# define TRUE 1

# define COLOR_SA 	"\e[38;5;105msa\e[33;0m"
# define COLOR_SB	"\e[38;5;46msb\e[33;0m"
# define COLOR_SS 	"\e[38;5;51mss\e[33;0m"
# define COLOR_PA 	"\e[38;5;196mpa\e[33;0m"
# define COLOR_PB	"\e[38;5;190mpb\e[33;0m"
# define COLOR_RA	"\e[38;5;214mra\e[33;0m"
# define COLOR_RB	"\e[38;5;98mrb\e[33;0m"
# define COLOR_RR	"\e[38;5;220mrr\e[33;0m"
# define COLOR_RRA	"\e[38;5;205mrra\e[33;0m"
# define COLOR_RRB	"\e[38;5;226mrrb\e[33;0m"
# define COLOR_RRR	"\e[38;5;206mrrr\e[33;0m"

# include "ft_node.h"

typedef struct s_element
{
	size_t	rank;
	int		num;
}	t_elem;

typedef struct s_data
{
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
	int	total_push;
	int	total_rots;
	int	total_swap;
	int	total;
}	t_data;

typedef struct s_args
{
	char	**args;
	size_t	size;
}	t_args;

typedef struct s_options
{
	int		color;
	int		data;
	int		file;
	int		help;
	int		instr;
	int		instr_fd;
	int		verbose;
}	t_opt;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
	size_t	high;
	size_t	low;
}	t_stack;

typedef struct s_variables
{
	t_stack	a;
	t_stack	b;
	size_t	total_size;
	size_t	max_rank;
	t_node	*sorted;
	t_args	args;
	t_opt	opt;
	t_data	data;
}	t_vars;

/*		bonus	*/
void	print_stacks(t_vars *v, char *next_cmd);
void	print_data(t_vars *v);
int		read_color_instruction(t_vars *v, char *line);
int		option_help(void);
int		cmd_file_option(t_vars *v, char **argv, int start);
int		file_option(t_vars *v, char **argv, int start, char **str);
int		search_options(t_vars *v, int argc, char **argv);
int		get_option(t_vars *v, char *str);

/*		input	*/
void	check_args(t_vars *v, int argc, char **argv);
void	init_stacks(t_vars *v, size_t size, char **argv);
int		read_instruction(t_vars *v, char *line);

/*		sorting	*/
size_t	find_highest_rank(t_node *stack);
size_t	find_lowest_rank(t_node *stack);
int		rotate_left_or_right(t_vars *v, t_node *stack);
int		is_correct_rotation_order(t_vars *v);

/*		solve_small	*/
int		solve_small(t_vars *v);

/*		solve_medium	*/
int		solve_medium(t_vars *v, size_t limit);
int		swap_routine_check(t_vars *v);

/*		solve_large	*/
int		solve_large(t_vars *v);
void	split_large_part_1(t_vars *v);
void	split_large_part_2(t_vars *v);
void	split_large_part_3(t_vars *v);
void	split_large_part_4(t_vars *v);
void	split_large_part_5(t_vars *v);
int		large_is_group_a(t_vars *v, t_node *stack);
int		large_group_n(t_vars *v, t_node *stack, size_t num);

/*		solve_huge	*/
int		solve_huge(t_vars *v);
void	split_huge_part_xabc(t_vars *v);
void	split_huge_part_x(t_vars *v);
void	split_huge_part_3(t_vars *v);
void	split_huge_part_4(t_vars *v);
void	split_huge_part_5(t_vars *v);
void	split_huge_part_6(t_vars *v);
void	split_huge_part_7(t_vars *v);
void	split_huge_part_8(t_vars *v);
void	split_huge_part_9(t_vars *v);
void	split_huge_part_10(t_vars *v);
int		group_n(t_vars *v, t_node *stack, size_t low, size_t high);
int		is_group_x(t_vars *v, t_node *stack);
int		is_group_a(t_vars *v, t_node *stack);
int		is_group_b(t_vars *v, t_node *stack);
int		is_group_c(t_vars *v, t_node *stack);

/*		errors	*/
int		ft_exit(char *str);
void	check_minmax_int(char *str);
void	check_malloc(void *ptr);
void	check_digits(char *str);
void	check_duplicate(t_vars *v, int num);

/*		utils	*/
void	swap(t_elem *a, t_elem *b);
int		intcmp(t_elem *a, t_elem *b);
int		rankcmp(int *ref, t_elem *e);
int		finished(t_vars *v);

/*		swap	*/
int		sa(t_vars *v);
int		sb(t_vars *v);
int		ss(t_vars *v);

/*		push	*/
int		pa(t_vars *v);
int		pb(t_vars *v);

/*		rotate	*/
int		ra(t_vars *v);
int		rb(t_vars *v);
int		rr(t_vars *v);

/*		reverse rotate	*/
int		rra(t_vars *v);
int		rrb(t_vars *v);
int		rrr(t_vars *v);

/*		call cmds	*/
int		cmd_sa(t_vars *v);
int		cmd_sb(t_vars *v);
int		cmd_ss(t_vars *v);
int		cmd_pa(t_vars *v);
int		cmd_papa(t_vars *v);
int		cmd_pb(t_vars *v);
int		cmd_pb(t_vars *v);
int		cmd_ra(t_vars *v);
int		cmd_rb(t_vars *v);
int		cmd_rr(t_vars *v);
int		cmd_rra(t_vars *v);
int		cmd_rrb(t_vars *v);
int		cmd_rrr(t_vars *v);

#endif
