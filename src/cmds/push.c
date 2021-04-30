/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:27 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 08:22:27 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	update_high_low(t_vars *v)
{
	t_elem	*e;

	if (v->a.head)
	{
		e = v->a.head->content;
		if (e->rank < v->a.low)
			v->a.low = e->rank;
		if (e->rank == v->b.high)
			v->b.high = find_highest_rank(v->b.head);
	}
	if (v->b.head)
	{
		e = v->b.head->content;
		if (e->rank > v->b.high)
			v->b.high = e->rank;
		if (e->rank == v->a.low)
			v->a.low = find_lowest_rank(v->a.head);
	}
}

int	pa(t_vars *v)
{
	t_node	*tmp;

	v->data.pa++;
	if (!v->b.head)
		return (0);
	tmp = v->b.head;
	ft_node_unlink(&v->b.head, v->b.head);
	ft_node_add_front(&v->a.head, tmp);
	v->b.size -= 1;
	v->a.size += 1;
	if (!v->b.head)
		v->b.tail = NULL;
	if (!v->a.head->next)
		v->a.tail = v->a.head;
	update_high_low(v);
	return (1);
}

int	pb(t_vars *v)
{
	t_node	*tmp;

	v->data.pb++;
	if (!v->a.head)
		return (0);
	tmp = v->a.head;
	ft_node_unlink(&v->a.head, v->a.head);
	ft_node_add_front(&v->b.head, tmp);
	v->a.size -= 1;
	v->b.size += 1;
	if (!v->a.head)
		v->a.tail = NULL;
	if (!v->b.head->next)
		v->b.tail = v->b.head;
	update_high_low(v);
	return (1);
}
