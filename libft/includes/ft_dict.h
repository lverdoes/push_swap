/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dict.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:14:00 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/09 15:30:38 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H

# include <stddef.h>

# define PAGES 256

typedef struct s_dict
{
	void			*content;
	struct s_dict	*dict[PAGES];
}	t_dict;

void	ft_dict_clear(t_dict *head, void (*del)(void *));
void	ft_dict_del_one(t_dict *dict, void (*del)(void *));
t_dict	*ft_dict_find(t_dict *head, char *key);
int		ft_dict_new(t_dict *head, char *key, void *content);
size_t	ft_dict_size_content(t_dict *head);
size_t	ft_dict_size_page(t_dict *head);

#endif
