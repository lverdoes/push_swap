/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dict_find.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:13:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/09 15:33:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

t_dict	*ft_dict_find(t_dict *head, char *key)
{
	int		i;
	t_dict	*tmp;

	if (!key)
		return (0);
	i = 0;
	tmp = head;
	while (key[i])
	{
		if (tmp && tmp->dict[(unsigned char)key[i]])
		{
			tmp = tmp->dict[(unsigned char)key[i]];
			i++;
		}
		else
			return (0);
	}
	return (tmp);
}
