/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_insert_after.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:44 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/11 17:31:17 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_node_insert_after(t_node **head, t_node *node, t_node *after_this)
{
	if (!after_this)
	{
		ft_node_add_back(head, node);
		return ;
	}
	node->prev = after_this;
	node->next = after_this->next;
	after_this->next = node;
	if (node->next)
		node->next->prev = node;
}
