/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_last.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:27:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/23 08:38:42 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
