/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_insert_after.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:44 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:40:58 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_insert_after(t_list **head, t_list *list, t_list *after_this)
{
	if (!after_this)
	{
		ft_list_add_back(head, list);
		return ;
	}
	list->prev = after_this;
	list->next = after_this->next;
	after_this->next = list;
	if (list->next)
		list->next->prev = list;
}
