/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:22:08 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/25 20:11:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trie.h"
#include "libft.h"

int	ft_trie_new(t_trie *head, char *key, void *content)
{
	int		i;
	t_trie	*tmp;

	tmp = head;
	i = 0;
	while (key[i])
	{
		if (tmp->trie[(unsigned char)key[i]])
		{
			tmp = tmp->trie[(unsigned char)key[i]];
			i++;
		}
		else
		{
			tmp->trie[(unsigned char)key[i]] = ft_calloc(1, sizeof(t_trie));
			if (!tmp->trie[(unsigned char)key[i]])
				return (-1);
		}
	}
	if (tmp->content)
		return (0);
	tmp->content = content;
	return (1);
}
