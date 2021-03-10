/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_high_low.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:32:20 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/10 13:52:04 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <limits.h>

size_t	find_highest_rank(t_node *stack)
{
	t_node	*tmp;
	t_elem	*e;
	size_t	high;

	high = 0;
	tmp = stack;
	while (tmp)
	{
		e = tmp->content;
		if (e->rank > high)
			high = e->rank;
		tmp = tmp->next;
	}
	return (high);
}

size_t	find_lowest_rank(t_node *stack)
{
	t_node	*tmp;
	t_elem	*e;
	size_t	low;

	low = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		e = tmp->content;
		if (e->rank < low)
			low = e->rank;
		tmp = tmp->next;
	}
	return (low);
}
