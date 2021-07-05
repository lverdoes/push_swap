/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 21:38:51 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/06 00:22:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_in_range(t_vars *v)
{
	size_t const	range = 2;
	size_t			rank;

	rank = ((t_elem *)v->a.head->content)->rank;
	if (rank < v->a.low + range)
		cmd(PB, 1);
}

int	solve_medium(t_vars *v)
{
	push_in_range(v);
	while (v->a.size > 3)
	{
		shortest_path(&v->a, v->a.pos_low, 1);
		push_in_range(v);
	}
	solve_small(v);
	push_back(v);
	return (0);
}
