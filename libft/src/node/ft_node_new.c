/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:58 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 11:36:38 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"
#include <stdlib.h>

t_node	*ft_node_new(void *content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
