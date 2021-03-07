/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/05 15:59:41 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_vars *v)
{
	t_node	*tmp;

	tmp = ft_node_last(v->a);
	ft_node_unlink(&v->a, tmp);
	ft_node_add_front(&v->a, tmp);
}

void	rrb(t_vars *v)
{
	t_node	*tmp;

	tmp = ft_node_last(v->b);
	ft_node_unlink(&v->b, tmp);
	ft_node_add_front(&v->b, tmp);
}

void	rrr(t_vars *v)
{
	rra(v);
	rrb(v);
}
