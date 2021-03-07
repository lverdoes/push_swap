/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 16:57:35 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:31:05 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **alst, void (*del)(void *))
{
	t_list	*tmp;

	if (!alst)
		return ;
	while (*alst)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(tmp, del);
	}
	*alst = NULL;
}
