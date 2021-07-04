/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_find.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:19:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:40:40 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
**	Returns the first node from START that matches DATA_REF,
**	according to CMP.
**	CMP can be a function that returns strcmp(), for example:
**
**	int		cmp_ref(void *data_ref, t_var *var)
**	{
**		return (ft_strcmp(data_ref, var->str));
**	}
*/

t_list	*ft_list_find(t_list *start, void *data_ref, int (*cmp)())
{
	t_list	*tmp;

	tmp = start;
	while (tmp)
	{
		if (!cmp(data_ref, tmp->content))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
