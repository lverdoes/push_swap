/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 18:18:28 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/14 10:33:47 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solve_3(t_stack *a, t_stack *b)
{
	if (is_correct_rotation_order(a))
		return (shortest_path(a, a->pos_low, 0));
	cmd(SA, 1); //swap_routine(a, b);
	if (a->pos_low == 2)
		cmd(RRA, 1);
	else if (a->pos_high == 0)
		cmd(RA, 1);
	return (0);
}

static int	solve_4(t_stack *a, t_stack *b)
{
	if (is_correct_rotation_order(a))
		return (shortest_path(a, a->pos_low, 0));
	shortest_path(a, a->pos_low, 0);
	cmd(PB, 1);
	if (a->size > 3)
		solve_4(a, b);
	if (a->size == 3)
		solve_3(a, b);
	cmd(PA, 1);
	return (0);
}

int	solve_small(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		return (solve_3(a, b));
	if (a->size > 3)
		return (solve_4(a, b));
	if (a->pos_low == 1)
		cmd(SA, 1);
	return (0);
}
