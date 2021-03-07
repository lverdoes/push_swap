/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstfind.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 17:38:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/05 08:25:57 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *list, void *data_ref, int (*cmp)())
{
	while (list)
	{
		if (!cmp(data_ref, list->content))
			return (list);
		list = list->next;
	}
	return (NULL);
}
