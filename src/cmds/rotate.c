/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/01 14:13:04 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_vars *v)
{
	t_node	*tmp;

	v->data.ra++;
	if (!v->a || !v->a->next)
		return ;
	tmp = v->a;
	ft_node_unlink(&v->a, v->a);
	ft_node_insert_after(&v->a, tmp, v->last_a);
	v->last_a = tmp;
}

void	rb(t_vars *v)
{
	t_node	*tmp;

	v->data.rb++;
	if (!v->b || !v->b->next)
		return ;
	tmp = v->b;
	ft_node_unlink(&v->b, v->b);
	ft_node_insert_after(&v->b, tmp, v->last_b);
	v->last_b = tmp;
}

void	rr(t_vars *v)
{
	ra(v);
	rb(v);
	v->data.rr++;
	v->data.ra--;
	v->data.rb--;
}
