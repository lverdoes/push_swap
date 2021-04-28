/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_last.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:27:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 11:35:59 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

t_node	*ft_node_last(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return (NULL);
	tmp = node;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
