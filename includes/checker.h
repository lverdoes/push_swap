/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:24:14 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/05 14:04:32 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
#include <stdio.h>

# define MEDIUM 15
# define LARGE 45
# define HUGE 200

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
}	t_data;

typedef struct s_variables
{
	t_node	*a;
	t_node	*b;
	size_t	size_a;
	size_t	size_b;
	size_t	total_size;
	t_node	*sorted;
	size_t	max_rank;
	size_t	gr_a;
	size_t	gr_b;
	size_t	gr_c;
	t_node	*last_a;
	t_node	*last_b;
	size_t	low_a;
	size_t	high_b;
	t_data	data;
}	t_vars;

typedef struct s_args
{
	char	**args;
	size_t	size;
}	t_args;

/*		output	*/
void	print_stacks(t_vars *v, char *next_cmd);
void	print_data(t_vars *v);

/*		input	*/
void	check_args(t_args *a, int argc, char **argv);
void	init(t_vars *v, size_t size, char **argv);
void	read_instruction(t_vars *v, char const *const line);

/*		sorting	*/
int		rotate_left_or_right(t_vars *v, t_node *stack);
int		is_correct_rotation_order(t_vars *v, int exception);
int		is_ordered_a(t_vars *v, size_t len);
int		is_ordered_b(t_vars *v, size_t len);
size_t	find_highest_rank(t_node *stack);
size_t	find_lowest_rank(t_node *stack);

/*		solve	*/
int		solve(t_vars *v);
int		solve_small(t_vars *v);
int		solve_medium(t_vars *v, size_t limit);
int		solve_large(t_vars *v);
int		solve_huge(t_vars *v);
int		group_n(t_vars *v, t_node *stack, size_t low, size_t high);
int		is_group_x(t_vars *v, t_node *stack);
int		is_group_a(t_vars *v, t_node *stack);
int		is_group_b(t_vars *v, t_node *stack);
int		is_group_c(t_vars *v, t_node *stack);


/*		errors	*/
void	ft_exit(char *str);
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
void	ra(t_vars *v);
void	rb(t_vars *v);
void	rr(t_vars *v);

/*		reverse rotate	*/
void	rra(t_vars *v);
void	rrb(t_vars *v);
void	rrr(t_vars *v);

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
