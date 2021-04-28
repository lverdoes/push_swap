/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dict_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:22:08 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/09 15:33:01 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"
#include "libft.h"

int	ft_dict_new(t_dict *head, char *key, void *content)
{
	int		i;
	t_dict	*tmp;

	tmp = head;
	i = 0;
	while (key[i])
	{
		if (tmp->dict[(unsigned char)key[i]])
		{
			tmp = tmp->dict[(unsigned char)key[i]];
			i++;
		}
		else
		{
			tmp->dict[(unsigned char)key[i]] = ft_calloc(1, sizeof(t_dict));
			if (!tmp->dict[(unsigned char)key[i]])
				return (-1);
		}
	}
	if (tmp->content)
		return (0);
	tmp->content = content;
	return (1);
}
