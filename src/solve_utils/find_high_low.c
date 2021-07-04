/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_high_low.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:32:20 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 10:43:44 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	find_highest_rank(t_stack *s)
{
	t_list	*tmp;
	t_elem	*e;
	size_t	i;

	s->high = 0;
	i = 0;
	tmp = s->head;
	while (tmp)
	{
		e = tmp->content;
		if (e->rank > s->high)
		{
			s->high = e->rank;
			s->pos_high = i;
		}
		i++;
		tmp = tmp->next;
	}
}

void	find_lowest_rank(t_stack *s)
{
	t_list	*tmp;
	t_elem	*e;
	size_t	i;

	s->low = ULLONG_MAX;
	i = 0;
	tmp = s->head;
	while (tmp)
	{
		e = tmp->content;
		if (e->rank < s->low)
		{
			s->low = e->rank;
			s->pos_low = i;
		}
		i++;
		tmp = tmp->next;
	}
}
