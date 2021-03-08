/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_large_phase_two.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:55:06 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/08 13:03:50 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	phase_two_b(t_vars *v, size_t *i)
{
	if (group_b3(v, v->b))
		cmd_rb(v);
	else
	{
		cmd_pa(v);
		if (group_b2(v, v->a))
		{
			if (group_b3(v, v->b))
			{
				cmd_rr(v);
				*i += 1;
			}
			else
				cmd_ra(v);
		}
	}
}

static void	phase_two_c(t_vars *v, size_t *i)
{
	if (group_c3(v, v->b))
		cmd_rb(v);
	else
	{
		cmd_pa(v);
		if (group_c2(v, v->a))
		{
			if (group_c3(v, v->b))
			{
				cmd_rr(v);
				*i += 1;
			}
			else
				cmd_ra(v);
		}
	}
}

void	phase_two(t_vars *v)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	tmp = v->size_b;
	while (i < tmp)
	{
		if (group_b(v, v->b))
			phase_two_b(v, &i);
		else
			phase_two_c(v, &i);
		i++;
	}
}
