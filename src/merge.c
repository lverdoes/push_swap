/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:35:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/09 22:30:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	swap_last_two(t_vars *v, size_t size)
{
	if (v->a && v->a->next && is_ordered_a(v, size))
	{
		if (v->b && v->b->next && is_ordered_b(v, size))
			cmd_ss(v);
		cmd_sa(v);	
	}
	else if (v->b && v->b->next && is_ordered_b(v, size))
		cmd_sb(v);
	return (1);
}

void	a_push_or_rot(t_vars *v, size_t size, size_t middle)
{
	size_t	i;
	t_elem	*e;

	i = 0;
	while (i < size)
	{
		e = v->b->content;
		if (e->rank >= middle)
			cmd_pa(v);
		else
			cmd_rb(v);
		i++;
	}
}

void	b_push_or_rot(t_vars *v, size_t size, size_t middle)
{
	size_t	i;
	t_elem	*e;

	i = 0;
	while (i < size)
	{
		e = v->a->content;
		if (e->rank >= middle)
			cmd_ra(v);
		else
			cmd_pb(v);
		i++;
	}
}

int	push_back(t_vars *v)
{
	t_elem	*ea;
	t_elem	*eb;

	if (!v->a)
		return (1);
	if (!v->b)
		return (0);
	ea = v->a->content;
	eb = v->b->content;
	if (eb->rank + 1 == ea->rank)
		return (1);
	return (0);
}

int	merge_routine(t_vars *v, size_t size, size_t low, size_t high)
{
	size_t	middle;
																// inp:	1 0 2
	if (size > 2)
	{
		middle = low + (high - low) / 2;						//	1
		b_push_or_rot(v, size, middle);
		merge_routine(v, size - size / 2, middle + 1, high);	//	2, 1+1, 2
		a_push_or_rot(v, size / 2, middle);						//	1, 1
		merge_routine(v, size / 2, low, middle);				//	1, 0, 1
	}
	swap_last_two(v, size);
	return (1);
}

int	solve_large(t_vars *v)
{
//	if (size == v->total_size)
//		split_into_three_groups(v, low, high);
	merge_routine(v, v->total_size, 0, v->max_rank);
	return (1);
}
