/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_large_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 00:59:56 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/10 01:21:21 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_top_third(t_vars *v)
{
	t_elem	*e;
	double	top;

	e = v->a->content;
	top = (double)(v->total_size / 5) * 4;
	if (e->rank > top)
		return (1);
	return (0);
}

static int	is_bottom_third(t_vars *v)
{
	t_elem	*e;
	double	top;

	e = v->b->content;
	top = (double)(v->total_size / 5) * 3;
	if (e->rank < top)
		return (1);
	return (0);
}

void	split_large_thirds(t_vars *v)
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
