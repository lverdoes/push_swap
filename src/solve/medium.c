/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 21:38:51 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 19:00:31 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	rotate_direction_b(t_vars *v, size_t target)
{
	size_t	counter;
	size_t	mid;
	t_node	*tmp;
	t_elem	*e;

	counter = 0;
	mid = v->b.size / 2;
	tmp = v->b.head;
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

static int	rotate_direction(t_vars *v, size_t target)
{
	size_t	counter;
	size_t	mid;
	t_node	*tmp;
	t_elem	*e;

	counter = 0;
	mid = v->a.size / 2;
	tmp = v->a.head;
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

int	cmd_papa(t_vars *v)
{
	t_elem	*e;
	int		rot;

	while (v->b.head)
	{
		if (swap_routine_check(v))
			continue ;
		rot = rotate_direction_b(v, v->b.high);
		if (rot == 1)
			cmd_rrb(v);
		else if (rot == -1)
			cmd_rb(v);
		e = v->b.head->content;
		if (e->rank == v->b.high)
			cmd_pa(v);
	}
	return (1);
}

int	solve_medium(t_vars *v, size_t limit)
{
	size_t	scope;
	t_elem	*e;
	int		rot;

	while (v->a.size > MEDIUM)
	{
		e = v->a.head->content;
		scope = v->a.low + limit;
		if (e->rank <= scope)
			cmd_pb(v);
		rot = rotate_direction(v, v->a.low);
		if (rot == 1)
			cmd_rra(v);
		else if (rot == -1)
			cmd_ra(v);
	}
	solve_small(v);
	return (cmd_papa(v));
}
