/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   huge49.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:57:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/12 10:35:04 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>

static inline int	group_nrs(t_vars *v, t_stack *s, int ac, ...)
{
	static size_t const n_groups = 49;
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
	static size_t const n_groups = 49;
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

/*
	a = 7-9, 11, 20-22, 26, 28-30, 39, 41-43
	b = 4-6, 12, 17-19, 25, 31-33, 38, 44-46
	c = 1-3, 13-16, 24, 34-37, 47-49
	x = 10, 23, 27, 40
*/

static inline int	group_x(t_vars *v, t_stack *stack)
{
	int const size = 4;

	if (group_nrs(v, stack, size, 10, 23, 27, 40))
		return (1);
	return (0);
}

static inline int	group_a(t_vars *v, t_stack *stack)
{
	int const size = 15;

	if (group_nrs(v, stack, size, 7, 8, 9, 11, 20, 21, 22, 26, 28, 29, 30, 39, 41, 42, 43))
		return (1);
	return (0);
}

static inline int	group_b(t_vars *v, t_stack *stack)
{
	int const size = 15;

	if (group_nrs(v, stack, size, 4, 5, 6, 12, 17, 18, 19, 25, 31, 32, 33, 38, 44, 45, 46))
		return (1);
	return (0);
}

static inline int	group_c(t_vars *v, t_stack *stack)
{
	int const size = 15;

	if (group_nrs(v, stack, size, 1, 2, 3, 13, 14, 15, 16, 24, 34, 35, 36, 37, 47, 48, 49))
		return (1);
	return (0);
}

static inline void	part_finish(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (group_n(v, &v->a, 37, 49))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, &v->b, 1, 13))
			{
				if (group_n(v, &v->a, 37, 49))
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

static inline void	part_11(t_vars *v)
{
	while (!group_x(v, &v->b))
	{
		if (group_n(v, &v->b, 14, 14))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_nrs(v, &v->a, 3, 1, 36, 49))
			{
				if (group_n(v, &v->b, 14, 14))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static inline void	part_10(t_vars *v)
{
	while (!group_b(v, &v->a))
	{
		if (group_nrs(v, &v->a, 3, 2, 35, 48))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, &v->b, 15, 15))
			{
				if (group_nrs(v, &v->a, 3, 2, 35, 48))
					cmd(RR, 1);
				else
					cmd(RB, 1);
			}
		}
	}
}

static inline void	part_9(t_vars *v)
{
	while (!group_x(v, &v->b))
	{
		if (group_n(v, &v->b, 16, 16))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_nrs(v, &v->a, 3, 3, 34, 47))
			{
				if (group_n(v, &v->b, 16, 16))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static inline void	part_8(t_vars *v)
{
	while (!group_c(v, &v->b))
	{
		if (group_n(v, &v->b, 17, 17))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_nrs(v, &v->a, 3, 4, 33, 46))
			{
				if (group_n(v, &v->b, 17, 17))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static inline void	part_7(t_vars *v)
{
	while (!group_a(v, &v->a))
	{
		if (group_nrs(v, &v->a, 3, 5, 32, 45))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, &v->b, 18, 18))
			{
				if (group_nrs(v, &v->a, 3, 5, 32, 45))
					cmd(RR, 1);
				else
					cmd(RB, 1);
			}
		}
	}
}

static inline void	part_6(t_vars *v)
{
	while (!group_c(v, &v->b))
	{
		if (group_n(v, &v->b, 19, 19))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_nrs(v, &v->a, 3, 6, 31, 44))
			{
				if (group_n(v, &v->b, 19, 19))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static inline void	part_5(t_vars *v)
{
	while (!group_b(v, &v->b))
	{
		if (group_n(v, &v->b, 20, 20))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_nrs(v, &v->a, 3, 7, 30, 43))
			{
				if (group_n(v, &v->b, 20, 20))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static inline void	part_4(t_vars *v)
{
	while (!group_nrs(v, &v->a, 3, 10, 27, 40))
	{
		if (group_nrs(v, &v->a, 3, 8, 29, 42))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, &v->b, 21, 21))
			{
				if (group_nrs(v, &v->a, 3, 8, 29, 42))
					cmd(RR, 1);
				else
					cmd(RB, 1);
			}
		}
	}
}

static inline void	part_3(t_vars *v)
{
	while (!group_b(v, &v->b))
	{
		if (group_n(v, &v->b, 22, 22))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_nrs(v, &v->a, 3, 9, 28, 41))
			{
				if (group_n(v, &v->b, 22, 22))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static inline void	part_x(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (group_nrs(v, &v->a, 3, 10, 27, 40))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, &v->b, 23, 23))
			{
				if (group_nrs(v, &v->a, 3, 10, 27, 40))
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

static inline void	part_xabc(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (group_x(v, &v->a) || group_a(v, &v->a))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_c(v, &v->b))
			{
				if (group_x(v, &v->a) || group_a(v, &v->a))
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

int	solve_huge49(t_vars *v)
{
	part_xabc(v);
	part_x(v);
	part_3(v);
	part_4(v);
	part_5(v);
	part_6(v);
	part_7(v);
	part_8(v);
	part_9(v);
	part_10(v);
	part_11(v);
	part_finish(v);
	solve_medium(&v->a, &v->b);
	return (1);
}
