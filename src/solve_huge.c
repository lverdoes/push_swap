/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_huge.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:57:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/08 15:47:38 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	phase_one(t_vars *v)
{
	size_t	i;

	i = 0;
	while (i < v->total_size)
	{
		if (group_a(v, v->a))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_c(v, v->b))
			{
				if (group_a(v, v->a))
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
	phase_one(v);
	phase_two(v);
	phase_three(v);
	return (solve_medium(v));
}
