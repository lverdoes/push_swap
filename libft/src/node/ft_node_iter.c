/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_iter.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 10:04:31 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 11:35:50 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

void	ft_node_iter(t_node *node, void (*f)(void *))
{
	t_node	*tmp;

	if (!f)
		return ;
	tmp = node;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
