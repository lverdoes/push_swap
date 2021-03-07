/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_size.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:18:35 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/23 08:39:42 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
