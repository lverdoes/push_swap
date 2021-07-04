/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_insert_before.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:52 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:41:12 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_insert_before(t_list **head, t_list *list, t_list *before_this)
{
	if (!before_this)
	{
		ft_list_add_back(head, list);
		return ;
	}	
	if (before_this == *head)
	{
		ft_list_add_front(head, list);
		return ;
	}
	list->prev = before_this->prev;
	list->next = before_this;
	before_this->prev = list;
	list->prev->next = list;
}
