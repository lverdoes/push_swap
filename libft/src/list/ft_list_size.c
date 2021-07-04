/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_size.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:18:35 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:43:31 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_list_size(t_list *list)
{
	size_t	ret;
	t_list	*tmp;

	ret = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		ret++;
	}
	return (ret);
}
