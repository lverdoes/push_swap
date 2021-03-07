/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_insert_after.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:44 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:11:58 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_node_insert_after(t_node *node, t_node *after_this)
{
	node->prev = after_this;
	node->next = after_this->next;
	after_this->next = node;
	if (node->next)
		node->next->prev = node;
}
