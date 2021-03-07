/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_ordered.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 08:40:11 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/05 17:59:57 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	correct_rotation_order(t_vars *v, int exception)
{
	t_node	*tmp;
	t_node	*next;
	t_elem	*e;
	t_elem	*e_next;

	tmp = v->a;
	next = tmp->next;
	while (tmp)
	{
		if (!tmp->next)
			next = v->a;
		e = tmp->content;
		e_next = next->content;
		if (e->rank > e_next->rank)
		{
			if (exception == 1)
				return (0);
			exception = 1;
		}
		tmp = tmp->next;
		if (tmp)
			next = tmp->next;
	}
	return (1);
}

int	is_ordered_a(t_vars *v)
{
	t_node	*tmp;
	t_node	*next;
	t_elem	*e;
	t_elem	*e_next;

	tmp = v->a;
	next = tmp->next;
	while (next)
	{
		e = tmp->content;
		e_next = next->content;
		if (e->rank > e_next->rank)
			return (0);
		tmp = tmp->next;
		next = tmp->next;
	}
	return (1);
}

int	is_ordered_b(t_vars *v)
{
	t_node	*tmp;
	t_node	*next;
	t_elem	*e;
	t_elem	*e_next;

	tmp = v->a;
	next = tmp->next;
	while (next)
	{
		e = tmp->content;
		e_next = next->content;
		if (e->rank < e_next->rank)
			return (0);
		tmp = tmp->next;
		next = tmp->next;
	}
	return (1);
}
