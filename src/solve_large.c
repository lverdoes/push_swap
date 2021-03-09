/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_large.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:35:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/09 23:58:50 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_first_quarter(t_vars *v)
{
	t_elem	*e;
	double	quarter;
	
	e = v->b->content;
	quarter = (double)(v->total_size) / 4;
	if (e->rank < quarter)
		return (1);
	return (0);
}

int	is_top_half(t_vars *v, t_node *stack)
{
	t_elem	*e;
	double	half;

	e = stack->content;
	half = (double)(v->total_size) / 2;
	if (e->rank > half)
		return (1);
	return (0);
}

void split_50_25_25(t_vars *v)
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

int	is_top_third(t_vars *v)
{
	t_elem	*e;
	double	top;

	e = v->a->content;
	top = (double)(v->total_size / 3) * 2;
	if (e->rank > top)
		return (1);
	return (0);
}

int	is_bottom_third(t_vars *v)
{
	t_elem	*e;
	double	top;

	e = v->b->content;
	top = (double)(v->total_size / 3) * 2;
	if (e->rank < top)
		return (1);
	return (0);
}

void split_thirds(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (is_top_third(v))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (is_bottom_third(v))
			{
				if (is_top_third(v))
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
	split_50_25_25(v);
	split_thirds(v);
	solve_medium(v);
	return (1);
}
