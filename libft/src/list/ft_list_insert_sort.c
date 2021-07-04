/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_insert_sort.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 08:31:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:41:21 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_insert_sort(t_list **head, t_list *list, int (*cmp)())
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (cmp(list->content, tmp->content) <= 0)
		{
			ft_list_insert_before(head, list, tmp);
			return ;
		}
		tmp = tmp->next;
	}
	ft_list_add_back(head, list);
}
