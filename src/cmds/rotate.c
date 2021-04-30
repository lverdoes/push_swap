/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 15:09:32 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ra(t_vars *v)
{
	t_node	*tmp;

	v->data.ra++;
	if (!v->a.head || !v->a.head->next)
		return (0);
	tmp = v->a.head;
	ft_node_unlink(&v->a.head, v->a.head);
	ft_node_insert_after(&v->a.head, tmp, v->a.tail);
	v->a.tail = tmp;
	return (1);
}

int	rb(t_vars *v)
{
	t_node	*tmp;

	v->data.rb++;
	if (!v->b.head || !v->b.head->next)
		return (0);
	tmp = v->b.head;
	ft_node_unlink(&v->b.head, v->b.head);
	ft_node_insert_after(&v->b.head, tmp, v->b.tail);
	v->b.tail = tmp;
	return (1);
}

int	rr(t_vars *v)
{
	ra(v);
	rb(v);
	v->data.rr++;
	v->data.ra--;
	v->data.rb--;
	return (1);
}
