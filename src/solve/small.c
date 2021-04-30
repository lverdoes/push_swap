/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_small.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 18:18:28 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/29 23:49:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	solve_3(t_vars *v)
{
	t_elem	*e;

	if (is_correct_rotation_order(v))
		return (rotate_left_or_right(v, v->a.head));
	e = v->a.head->content;
	if (e->rank == 1 + v->a.low)
		return (cmd_sa(v));
	if (e->rank == find_highest_rank(v->a.head))
	{
		cmd_sa(v);
		return (cmd_rra(v));
	}
	cmd_sa(v);
	cmd_ra(v);
	return (cmd_papa(v));
}

static int	solve_4_plus(t_vars *v)
{
	t_elem	*e;

	if (is_correct_rotation_order(v))
		return (rotate_left_or_right(v, v->a.head));
	e = v->a.head->content;
	if (e->rank != v->a.low)
		rotate_left_or_right(v, v->a.head);
	cmd_pb(v);
	if (v->a.size == 3)
		solve_3(v);
	else
		solve_4_plus(v);
	return (cmd_papa(v));
}

int	solve_small(t_vars *v)
{
	if (finished(v))
		return (1);
	if (v->a.size > 3)
		return (solve_4_plus(v));
	if (v->a.size == 3)
		return (solve_3(v));
	return (cmd_sa(v));
}
