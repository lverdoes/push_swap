/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_huge_new.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:57:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/31 22:23:07 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int group_n(t_vars *v, t_node *stack, size_t num)
{
	t_elem	*e;
	double	top;
	double	bottom;

	e = stack->content;
	top = (double)v->total_size / 31 * num;
	bottom = (double)v->total_size / 31 * (num - 1);
	if (e->rank < top && e->rank >= bottom)
		return (1);
	return (0);
}

	// a		1	6	7	8	13	14	17	18	19	24	25	26	31
	// b				2	5	9	12	16	20	23	27	30
	// c				3	4	10	11	15	21	22	28	29

static int	is_group_a(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 1))
		return (1);
	if (group_n(v, stack, 6))
		return (1);
	if (group_n(v, stack, 7))
		return (1);
	if (group_n(v, stack, 8))
		return (1);
	if (group_n(v, stack, 13))
		return (1);
	if (group_n(v, stack, 14))
		return (1);
	if (group_n(v, stack, 17))
		return (1);
	if (group_n(v, stack, 14))
		return (1);
	if (group_n(v, stack, 18))
		return (1);
	if (group_n(v, stack, 19))
		return (1);
	if (group_n(v, stack, 24))
		return (1);
	if (group_n(v, stack, 25))
		return (1);
	if (group_n(v, stack, 26))
		return (1);
	if (group_n(v, stack, 31))
		return (1);
	return (0);
}

static int	is_group_b(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 2))
		return (1);
	if (group_n(v, stack, 5))
		return (1);
	if (group_n(v, stack, 9))
		return (1);
	if (group_n(v, stack, 12))
		return (1);
	if (group_n(v, stack, 16))
		return (1);
	if (group_n(v, stack, 20))
		return (1);
	if (group_n(v, stack, 23))
		return (1);
	if (group_n(v, stack, 27))
		return (1);
	if (group_n(v, stack, 30))
		return (1);
	return (0);
}

static int	is_group_c(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 3))
		return (1);
	if (group_n(v, stack, 4))
		return (1);
	if (group_n(v, stack, 10))
		return (1);
	if (group_n(v, stack, 11))
		return (1);
	if (group_n(v, stack, 15))
		return (1);
	if (group_n(v, stack, 21))
		return (1);
	if (group_n(v, stack, 22))
		return (1);
	if (group_n(v, stack, 28))
		return (1);
	if (group_n(v, stack, 29))
		return (1);
	return (0);
}

static void	split_huge_part_7(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 25) || group_n(v, v->a, 26) || group_n(v, v->a, 27) || group_n(v, v->a, 28) || group_n(v, v->a, 29) || group_n(v, v->a, 30) || group_n(v, v->a, 31))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 1) || group_n(v, v->b, 2) || group_n(v, v->b, 3) || group_n(v, v->b, 4) || group_n(v, v->b, 5) || group_n(v, v->b, 6) || group_n(v, v->b, 7))
			{
				if (group_n(v, v->a, 25) || group_n(v, v->a, 26) || group_n(v, v->a, 27) || group_n(v, v->a, 28) || group_n(v, v->a, 29) || group_n(v, v->a, 30) || group_n(v, v->a, 31))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_rb(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_6(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 7) || group_n(v, v->a, 18) || group_n(v, v->a, 25))
			return ;
		if (group_n(v, v->a, 1) || group_n(v, v->a, 2) || group_n(v, v->a, 3) || group_n(v, v->a, 22) || group_n(v, v->a, 23) || group_n(v, v->a, 24) || group_n(v, v->a, 29) || group_n(v, v->a, 30) || group_n(v, v->a, 31))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 8) || group_n(v, v->b, 9) || group_n(v, v->b, 10))
			{
				if (group_n(v, v->a, 1) || group_n(v, v->a, 2) || group_n(v, v->a, 3) || group_n(v, v->a, 22) || group_n(v, v->a, 23) || group_n(v, v->a, 24) || group_n(v, v->a, 29) || group_n(v, v->a, 30) || group_n(v, v->a, 31))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_rb(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_5(t_vars *v)	//c from b stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (group_n(v, v->b, 14))
			return ;
		if (group_n(v, v->b, 11))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 4) || group_n(v, v->a, 21) || group_n(v, v->a, 28))
			{
				if (group_n(v, v->b, 11))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_ra(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_4(t_vars *v)	// b from b stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_c(v, v->b))
			return ;
		if (group_n(v, v->b, 12))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 5) || group_n(v, v->a, 20) || group_n(v, v->a, 27))
			{
				if (group_n(v, v->b, 12))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_ra(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_3(t_vars *v)	//a from b stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_b(v, v->b))
			return ;
		if (group_n(v, v->b, 13))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 6) || group_n(v, v->a, 19) || group_n(v, v->a, 26))
			{
				if (group_n(v, v->b, 13))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_ra(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_2(t_vars *v)	//a from a stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 7) || group_n(v, v->a, 18) || group_n(v, v->a, 25))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 14))
			{
				if (group_n(v, v->a, 7) || group_n(v, v->a, 18) || group_n(v, v->a, 25))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_rb(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_abc(t_vars *v)	//abc from a stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (is_group_a(v, v->a))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (is_group_c(v, v->b))
			{
				if (is_group_a(v, v->a))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_rb(v);
			}
		}
		i++;
	}
}

int	solve_huge_new(t_vars *v)
{
	split_huge_part_abc(v);
	split_huge_part_2(v);
	split_huge_part_3(v);
	split_huge_part_4(v);
	split_huge_part_5(v);
	split_huge_part_6(v);
	split_huge_part_7(v);
	solve_medium(v, 4);
	return (1);
}
