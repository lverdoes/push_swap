/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:14:00 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/25 20:09:51 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRIE_H
# define FT_TRIE_H

# include <stddef.h>

# define NODES 256

typedef struct s_trie
{
	void			*content;
	struct s_trie	*trie[NODES];
}	t_trie;

void	ft_trie_clear(t_trie *head, void (*del)(void *));
void	ft_trie_del_one(t_trie *trie, void (*del)(void *));
t_trie	*ft_trie_find(t_trie *head, char *key);
int		ft_trie_new(t_trie *head, char *key, void *content);
size_t	ft_trie_size_content(t_trie *head);
size_t	ft_trie_size_page(t_trie *head);

#endif
