/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_size_content.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 09:45:11 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/25 20:10:55 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trie.h"

static void	go_node(t_trie *trie, size_t *const size)
{
	int	i;

	i = 0;
	while (i < NODES)
	{
		if (trie->trie[i])
			go_node(trie->trie[i], size);
		i++;
	}
	if (trie->content)
		*size += 1;
}

size_t	ft_trie_size_content(t_trie *head)
{
	size_t	size;

	if (!head)
		return (0);
	size = 0;
	go_node(head, &size);
	return (size);
}
