/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_find.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:13:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/25 20:11:48 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trie.h"

t_trie	*ft_trie_find(t_trie *head, char *key)
{
	int		i;
	t_trie	*tmp;

	if (!key)
		return (0);
	i = 0;
	tmp = head;
	while (key[i])
	{
		if (tmp && tmp->trie[(unsigned char)key[i]])
		{
			tmp = tmp->trie[(unsigned char)key[i]];
			i++;
		}
		else
			return (0);
	}
	return (tmp);
}
