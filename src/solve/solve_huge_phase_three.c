/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_huge_phase_three.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:54:55 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/10 01:37:27 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	phase_three_b(t_vars *v, size_t *i)
{
	if (group_small(v, v->b, 1))
		cmd_rb(v);
	else
	{
		cmd_pa(v);
		if (group_small(v, v->a, 5))
		{
			if (group_small(v, v->b, 1))
			{
				cmd_rr(v);
				i++;
			}
			else
				cmd_ra(v);
		}
	}
}

static void	phase_three_c(t_vars *v, size_t *i)
{
	if (group_small(v, v->b, 0))
		cmd_rb(v);
	else
	{
		cmd_pa(v);
		if (group_small(v, v->a, 3))
		{
			if (group_small(v, v->b, 0))
			{
				cmd_rr(v);
				i++;
			}
			else
				cmd_ra(v);
		}
	}
}

void	phase_three(t_vars *v)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	tmp = v->size_b;
	while (i < tmp)
	{
		if (group_b3(v, v->b))
			phase_three_b(v, &i);
		else
			phase_three_c(v, &i);
		i++;
	}
}
