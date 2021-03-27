/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_medium.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 21:38:51 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/27 01:16:54 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	cmd_papa(t_vars *v)
{
	while (v->b)
	{
		rotate_left_or_right(v, v->b);
		cmd_pa(v);
	}
	return (1);
}

static int	rotate_direction(t_vars *v, size_t target)
{
	size_t	counter;
	size_t	mid;
	t_node	*tmp;
	t_elem	*e;

	counter = 0;
	mid = v->size_a / 2;
	tmp = v->a;
	e = tmp->content;
	if (e->rank == target)
		return (0);
	while (tmp)
	{
		e = tmp->content;
		if (e->rank == target)
		{
			if (counter > mid)
				break ;
			return (-1);
		}
		counter++;
		tmp = tmp->next;
	}
	return (1);
}

int	solve_medium(t_vars *v, size_t limit)
{
	size_t	scope;
	t_elem	*e;
	int		rot;

	while (v->size_a > MEDIUM)
	{
		e = v->a->content;
		scope = find_lowest_rank(v->a) + limit;
		if (e->rank <= scope)
			cmd_pb(v);
		rot = rotate_direction(v, find_lowest_rank(v->a));
		if (rot == 1)
			cmd_rra(v);
		else if (rot == -1)
			cmd_ra(v);
	}
	solve_small(v);
	return (cmd_papa(v));
}
