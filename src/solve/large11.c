/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   large11.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:35:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/12 18:35:17 by lverdoes      ########   odam.nl         */
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

static inline int	group_range(t_vars *v, t_stack *s, size_t low, size_t high)
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

static inline int	group_n(t_vars *v, t_stack *s, size_t group)
{
	static size_t const n_groups = 11;
	double				top;
	double				bottom;
	size_t				rank;

	rank = ((t_elem *)s->head->content)->rank;
	top = (double)v->total_size / n_groups * group;
	bottom = (double)v->total_size / n_groups * (group - 1);
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
	size_t	counter;

	counter = 0;
	while (!group_n(v, &v->b, 6))
	{
		if (group_n(v, &v->b, 1))
		{
			if (counter > 0)
			{
				counter--;
				cmd(RR, 1);
			}
			else
				cmd(RB, 1);
		}
		else if (group_n(v, &v->b, 11))
		{
			cmd(PA, 1);
			counter++;
		}
		else
		{
			if (counter > 0)
				cmd(RA, counter);
			counter = 0;
			cmd(PA, 1);
		}
	}
	cmd(RA, counter);
}

static inline void	part_4(t_vars *v)
{
	size_t	counter;

	counter = 0;
	while (!group_n(v, &v->a, 8))
	{
		if (group_n(v, &v->a, 10))
		{
			if (counter > 0)
			{
				counter--;
				cmd(RR, 1);
			}
			else
				cmd(RA, 1);
		}
		else if (group_n(v, &v->a, 2))
		{
			cmd(PB, 1);
			counter++;
		}
		else
		{
			if (counter > 0)
				cmd(RB, counter);
			counter = 0;
			cmd(PB, 1);
		}
	}
	cmd(RB, counter);
}

static inline void	part_3(t_vars *v)
{
	size_t	counter;

	counter = 0;
	while (!group_a(v, &v->a))
	{
		if (group_n(v, &v->a, 9))
		{
			if (counter > 0)
			{
				counter--;
				cmd(RR, 1);
			}
			else
				cmd(RA, 1);
		}
		else if (group_n(v, &v->a, 3))
		{
			cmd(PB, 1);
			counter++;
		}
		else
		{
			if (counter > 0)
				cmd(RB, counter);
			counter = 0;
			cmd(PB, 1);
		}
	}
	cmd(RB, counter);
}

static inline void	part_2(t_vars *v)
{
	size_t	counter;

	counter = 0;
	while (!group_n(v, &v->b, 5))
	{
		if (group_n(v, &v->b, 4))
		{
			if (counter > 0)
			{
				counter--;
				cmd(RR, 1);
			}
			else
				cmd(RB, 1);
		}
		else if (group_n(v, &v->b, 8))
		{
			cmd(PA, 1);
			counter++;
		}
		else
		{
			if (counter > 0)
				cmd(RA, counter);
			counter = 0;
			cmd(PA, 1);
		}
	}
	cmd(RA, counter);
}

static inline void	part_1(t_vars *v)
{
	size_t	i;
	size_t	size;
	size_t	counter;

	counter = 0;
	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (group_a(v, &v->a))
		{
			if (counter > 0)
			{
				counter--;
				cmd(RR, 1);
			}
			else
				cmd(RA, 1);
		}
		else if (group_n(v, &v->a, 5))
		{
			cmd(PB, 1);
			counter++;
		}
		else
		{
			if (counter > 0)
				cmd(RB, counter);
			counter = 0;
			cmd(PB, 1);
		}
		i++;
	}
	cmd(RB, counter);
}

int	solve_large11(t_vars *v)
{
	part_1(v);
	part_2(v);
	part_3(v);
	part_4(v);
	part_5(v);
	solve_medium(&v->a, &v->b);
	return (1);
}
