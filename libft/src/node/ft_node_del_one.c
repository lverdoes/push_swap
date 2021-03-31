/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_del_one.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:33 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/11 17:21:01 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Delete one node from memory.
**	This does not unlink the node cleanly from the list.
**	See ft_node_del_all.c for more info.
*/

void	ft_node_del_one(t_node *node, void (*del)(void *))
{
	if (!node)
		return ;
	del(node->content);
	ft_free(node);
}
