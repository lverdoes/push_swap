/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_add_back.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:27:58 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:37:46 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_add_back(t_list **head, t_list *new)
{
	t_list	*tmp;

	if (!*head)
		ft_list_add_front(head, new);
	else
	{
		tmp = ft_list_last(*head);
		tmp->next = new;
		new->prev = tmp;
	}
}
