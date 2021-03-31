/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_remove_if.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 11:14:55 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/06 11:14:11 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Remove all nodes from the linked list that match DATA_REF,
**	according to CMP_REF.
**	
**	Ex.:	ft_node_remove_if(&head, "Rigate", cmp_ref, del_var);
**
**	Ex. of CMP_REF:
**	int		cmp_ref(void *data_ref, t_var *var)
**	{
**		return (ft_strcmp(data_ref, var->str));
**	}
**
**	For info on del(), see ft_node_del_all.c
*/

void	ft_node_remove_if(t_node **head, void *data_ref, \
		int (*cmp)(), void (*del)(void *))
{
	t_node	*node;
	t_node	*tmp;

	node = *head;
	while (node)
	{
		if (!cmp(data_ref, node->content))
		{
			tmp = node;
			node = node->next;
			ft_node_remove_one(head, tmp, del);
		}
		else
			node = node->next;
	}
}
