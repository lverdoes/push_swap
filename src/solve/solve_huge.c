/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_huge.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:57:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/29 23:31:02 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int group_n(t_vars *v, t_node *stack, size_t num)
{
	t_elem	*e;
	double	top;
	double	bottom;

	e = stack->content;
	top = (double)v->total_size / 23 * num;
	bottom = (double)v->total_size / 23 * (num - 1);
	if (e->rank < top && e->rank >= bottom)
		return (1);
	return (0);
}

static int	is_group_a(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 7))
		return (1);
	if (group_n(v, stack, 8))
		return (1);
	if (group_n(v, stack, 9))
		return (1);
	if (group_n(v, stack, 10))
		return (1);
	if (group_n(v, stack, 13))
		return (1);
	if (group_n(v, stack, 14))
		return (1);
	if (group_n(v, stack, 15))
		return (1);
	if (group_n(v, stack, 16))
		return (1);
	if (group_n(v, stack, 17))
		return (1);
	return (0);
}

static int	is_group_b(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 4))
		return (1);
	if (group_n(v, stack, 5))
		return (1);
	if (group_n(v, stack, 6))
		return (1);
	if (group_n(v, stack, 12))
		return (1);
	if (group_n(v, stack, 18))
		return (1);
	if (group_n(v, stack, 19))
		return (1);
	if (group_n(v, stack, 20))
		return (1);
	return (0);
}

static int	is_group_c(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 1))
		return (1);
	if (group_n(v, stack, 2))
		return (1);
	if (group_n(v, stack, 3))
		return (1);
	if (group_n(v, stack, 11))
		return (1);
	if (group_n(v, stack, 21))
		return (1);
	if (group_n(v, stack, 22))
		return (1);
	if (group_n(v, stack, 23))
		return (1);
	return (0);
}

static void	split_huge_part_11(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (group_n(v, v->b, 10))
			return ;
		if (group_n(v, v->b, 1))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 23))
			{
				if (group_n(v, v->b, 1))
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

static void	split_huge_part_10(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 12))
			return ;
		if (group_n(v, v->a, 22))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 2))
			{
				if (group_n(v, v->a, 22))
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

static void	split_huge_part_9(t_vars *v) // start c group
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (group_n(v, v->b, 10))
			return ;
		if (group_n(v, v->b, 3))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 21))
			{
				if (group_n(v, v->b, 3))
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

static void	split_huge_part_8(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_c(v, v->b))
			return ;
		if (group_n(v, v->b, 4))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 20))
			{
				if (group_n(v, v->b, 4))
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

static void	split_huge_part_7(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 13))
			return ;
		if (group_n(v, v->a, 19))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 5))
			{
				if (group_n(v, v->a, 19))
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

static void	split_huge_part_6(t_vars *v) // start b group
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_c(v, v->b))
			return ;
		if (group_n(v, v->b, 6))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 18))
			{
				if (group_n(v, v->b, 6))
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

static void	split_huge_part_5(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_b(v, v->b))
			return ;
		if (group_n(v, v->b, 7))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 17))
			{
				if (group_n(v, v->b, 7))
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

static void	split_huge_part_4(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 14))
			return ;
		if (group_n(v, v->a, 16))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 8))
			{
				if (group_n(v, v->a, 16))
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

static void	split_huge_part_3(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_b(v, v->b))
			return ;
		if (group_n(v, v->b, 9))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 15))
			{
				if (group_n(v, v->b, 9))
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

static void	split_huge_part_2(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 14))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 10))
			{
				if (group_n(v, v->a, 14))
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

static void	split_huge_part_1(t_vars *v)
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

int	solve_huge(t_vars *v)
{
	split_huge_part_1(v);
	split_huge_part_2(v);
	split_huge_part_3(v);
	split_huge_part_4(v);
	split_huge_part_5(v);
	split_huge_part_6(v);
	split_huge_part_7(v);
	split_huge_part_8(v);
	split_huge_part_9(v);
	split_huge_part_10(v);
	split_huge_part_11(v);
	solve_medium(v, 4);
	return (1);
}
