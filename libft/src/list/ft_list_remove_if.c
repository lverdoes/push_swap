/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_remove_if.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 11:14:55 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:43:15 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
**	Remove all nodes from the linked list that match DATA_REF,
**	according to CMP_REF.
**	
**	Ex.:	ft_list_remove_if(&head, "Rigate", cmp_ref, del_var);
**
**	Ex. of CMP_REF:
**	int		cmp_ref(void *data_ref, t_var *var)
**	{
**		return (ft_strcmp(data_ref, var->str));
**	}
**
**	For info on del(), see ft_list_del_all.c
*/

void	ft_list_remove_if(t_list **head, void *data_ref, \
		int (*cmp)(), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	list = *head;
	while (list)
	{
		if (!cmp(data_ref, list->content))
		{
			tmp = list;
			list = list->next;
			ft_list_remove_one(head, tmp, del);
		}
		else
			list = list->next;
	}
}
