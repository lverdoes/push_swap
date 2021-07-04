/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_iter.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 10:04:31 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:41:46 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_iter(t_list *list, void (*f)(void *))
{
	t_list	*tmp;

	if (!f)
		return ;
	tmp = list;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
