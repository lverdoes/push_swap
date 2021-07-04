/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:24:14 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 10:06:50 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MEDIUM 15
# define LARGE 45
# define HUGE 200

# define SPACE " "
# define SPLIT_CHARS "\n \t"
# define ERROR "Error"

# include "ft_list.h"
# include <stdio.h>

typedef enum e_id
{
	STACK_A,
	STACK_B,
}	t_id;

typedef enum e_cmd
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_cmd;

typedef struct s_eleminfo
{
	size_t	rank;
	size_t	index;
}	t_info;

typedef struct s_element
{
	size_t	rank;
	int		num;
}	t_elem;

typedef struct s_data
{
	int	count[11];
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

typedef struct s_stack
{
	t_list	*head;
	t_list	*tail;
	size_t	size;
	size_t	high;
	size_t	low;
	size_t	pos_high;
	size_t	pos_low;
	t_id	id;
}	t_stack;

typedef struct s_variables
{
	t_stack	a;
	t_stack	b;
	size_t	total_size;
	size_t	max_rank;
	t_list	*sorted;
	t_args	args;
	t_data	data;
	int		(*cmd[11])(struct s_variables *);
}	t_vars;

/*		errors	*/
int		ft_exit(char *str);
void	check_minmax_int(char *str);
void	check_malloc(void *ptr);
void	check_digits(char *str);
void	check_duplicate(t_vars *v, int num);

/*		new	*/
void	check_args(t_vars *v, int argc, char **argv);
void	init(t_vars *v, size_t size, char **argv);
void	**cmd(t_cmd cmd, int amount);
void	print_data(t_vars *v);

/*		utils	*/
int		intcmp(t_elem *a, t_elem *b);
int		rankcmp(int *ref, t_elem *e);
int		finished(t_stack *a, t_stack *b);

/*		sorting	*/
int		shortest_path(t_stack *s, size_t pos, size_t limit);
void	find_lowest_rank(t_stack *s);
void	find_highest_rank(t_stack *s);
int		is_correct_rotation_order(t_stack *s);

/*		to be deleted	*/
int		rotate_left_or_right(t_vars *v, t_list *stack);

/*		solve_small	*/
int		solve_small(t_vars *v);

/*		solve_medium	*/
int		push_back(t_vars *v);
int		swap_routine_check(t_vars *v);
int		solve_medium(t_vars *v, size_t limit);

/*		solve_large	*/
int		solve_large(t_vars *v);
int		large_is_group_a(t_vars *v, t_list *stack);
int		large_group_n(t_vars *v, t_list *stack, size_t num);

/*		solve_huge	*/
int		solve_huge(t_vars *v);
int		group_n(t_vars *v, t_list *stack, size_t low, size_t high);
int		is_group_x(t_vars *v, t_list *stack);
int		is_group_a(t_vars *v, t_list *stack);
int		is_group_b(t_vars *v, t_list *stack);
int		is_group_c(t_vars *v, t_list *stack);



#endif
