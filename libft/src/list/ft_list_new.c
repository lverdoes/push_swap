/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:58 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:42:11 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_new(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->prev = NULL;
	new_list->next = NULL;
	return (new_list);
}
