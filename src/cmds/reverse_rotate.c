/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/01 14:13:11 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_vars *v)
{
	t_node	*tmp;
	t_node	*tmp_last;

	v->data.rra++;
	if (!v->a || !v->a->next)
		return ;
	tmp = v->last_a;
	tmp_last = v->last_a->prev;
	ft_node_unlink(&v->a, tmp);
	ft_node_add_front(&v->a, tmp);
	v->last_a = tmp_last;
}

void	rrb(t_vars *v)
{
	t_node	*tmp;
	t_node	*tmp_last;

	v->data.rrb++;
	if (!v->b || !v->b->next)
		return ;
	tmp = v->last_b;
	tmp_last = v->last_b->prev;
	ft_node_unlink(&v->b, tmp);
	ft_node_add_front(&v->b, tmp);
	v->last_b = tmp_last;
}

void	rrr(t_vars *v)
{
	rra(v);
	rrb(v);
	v->data.rrr++;
	v->data.rra--;
	v->data.rrb--;
}
