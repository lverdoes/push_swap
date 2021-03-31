/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_index.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/30 19:51:05 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/30 19:56:39 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_node_index(t_node *start, t_node *node)
{
	size_t	ret;
	t_node	*tmp;

	ret = 0;
	tmp = start;
	while (tmp)
	{
		if (node == tmp)
			break ;
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}
