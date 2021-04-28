/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_remove_one.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 01:59:14 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 11:37:21 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

/*
**	Remove a node from the list.
**	The node is unlinked, freed and set to NULL.
**
**	Ex.:
**	ft_node_remove_one(&head, ft_node_find(head, "Rigate",  cmp_ref), del_var);
*/

void	ft_node_remove_one(t_node **head, t_node *node, void (*del)(void *))
{
	ft_node_unlink(head, node);
	ft_node_del_one(node, *del);
}
