/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation_order.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 19:26:47 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/29 23:49:03 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	keep_rotating_rr(t_vars *v, t_node *node)
{
	t_elem	*e;
	size_t	target;

	if (node == v->a.head)
	{
		target = v->a.low;
		e = v->a.head->content;
		while (e->rank != target)
		{
			cmd_rra(v);
			e = v->a.head->content;
		}
	}
	else
	{
		target = v->b.high;
		e = v->b.head->content;
		while (e->rank != target)
		{
			cmd_rrb(v);
			e = v->b.head->content;
		}
	}
	return (1);
}

static int	keep_rotating_r(t_vars *v, t_node *stack)
{
	t_elem	*e;
	size_t	target;

	if (stack == v->a.head)
	{
		target = v->a.low;
		e = v->a.head->content;
		while (e->rank != target)
		{
			cmd_ra(v);
			e = v->a.head->content;
		}
	}
	else
	{
		target = v->b.high;
		e = v->b.head->content;
		while (e->rank != target)
		{
			cmd_rb(v);
			e = v->b.head->content;
		}
	}
	return (1);
}

static size_t	stack_length(t_vars *v, t_node *stack)
{
	if (stack == v->a.head)
		return (v->a.size);
	return (v->b.size);
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
		if ((stack == v->a.head && e->rank == v->a.low) || \
			(stack == v->b.head && e->rank == v->b.high))
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

// int	is_correct_rotation_order(t_vars *v, int exception)		//original
// {
// 	t_node	*tmp;
// 	t_node	*next;
// 	t_elem	*e;
// 	t_elem	*e_next;

// 	tmp = v->a.head;
// 	next = tmp->next;
// 	while (tmp)
// 	{
// 		if (!tmp->next)
// 			next = v->a.head;
// 		e = tmp->content;
// 		e_next = next->content;
// 		if (e->rank > e_next->rank)
// 		{
// 			if (exception == 1)
// 				return (0);
// 			exception = 1;
// 		}
// 		tmp = tmp->next;
// 		if (tmp)
// 			next = tmp->next;
// 	}
// 	return (1);
// }

int	is_correct_rotation_order(t_vars *v)
{
	t_node	*tmp[2];
	t_elem	*elem[2];
	int		exception;

	tmp[0] = v->a.head;
	tmp[1] = tmp[0]->next;
	exception = 0;
	while (tmp[0])
	{
		if (!tmp[0]->next)
			tmp[1] = v->a.head;
		elem[0] = tmp[0]->content;
		elem[1] = tmp[1]->content;
		if (elem[0]->rank > elem[1]->rank)
		{
			if (exception == 1)
				return (0);
			exception = 1;
		}
		tmp[0] = tmp[0]->next;
		if (tmp[0])
			tmp[1] = tmp[0]->next;
	}
	return (1);
}
