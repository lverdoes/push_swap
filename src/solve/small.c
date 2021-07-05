/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 18:18:28 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/05 13:01:48 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solve_3(t_vars *v)
{
	if (is_correct_rotation_order(&v->a))
		return (shortest_path(&v->a, v->a.pos_low, 0));
	cmd(SA, 1); //swap_routine(v);
	if (v->a.pos_low == 2)
		cmd(RRA, 1);
	else if (v->a.pos_high == 0)
		cmd(RA, 1);
	return (0);
}

static int	solve_4(t_vars *v)
{
	if (is_correct_rotation_order(&v->a))
		return (shortest_path(&v->a, v->a.pos_low, 0));
	shortest_path(&v->a, v->a.pos_low, 0);
	cmd(PB, 1);
	if (v->a.size > 3)
		solve_4(v);
	if (v->a.size == 3)
		solve_3(v);
	cmd(PA, 1);
	return (0);
}

int	solve_small(t_vars *v)
{
	if (v->a.size > 3)
		return (solve_4(v));
	if (v->a.size == 3)
		return (solve_3(v));
	if (v->a.pos_low == 1)
		cmd(SA, 1);
	return (0);
}
