/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_remove_one.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 01:59:14 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/05 11:05:25 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
