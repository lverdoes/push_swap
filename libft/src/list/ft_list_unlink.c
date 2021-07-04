/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_unlink.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:36:08 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:43:42 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	is_middle(t_list *list)
{
	list->prev->next = list->next;
	list->next->prev = list->prev;
}

static void	is_last(t_list *list)
{
	list->prev->next = NULL;
}

static void	is_head(t_list **head, t_list *list)
{
	*head = list->next;
	if (*head)
		(*head)->prev = NULL;
}

t_list	*ft_list_unlink(t_list **head, t_list *list)
{
	if (!list->prev)
		is_head(head, list);
	else if (!list->next)
		is_last(list);
	else
		is_middle(list);
	list->prev = NULL;
	list->next = NULL;
	return (list);
}
