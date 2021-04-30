/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 15:09:24 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rra(t_vars *v)
{
	t_node	*tmp;
	t_node	*tmp_last;

	v->data.rra++;
	if (!v->a.head || !v->a.head->next)
		return (0);
	tmp = v->a.tail;
	tmp_last = v->a.tail->prev;
	ft_node_unlink(&v->a.head, tmp);
	ft_node_add_front(&v->a.head, tmp);
	v->a.tail = tmp_last;
	return (1);
}

int	rrb(t_vars *v)
{
	t_node	*tmp;
	t_node	*tmp_last;

	v->data.rrb++;
	if (!v->b.head || !v->b.head->next)
		return (0);
	tmp = v->b.tail;
	tmp_last = v->b.tail->prev;
	ft_node_unlink(&v->b.head, tmp);
	ft_node_add_front(&v->b.head, tmp);
	v->b.tail = tmp_last;
	return (1);
}

int	rrr(t_vars *v)
{
	rra(v);
	rrb(v);
	v->data.rrr++;
	v->data.rra--;
	v->data.rrb--;
	return (1);
}
