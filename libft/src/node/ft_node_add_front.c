/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_add_front.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:32:40 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/05 08:25:57 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_node_add_front(t_node **head, t_node *new)
{
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;
}
