/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:39:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/10 10:27:37 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_vars *v)
{
	if (!v->a || !v->a->next)
		return ;
	swap(v->a->content, v->a->next->content);
	if (ft_node_size(v->a) == 2)
		v->last_a = ft_node_last(v->a);
}

void	sb(t_vars *v)
{
	if (!v->b || !v->b->next)
		return ;
	swap(v->b->content, v->b->next->content);
	if (ft_node_size(v->b) == 2)
		v->last_b = ft_node_last(v->b);
}

void	ss(t_vars *v)
{
	sa(v);
	sb(v);
}
