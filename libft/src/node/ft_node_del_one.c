/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_del_one.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:33 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 11:35:12 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"
#include <stdlib.h>

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
	free(node);
}
