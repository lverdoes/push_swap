/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_add_back.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:27:58 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 11:34:50 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

void	ft_node_add_back(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (!*head)
		ft_node_add_front(head, new);
	else
	{
		tmp = ft_node_last(*head);
		tmp->next = new;
		new->prev = tmp;
	}
}
