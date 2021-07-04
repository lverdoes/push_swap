/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_size_nodes.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 21:27:31 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/25 20:11:01 by lverdoes      ########   odam.nl         */
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
	*size += 1;
}

size_t	ft_trie_size_nodes(t_trie *head)
{
	size_t	size;

	if (!head)
		return (0);
	size = 0;
	go_node(head, &size);
	return (size);
}
