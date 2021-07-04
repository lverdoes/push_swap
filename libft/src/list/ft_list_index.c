/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_index.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/30 19:51:05 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:40:50 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
**	See ft_list_find.c
*/

size_t	ft_list_index(t_list *start, void *data_ref, int (*cmp)())
{
	size_t	ret;
	t_list	*tmp;

	ret = 0;
	tmp = start;
	while (tmp)
	{
		if (!cmp(data_ref, tmp->content))
			break ;
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}
