/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_size.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:18:35 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 11:37:25 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

size_t	ft_node_size(t_node *node)
{
	size_t	ret;
	t_node	*tmp;

	ret = 0;
	tmp = node;
	while (tmp)
	{
		tmp = tmp->next;
		ret++;
	}
	return (ret);
}
