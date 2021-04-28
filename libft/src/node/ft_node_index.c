/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_index.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/30 19:51:05 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 11:35:29 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

/*
**	See ft_node_find.c
*/

size_t	ft_node_index(t_node *start, void *data_ref, int (*cmp)())
{
	size_t	ret;
	t_node	*tmp;

	ret = 0;
	tmp = start;
	while (tmp)
	{
		if (!cmp(data_ref, tmp->content))
			break ;
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}
