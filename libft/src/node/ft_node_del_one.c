/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_del_one.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:33 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:11:22 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Delete one node from memory and set it to NULL.
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
