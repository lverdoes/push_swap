/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 21:31:10 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:49:23 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_node_sort(t_node *head, int (*cmp)())
{
	t_node	*i;
	t_node	*j;

	i = head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (cmp(i->content, j->content) > 0)
				ft_swap(&i->content, &j->content, sizeof(void *));
			j = j->next;
		}
		i = i->next;
	}
}
