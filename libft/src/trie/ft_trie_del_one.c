/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_del_one.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 09:34:41 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/06/30 22:50:31 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trie.h"
#include "ft_ext.h"

void	ft_trie_del_one(t_trie *trie, void (*del)(void *))
{
	if (!trie)
		return ;
	del(trie->content);
	ft_free(trie);
	trie = NULL;
}
