/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_huge.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:57:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/16 16:47:59 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push_back(t_vars *v, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		cmd_pa(v);
		if (group_a3(v, v->a))
			cmd_ra(v);
		i++;
	}
}

static void	phase_one_a(t_vars *v)
{
	size_t	i;
	size_t	tmp;
	size_t	push_count;

	i = 0;
	push_count = 0;
	tmp = v->size_a;
	while (i < tmp)
	{
		if (group_a2(v, v->a))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			push_count++;
		}
		i++;
	}
	push_back(v, push_count);
}

static void	phase_one(t_vars *v, size_t * const i)
{
	if (group_a(v, v->a))
	{
		cmd_ra(v);
		v->gr_a++;
	}
	else
	{
		cmd_pb(v);
		if (group_c(v, v->b))
		{
			v->gr_c++;
			if (group_a(v, v->a))
			{
				cmd_rr(v);
				v->gr_a++;
				*i += 1;
			}
			else
				cmd_rb(v);
		}
		else
			v->gr_b++;
	}
}

int	solve_huge(t_vars *v)
{
	size_t	i;

	i = 0;
	while (i < v->total_size)
	{
		phase_one(v, &i);
		i++;
	}
	phase_one_a(v);
	phase_two(v);
	phase_three(v);
	return (solve_medium(v));
}
