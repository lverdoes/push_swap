/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_find.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:19:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:11:55 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

t_node	*ft_node_find(t_node *start, void *data_ref, int (*cmp)())
{
	t_node	*tmp;

	tmp = start;
	while (tmp)
	{
		if (!cmp(data_ref, tmp->content))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
