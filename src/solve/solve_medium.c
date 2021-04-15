/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_medium.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 21:38:51 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/15 14:12:38 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	swap_routine_check(t_vars *v)
{
	t_elem	*first;
	t_elem	*second;
	t_elem	*third;
	t_elem	*fourth;
	size_t	target;

	if (!v->b->next)
		return (0);
	target = v->high_b;
	first = v->b->content;
	second = v->b->next->content;
	if (second->rank == target)
	{
		if (first->rank + 1 == target)
		{
			if (v->b->next->next && v->b->next->next->next)
			{
				third = v->b->next->next->content;
				fourth = v->b->next->next->next->content;
				if (third->rank + 3 == target && fourth->rank + 2 == target)
				{
					cmd_pa(v);
					cmd_pa(v);
					cmd_ss(v);
					cmd_pa(v);
					cmd_pa(v);
					return (1);
				}
			}
			cmd_sb(v);
			cmd_pa(v);
			cmd_pa(v);
			return (1);
		}
		cmd_sb(v);
		cmd_pa(v);
		return (1);
	}
	return (0);
}

static int	rotate_direction_b(t_vars *v, size_t target)
{
	size_t	counter;
	size_t	mid;
	t_node	*tmp;
	t_elem	*e;

	counter = 0;
	mid = v->size_b / 2;
	tmp = v->b;
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

int	cmd_papa(t_vars *v)
{
	t_elem	*e;
	int 	rot;

	while (v->b)
	{
		if (swap_routine_check(v))
			continue ;
		rot = rotate_direction_b(v, v->high_b);
		if (rot == 1)
			cmd_rrb(v);
		else if (rot == -1)
			cmd_rb(v);
		e = v->b->content;
		if (e->rank == v->high_b)
			cmd_pa(v);
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
		scope = v->low_a + limit;
		if (e->rank <= scope)
			cmd_pb(v);
		rot = rotate_direction(v, v->low_a);
		if (rot == 1)
			cmd_rra(v);
		else if (rot == -1)
			cmd_ra(v);
	}
	solve_small(v);
	return (cmd_papa(v));
}
