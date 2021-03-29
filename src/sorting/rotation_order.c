/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation_order.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 19:26:47 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/29 21:30:24 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	keep_rotating_rr(t_vars *v, t_node *node)
{
	t_elem	*e;
	size_t	target;

	if (node == v->a)
	{
		target = find_lowest_rank(v->a);
		e = v->a->content;
		while (e->rank != target)
		{
			cmd_rra(v);
			e = v->a->content;
		}
	}
	else
	{
		target = find_highest_rank(v->b);
		e = v->b->content;
		while (e->rank != target)
		{
			cmd_rrb(v);
			e = v->b->content;
		}
	}
	return (1);
}

static int	keep_rotating_r(t_vars *v, t_node *stack)
{
	t_elem	*e;
	size_t	target;

	if (stack == v->a)
	{
		target = find_lowest_rank(v->a);
		e = v->a->content;
		while (e->rank != target)
		{
			cmd_ra(v);
			e = v->a->content;
		}
	}
	else
	{
		target = find_highest_rank(v->b);
		e = v->b->content;
		while (e->rank != target)
		{
			cmd_rb(v);
			e = v->b->content;
		}
	}
	return (1);
}

static size_t	stack_length(t_vars *v, t_node *stack)
{
	if (stack == v->a)
		return (v->size_a);
	return (v->size_b);
}

int	rotate_left_or_right(t_vars *v, t_node *stack)
{
	t_node	*tmp;
	t_elem	*e;
	size_t	counter;
	size_t	mid;

	counter = 0;
	mid = stack_length(v, stack) / 2;
	tmp = stack;
	while (tmp)
	{
		e = tmp->content;
		if ((stack == v->a && e->rank == find_lowest_rank(stack)) || \
			(stack == v->b && e->rank == find_highest_rank(stack)))
		{
			if (counter > mid)
				break ;
			return (keep_rotating_r(v, stack));
		}
		counter++;
		tmp = tmp->next;
	}
	return (keep_rotating_rr(v, stack));
}
