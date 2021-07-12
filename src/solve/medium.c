/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 21:38:51 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/12 10:29:29 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_in_range(t_stack *a)
{
	size_t const	range = 2;
	size_t			rank;

	rank = ((t_elem *)a->head->content)->rank;
	if (rank < a->low + range)
		cmd(PB, 1);
}

int	solve_medium(t_stack *a, t_stack *b)
{
	push_in_range(a);
	while (a->size > 3)
	{
		shortest_path(a, a->pos_low, 1);
		push_in_range(a);
	}
	solve_small(a, b);
	push_back(a, b);
	return (0);
}
