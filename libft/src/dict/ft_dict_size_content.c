/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dict_size_content.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 09:45:11 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/09 15:30:17 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

static void	go_page(t_dict *dict, size_t *const size)
{
	int	i;

	i = 0;
	while (i < PAGES)
	{
		if (dict->dict[i])
			go_page(dict->dict[i], size);
		i++;
	}
	if (dict->content)
		*size += 1;
}

size_t	ft_dict_size_content(t_dict *head)
{
	size_t	size;

	if (!head)
		return (0);
	size = 0;
	go_page(head, &size);
	return (size);
}
