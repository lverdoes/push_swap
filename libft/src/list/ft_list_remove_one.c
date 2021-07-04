/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_remove_one.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 01:59:14 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/02 21:28:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
**	Remove a node from the list.
**	The node is unlinked and freed.
**
**	Ex.:
**	ft_list_remove_one(&head, ft_list_find(head, "Rigate",  cmp_ref), del_var);
*/

void	ft_list_remove_one(t_list **head, t_list *list, void (*del)(void *))
{
	ft_list_unlink(head, list);
	ft_list_del_one(list, *del);
}
