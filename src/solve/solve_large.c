/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_large.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:35:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/27 17:02:25 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int group_n(t_vars *v, t_node *stack, size_t num)
{
	t_elem	*e;
	double	top;
	double	bottom;

	e = stack->content;
	top = (double)v->total_size / 11 * num;
	bottom = (double)v->total_size / 11 * (num - 1);
	if (e->rank < top && e->rank >= bottom)
		return (1);
	return (0);
}

static int	is_group_a(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 1))
		return (1);
	if (group_n(v, stack, 2))
		return (1);
	if (group_n(v, stack, 7))
		return (1);
	if (group_n(v, stack, 10))
		return (1);
	if (group_n(v, stack, 11))
		return (1);
	return (0);
}

static void	split_large_part_5(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (group_n(v, v->b, 6))
			return ;
		if (group_n(v, v->b, 1))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 11))
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

static void	split_large_part_4(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 8))
			return ;
		if (group_n(v, v->a, 10))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 2))
			{
				if (group_n(v, v->a, 10))
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

static void	split_large_part_3(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (is_group_a(v, v->a))
			return ;
		if (group_n(v, v->a, 9))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 3))
			{
				if (group_n(v, v->a, 9))
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

static void	split_large_part_2(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (group_n(v, v->b, 5))
			return ;
		if (group_n(v, v->b, 4))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 8))
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

static void	split_large_part_1(t_vars *v)
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
			if (group_n(v, v->b, 5))
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

int	solve_large(t_vars *v)
{
	split_large_part_1(v);
	split_large_part_2(v);
	split_large_part_3(v);
	split_large_part_4(v);
	split_large_part_5(v);
	solve_medium(v, 2);
	return (1);
}
