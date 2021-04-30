/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:39:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/29 23:23:21 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sa(t_vars *v)
{
	v->data.sa++;
	if (!v->a.head || !v->a.head->next)
		return (0);
	swap(v->a.head->content, v->a.head->next->content);
	if (ft_node_size(v->a.head) == 2)
		v->a.tail = ft_node_last(v->a.head);
	return (1);
}

int	sb(t_vars *v)
{
	v->data.sb++;
	if (!v->b.head || !v->b.head->next)
		return (0);
	swap(v->b.head->content, v->b.head->next->content);
	if (ft_node_size(v->b.head) == 2)
		v->b.tail = ft_node_last(v->b.head);
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
