/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_add_front.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:32:40 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:38:00 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_add_front(t_list **head, t_list *new)
{
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;
}
