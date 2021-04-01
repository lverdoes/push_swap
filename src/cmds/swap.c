/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:39:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/01 14:12:31 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sa(t_vars *v)
{
	v->data.sa++;
	if (!v->a || !v->a->next)
		return (0);
	swap(v->a->content, v->a->next->content);
	if (ft_node_size(v->a) == 2)
		v->last_a = ft_node_last(v->a);
	return (1);
}

int	sb(t_vars *v)
{
	v->data.sb++;
	if (!v->b || !v->b->next)
		return (0);
	swap(v->b->content, v->b->next->content);
	if (ft_node_size(v->b) == 2)
		v->last_b = ft_node_last(v->b);
	return (1);
}

int	ss(t_vars *v)
{
	sa(v);
	sb(v);
	v->data.ss++;
	v->data.sa--;
	v->data.sb--;
	return (1);
}
