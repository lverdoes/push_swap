/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:58 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:12:34 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_node_new(void *content)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
