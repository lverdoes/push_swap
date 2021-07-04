/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 18:18:28 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 10:17:15 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solve_3(t_vars *v)
{
	if (is_correct_rotation_order(&v->a))				//	1 2 3,	2 3 1,	3 1 2
		return (shortest_path(&v->a, v->a.pos_low, 0));
	if (v->a.pos_low == 1)								//	2 1 3
	{
		cmd(SA, 1);
	}
	else if (v->a.pos_low == 2)							//	3 2 1
	{
		cmd(SA, 1);
		cmd(RRA, 1);
	}
	else												//	1 3 2
	{
		cmd(SA, 1);
		cmd(RA, 1);
	}
	return (0);
}

static int	solve_4_plus(t_vars *v)
{
	if (is_correct_rotation_order(&v->a))
		return (shortest_path(&v->a, v->a.pos_low, 0));
	while (v->a.size > 3)
	{
		shortest_path(&v->a, v->a.pos_low, 0);
		cmd(PB, 1);
	}
	solve_3(v);
	return (push_back(v));
}

int	solve_small(t_vars *v)
{
	if (v->a.size > 3)
		return (solve_4_plus(v));
	if (v->a.size == 3)
		return (solve_3(v));
	if (v->a.pos_low == 1)
		cmd(SA, 1);
	return (0);
}
