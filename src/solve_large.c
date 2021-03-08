/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_large.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:35:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/08 17:50:52 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	part_two(t_vars *v)
{
	t_elem	*e;
	size_t	i;
	size_t	tmp;

	i = 0;
	tmp = v->size_b;
	while (i < tmp)
	{
		e = v->b->content;
		if (e->rank <= v->total_size / 7 * 3) //middle third
		{
			if (e->rank >= v->total_size / 7 * 6 / 3)
				cmd_rb(v);
			else
			{
				cmd_pa(v);
				if (1) //middle middle or top middle
				{
					
				}
			}
		}
		else	//bottom third
		{
			
		}
		i++;
	}
}

static void	part_one(t_vars *v)
{
	t_elem	*e;
	size_t	i;

	i = 0;
	while (i < v->total_size)
	{
		e = v->a->content;
		if (e->rank >= v->total_size / 7 * 6)	//top (1/7 / 85.7%)
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (e->rank < v->total_size / 7 * 3)	//bottom third (0-42.8%)
			{
				e = v->a->content;
				if (e->rank >= v->total_size / 7 * 6)	//middle third (42.8-85.7%)
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
	part_one(v);
	part_two(v);
	return (1);
}
