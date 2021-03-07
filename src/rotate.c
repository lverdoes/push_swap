/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/03 17:56:48 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_vars *v)
{
	t_node	*tmp;

	if (!v->a)
		return ;
	tmp = v->a;
	ft_node_unlink(&v->a, v->a);
	ft_node_add_back(&v->a, tmp);
}

void	rb(t_vars *v)
{
	t_node	*tmp;

	if (!v->b)
		return ;
	tmp = v->b;
	ft_node_unlink(&v->b, v->b);
	ft_node_add_back(&v->b, tmp);
}

void	rr(t_vars *v)
{
	ra(v);
	rb(v);
}
