/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_large.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:35:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/10 01:21:35 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_first_quarter(t_vars *v)
{
	t_elem	*e;
	double	quarter;
	
	e = v->b->content;
	quarter = (double)(v->total_size) / 5;
	if (e->rank < quarter)
		return (1);
	return (0);
}

static int	is_top_half(t_vars *v, t_node *stack)
{
	t_elem	*e;
	double	half;

	e = stack->content;
	half = (double)(v->total_size) / 5 * 2;
	if (e->rank > half)
		return (1);
	return (0);
}

static void	split_60_20_20(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (is_top_half(v, v->a))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (is_first_quarter(v))
			{
				if (is_top_half(v, v->a))
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
	split_60_20_20(v);
	split_large_thirds(v);
	solve_medium(v);
	return (1);
}
