/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   huge49edit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:57:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/06 00:44:35 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>

static inline int	group_nrs(t_vars *v, t_stack *s, int ac, ...)
{
	static double const n_groups = 49;
	int					i;
	double				arg;
	va_list				list;
	double				rank;
	double				top;
	double				bottom;

	top = (double)v->total_size / n_groups;
	bottom = (double)v->total_size / n_groups;
	va_start(list, ac);
	i = 0;
	while (i < ac)
	{
		rank = ((t_elem *)s->head->content)->rank;
		arg = (double)va_arg(list, int);
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

static inline int	group_n(t_vars *v, t_stack *s, double low, double high)
{
	static double const n_groups = 49;
	double				top;
	double				bottom;
	double				rank;

	rank = ((t_elem *)s->head->content)->rank;
	top = (double)v->total_size / n_groups * high;
	bottom = (double)v->total_size / n_groups * (low - 1);
	if (rank < top && rank >= bottom)
		return (1);
	return (0);
}

static inline int	group_7_up(t_vars *v, t_stack *stack)
{
	if (group_n(v, stack, 12, 15))
		return (1);
	if (group_n(v, stack, 20, 23))
		return (1);
	if (group_n(v, stack, 35, 38))
		return (1);
	return (0);
}

static inline int	group_13_up(t_vars *v, t_stack *stack)
{
	if (group_n(v, stack, 9, 11))
		return (1);
	if (group_n(v, stack, 24, 26))
		return (1);
	if (group_n(v, stack, 39, 41))
		return (1);
	return (0);
}

static inline int	group_mid_a(t_vars *v, t_stack *stack)
{
	int const size = 3;

	if (group_nrs(v, stack, size, 8, 27, 42))
		return (1);
	return (0);
}

static inline int	group_13_low(t_vars *v, t_stack *stack)
{
	if (group_n(v, stack, 5, 7))
		return (1);
	if (group_n(v, stack, 28, 30))
		return (1);
	if (group_n(v, stack, 43, 45))
		return (1);
	return (0);
}

static inline int	group_7_low(t_vars *v, t_stack *stack)
{
	if (group_n(v, stack, 1, 4))
		return (1);
	if (group_n(v, stack, 31, 34))
		return (1);
	if (group_n(v, stack, 46, 49))
		return (1);
	return (0);
}

static inline int	group_mid_b(t_vars *v, t_stack *stack)
{
	if (group_n(v, stack, 16, 19))
		return (1);
	return (0);
}

static inline int	group_7a(t_vars *v, t_stack *stack)
{
	int const size = 7;

	if (group_nrs(v, stack, size, 19, 12, 23, 38, 4, 31, 46))
		return (1);
	return (0);
}

static inline int	group_7b(t_vars *v, t_stack *stack)
{
	int const size = 7;

	if (group_nrs(v, stack, size, 18, 13, 22, 37, 3, 32, 47))
		return (1);
	return (0);
}

static inline int	group_7c(t_vars *v, t_stack *stack)
{
	int const size = 7;

	if (group_nrs(v, stack, size, 17, 14, 21, 36, 2, 33, 48))
		return (1);
	return (0);
}

static inline int	group_7d(t_vars *v, t_stack *stack)
{
	int const size = 7;

	if (group_nrs(v, stack, size, 16, 15, 20, 35, 1, 34, 49))
		return (1);
	return (0);
}

static inline int	group_13a(t_vars *v, t_stack *stack)
{
	int const size = 6;

	if (group_7b(v, stack))
		return (1);
	if (group_nrs(v, stack, size, 9, 26, 41, 7, 28, 43))
		return (1);
	return (0);
}

static inline int	group_13b(t_vars *v, t_stack *stack)
{
	int const size = 6;

	if (group_7c(v, stack))
		return (1);
	if (group_nrs(v, stack, size, 10, 25, 40, 6, 29, 44))
		return (1);
	return (0);
}

static inline int	group_13c(t_vars *v, t_stack *stack)
{
	int const size = 6;

	if (group_7d(v, stack))
		return (1);
	if (group_nrs(v, stack, size, 11, 24, 39, 5, 30, 45))
		return (1);
	return (0);
}

static inline int	group_a(t_vars *v, t_stack *stack)
{
	if (group_7a(v, stack))
		return (1);
	if (group_13a(v, stack))
		return (1);
	return (0);
}

static inline void	part_3(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (group_n(v, &v->a, 35, 49))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, &v->b, 1, 15))
			{
				if (group_n(v, &v->a, 35, 49))
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

static inline void	part_7(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->b.size;
	while (i < size)
	{
		if (group_mid_b(v, &v->b))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_7_low(v, &v->a))
			{
				if (group_mid_b(v, &v->b))
				{
					cmd(RR, 1);
					i++;
				}
				else
					cmd(RA, 1);
			}
		}
		i++;
	}
}

static inline void	part_13(t_vars *v)
{
	while (!group_7a(v, &v->b))
	{
		if (group_7b(v, &v->b) || group_7c(v, &v->b) || group_7d(v, &v->b))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_13_low(v, &v->a))
			{
				if (group_7b(v, &v->b) || group_7c(v, &v->b) || group_7d(v, &v->b))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static inline void	part_23(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (group_mid_a(v, &v->a))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_7a(v, &v->b))
			{
				if (group_mid_a(v, &v->a))
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

static inline void	part_49(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (group_mid_a(v, &v->a) || group_a(v, &v->a))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_13c(v, &v->b))
			{
				if (group_mid_a(v, &v->a) || group_a(v, &v->a))
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

int	solve_huge49edit(t_vars *v)
{
	part_49(v);
	part_23(v);
	part_13(v);
	part_7(v);
	part_3(v);
	solve_medium(v);
	return (1);
}
