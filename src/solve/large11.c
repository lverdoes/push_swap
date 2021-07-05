/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   large11.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:35:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/05 13:52:41 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>

static inline int	group_nrs(t_vars *v, t_stack *s, int ac, ...)
{
	static size_t const n_groups = 11;
	int					i;
	size_t				arg;
	va_list				list;
	size_t				rank;
	double				top;
	double				bottom;

	top = (double)v->total_size / n_groups;
	bottom = (double)v->total_size / n_groups;
	va_start(list, ac);
	i = 0;
	while (i < ac)
	{
		rank = ((t_elem *)s->head->content)->rank;
		arg = (size_t)va_arg(list, int);
		if (rank < top * arg && rank >= bottom * (arg - 1))
		{
			va_end(list);
			return (1);
		}
		i++;
	}
	va_end(list);
	return (0);
}

static inline int	group_n(t_vars *v, t_stack *s, size_t low, size_t high)
{
	static size_t const n_groups = 11;
	double				top;
	double				bottom;
	size_t				rank;

	rank = ((t_elem *)s->head->content)->rank;
	top = (double)v->total_size / n_groups * high;
	bottom = (double)v->total_size / n_groups * (low - 1);
	if (rank < top && rank >= bottom)
		return (1);
	return (0);
}

static inline int	group_a(t_vars *v, t_stack *stack)
{
	int const size = 5;

	if (group_nrs(v, stack, size, 1, 2, 7, 10, 11))
		return (1);
	return (0);
}

static inline void	part_5(t_vars *v)
{
	while (!group_n(v, &v->b, 6, 6))
	{
		if (group_n(v, &v->b, 1, 1))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_n(v, &v->a, 11, 11))
			{
				if (group_n(v, &v->b, 1, 1))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static inline void	part_4(t_vars *v)
{
	while (!group_n(v, &v->a, 8, 8))
	{
		if (group_n(v, &v->a, 10, 10))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, &v->b, 2, 2))
			{
				if (group_n(v, &v->a, 10, 10))
					cmd(RR, 1);
				else
					cmd(RB, 1);
			}
		}
	}
}

static inline void	part_3(t_vars *v)
{
	while (!group_a(v, &v->a))
	{
		if (group_n(v, &v->a, 9, 9))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, &v->b, 3, 3))
			{
				if (group_n(v, &v->a, 9, 9))
					cmd(RR, 1);
				else
					cmd(RB, 1);
			}
		}
	}
}

static inline void	part_2(t_vars *v)
{
	while (!group_n(v, &v->b, 5, 5))
	{
		if (group_n(v, &v->b, 4, 4))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_n(v, &v->a, 8, 8))
			{
				if (group_n(v, &v->b, 4, 4))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static inline void	part_1(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (group_a(v, &v->a))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, &v->b, 5, 5))
			{
				if (group_a(v, &v->a))
				{
					cmd(RR, 1);
					i++;
				}
				else
					cmd(RB, 1);
			}
		}
		i++;
	}
}

int	solve_large11(t_vars *v)
{
	part_1(v);
	part_2(v);
	part_3(v);
	part_4(v);
	part_5(v);
	solve_medium(v);
	return (1);
}
