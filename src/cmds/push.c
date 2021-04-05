/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:27 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/05 15:26:04 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	update_high_low(t_vars *v)
{
	t_elem	*e;

	if (v->a)
	{
		e = v->a->content;
		if (e->rank < v->low_a)
			v->low_a = e->rank;
		if (e->rank == v->high_b)
			v->high_b = find_highest_rank(v->b);
	}
	if (v->b)
	{
		e = v->b->content;
		if (e->rank > v->high_b)
			v->high_b = e->rank;
		if (e->rank == v->low_a)
			v->low_a = find_lowest_rank(v->a);
	}
}

int	pa(t_vars *v)
{
	t_node	*tmp;

	v->data.pa++;
	if (!v->b)
		return (0);
	tmp = v->b;
	ft_node_unlink(&v->b, v->b);
	ft_node_add_front(&v->a, tmp);
	v->size_b -= 1;
	v->size_a += 1;
	if (!v->b)
		v->last_b = NULL;
	if (!v->a->next)
		v->last_a = v->a;
	update_high_low(v);
	return (1);
}

int	pb(t_vars *v)
{
	t_node	*tmp;

	v->data.pb++;
	if (!v->a)
		return (0);
	tmp = v->a;
	ft_node_unlink(&v->a, v->a);
	ft_node_add_front(&v->b, tmp);
	v->size_a -= 1;
	v->size_b += 1;
	if (!v->a)
		v->last_a = NULL;
	if (!v->b->next)
		v->last_b = v->b;
	update_high_low(v);
	return (1);
}
